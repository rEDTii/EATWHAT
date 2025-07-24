/* 使用DMA优化的SPI SD卡驱动，提供给diskio的接口，使用FreeRTOS */
#include "sd_driver.h"
#include "dma.h"


uint8_t DFF=0xFF;
uint8_t SD_TYPE=0x00;

MSD_CARDINFO SD0_CardInfo;



int SD_sendcmd(uint8_t cmd,uint32_t arg,uint8_t crc){
		uint8_t r1;
		uint8_t retry;

		do{
				retry=SD_ReadWriteByte(DFF);
		}while(retry!=0xFF);

		SD_ReadWriteByte(cmd | 0x40);
		SD_ReadWriteByte(arg >> 24);
		SD_ReadWriteByte(arg >> 16);
		SD_ReadWriteByte(arg >> 8);
		SD_ReadWriteByte(arg);
		SD_ReadWriteByte(crc);
		if(cmd==CMD12)	SD_ReadWriteByte(DFF);
		do
		{
				r1=SD_ReadWriteByte(0xFF);
		}while(r1&0X80);
		
		return r1;
}

uint8_t SD_init(void)
{
		uint8_t r1;	
		uint8_t buff[6] = {0};
		uint16_t retry; 
		uint8_t i;
		
		SD_SPI_Init();
		
		SD_SetLowSpeed();
		SD_CS_L();
		
		for(retry=0;retry<10;retry++){
				SD_ReadWriteByte(DFF);
		}
		
		//SD卡进入IDLE状态
		do{
				r1 = SD_sendcmd(CMD0 ,0, 0x95);	
		}while(r1!=0x01);
		
		//查看SD卡的类型
		SD_TYPE=0;
		r1 = SD_sendcmd(CMD8, 0x1AA, 0x87);
		if(r1==0x01){
				for(i=0;i<4;i++)buff[i]=SD_ReadWriteByte(DFF);	//Get trailing return value of R7 resp
				if(buff[2]==0X01&&buff[3]==0XAA)//卡是否支持2.7~3.6V
				{
						retry=0XFFFE;
						do
						{
								SD_sendcmd(CMD55,0,0X01);	//发送CMD55
								r1=SD_sendcmd(CMD41,0x40000000,0X01);//发送CMD41
						}while(r1&&retry--);
						if(retry&&SD_sendcmd(CMD58,0,0X01)==0)//鉴别SD2.0卡版本开始
						{
								for(i=0;i<4;i++)buff[i]=SD_ReadWriteByte(0XFF);//得到OCR值
								if(buff[0]&0x40){
										SD_TYPE=V2HC;
								}else {
										SD_TYPE=V2;
								}						
						}
				}else{
						SD_sendcmd(CMD55,0,0X01);			//发送CMD55
						r1=SD_sendcmd(CMD41,0,0X01);	//发送CMD41
						if(r1<=1)
						{		
								SD_TYPE=V1;
								retry=0XFFFE;
								do //等待退出IDLE模式
								{
										SD_sendcmd(CMD55,0,0X01);	//发送CMD55
										r1=SD_sendcmd(CMD41,0,0X01);//发送CMD41
								}while(r1&&retry--);
						}else//MMC卡不支持CMD55+CMD41识别
						{
								SD_TYPE=MMC;//MMC V3
								retry=0XFFFE;
								do //等待退出IDLE模式
								{											    
										r1=SD_sendcmd(CMD1,0,0X01);//发送CMD1
								}while(r1&&retry--);  
						}
						if(retry==0||SD_sendcmd(CMD16,512,0X01)!=0)SD_TYPE=ERR;//错误的卡
				}
		}
		
		SD0_CardInfo.CardType = SD_TYPE;
		MSD0_GetCardInfo(&SD0_CardInfo);
		
		SD_CS_H();
		FL_DelayMs(10);
		SD_SetHighSpeed();
		
		if(SD_TYPE)return 0;
		else return 1;
}



//读取指定长度数据（DMA版本）
uint8_t SD_ReceiveData(uint8_t *data, uint16_t len)
{
   uint8_t r1;
	
   do
   { 
      r1 = SD_ReadWriteByte(0xFF);	
		}while(r1 != 0xFE);	
	 
		// 连续读
		SD_RECV_DMA_Trasnsfer(data, len);
		
		SD_ReadWriteByte(0xFF);
		SD_ReadWriteByte(0xFF); 										  		
		return 0;
}


//向sd卡写入一个数据包的内容 512字节（DMA版本）
uint8_t SD_SendBlock(uint8_t*buf,uint8_t cmd)
{	
		uint16_t t;	
		uint8_t r1;	
		do{
				r1=SD_ReadWriteByte(0xFF);
		}while(r1!=0xFF);
		
		SD_ReadWriteByte(cmd);
		if(cmd!=0XFD)//不是结束指令
		{
				// 连续写
				SD_SEND_DMA_Trasnsfer(buf, 512);
				SD_ReadWriteByte(0xFF);//忽略crc
				SD_ReadWriteByte(0xFF);
				t=SD_ReadWriteByte(0xFF);//接收响应
				if((t&0x1F)!=0x05)return 2;//响应错误									  					    
		}						 									  					    
		return 0;//写入成功
}




////读取指定长度数据
//uint8_t SD_ReceiveData(uint8_t *data, uint16_t len)
//{
//   uint8_t r1;
//	
//   do
//   { 
//      r1 = SD_ReadWriteByte(0xFF);	
//		}while(r1 != 0xFE);	
//		while(len--)
//		{
//			 *data = SD_ReadWriteByte(0xFF);
//			 data++;
//		}
//		SD_ReadWriteByte(0xFF);
//		SD_ReadWriteByte(0xFF); 										  		
//		return 0;
//}

////向sd卡写入一个数据包的内容 512字节
//uint8_t SD_SendBlock(uint8_t*buf,uint8_t cmd)
//{	
//	uint16_t t;	
//	uint8_t r1;	
//	do{
//		r1=SD_ReadWriteByte(0xFF);
//	}while(r1!=0xFF);
//	
//	SD_ReadWriteByte(cmd);
//	if(cmd!=0XFD)//不是结束指令
//	{
//		for(t=0;t<512;t++)SD_ReadWriteByte(buf[t]);//提高速度,减少函数传参时间
//	    SD_ReadWriteByte(0xFF);//忽略crc
//	    SD_ReadWriteByte(0xFF);
//		t=SD_ReadWriteByte(0xFF);//接收响应
//		if((t&0x1F)!=0x05)return 2;//响应错误									  					    
//	}						 									  					    
//  return 0;//写入成功
//}




//写SD卡
//buf:数据缓存区
//sector:起始扇区
//cnt:扇区数
//返回值:0,ok;其他,失败.
uint8_t SD_WriteDisk(uint8_t*buf,uint32_t sector,uint8_t cnt)
{
		uint8_t r1;
		if(SD_TYPE!=V2HC)sector <<= 9;//转换为字节地址
	
		SD_CS_L();	// 片选
		if(cnt==1)
		{
				r1=SD_sendcmd(CMD24,sector,0X01);//读命令
				if(r1==0)//指令发送成功
				{
						r1=SD_SendBlock(buf,0xFE);//写512个字节	   
				}
		}else
		{
				if(SD_TYPE!=MMC)
				{
						SD_sendcmd(CMD55,0,0X01);	
						SD_sendcmd(CMD23,cnt,0X01);//发送指令	
				}
				r1=SD_sendcmd(CMD25,sector,0X01);//连续读命令
				if(r1==0)
				{
						do
						{
								r1=SD_SendBlock(buf,0xFC);//写512个字节	 
								buf+=512;  
						}while(--cnt && r1==0);
						r1=SD_SendBlock(0,0xFD);//写结束cmd 
				}
		}   
		SD_CS_H();//取消片选
		return r1;//
}	



//读SD卡
//buf:数据缓存区
//sector:扇区
//cnt:扇区数
//返回值:0,ok;其他,失败.
uint8_t SD_ReadDisk(uint8_t*buf,uint32_t sector,uint8_t cnt)
{
		uint8_t r1;
		if(SD_TYPE!=V2HC)sector <<= 9;//转换为字节地址
	
		SD_CS_L();	// 片选	
		if(cnt==1)
		{
				r1=SD_sendcmd(CMD17,sector,0X01);//读命令
				if(r1==0)//指令发送成功
				{
						r1=SD_ReceiveData(buf,512);//接收512个字节	   
				}
		}else
		{
				r1=SD_sendcmd(CMD18,sector,0X01);//连续读命令
				do
				{
						r1=SD_ReceiveData(buf,512);//接收512个字节	 
						buf+=512;  
				}while(--cnt && r1==0); 	
				SD_sendcmd(CMD12,0,0X01);	//发送停止命令
		}   
		SD_CS_H();//取消片选
		return r1;//
}


//SPI低速波特率设置，SD卡初始化时的速率不能大于400KHz
// 外设时钟更新为32MHz
void SD_SetLowSpeed(void) {
		FL_SPI_SetBaudRate(SPI3, FL_SPI_PCLK_DIV128);
//	FL_SPI_SetBaudRate(SPI3, FL_SPI_PCLK_DIV32);
}
	
//SPI高速波特率设置，二分频后16MHz
void SD_SetHighSpeed(void) {
		FL_SPI_SetBaudRate(SPI3, FL_SPI_PCLK_DIV2);
}

// SPI3初始化
void SD_SPI_Init(void)
{
    FL_SPI_InitTypeDef    SPI_InitStruct = {0};
    FL_GPIO_InitTypeDef    GPIO_InitStruct;
    /* 
				CS			PC1
				MOSI		PC11
				SCK			PC12
				MISO		PC13
		*/
    GPIO_InitStruct.pin           = FL_GPIO_PIN_1;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		
		GPIO_InitStruct.pin           = FL_GPIO_PIN_11 | FL_GPIO_PIN_12 | FL_GPIO_PIN_13;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON3;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		
    SPI_InitStruct.softControl    = FL_ENABLE;                       //软件控制SSN使能
    SPI_InitStruct.mode           = FL_SPI_WORK_MODE_MASTER;         //主机模式
    SPI_InitStruct.baudRate       = FL_SPI_PCLK_DIV4;                //波特率
    SPI_InitStruct.bitOrder       = FL_SPI_BIT_ORDER_MSB_FIRST;      //先发送MSB
    SPI_InitStruct.dataWidth_l    = FL_SPI_DATAL_LENGTH0;
    SPI_InitStruct.dataWidth_h    = FL_SPI_DATAH_LENGTH0;            //数据长度：8bit
    SPI_InitStruct.clockPhase     = FL_SPI_PHASE_EDGE1;              //时钟相位
    SPI_InitStruct.clockPolarity  = FL_SPI_POLARITY_NORMAL;            //时钟极性
    SPI_InitStruct.transferMode   = FL_SPI_TRANSFER_MODE_FULL_DUPLEX;//全双工

    FL_SPI_Init(SPI3, &SPI_InitStruct);
}


uint32_t SD_ReadWriteByte(uint32_t data)
{
    uint32_t timeout = 0;

    FL_SPI_WriteTXBuff(SPI3, data);

    do
    {
        timeout++;
    } while(!FL_SPI_IsActiveFlag_TXBuffEmpty(SPI3) && timeout < TIMEOUT_VAL);

    timeout = 0;
    do
    {
        timeout++;
    } while(!FL_SPI_IsActiveFlag_RXBuffFull(SPI3) && timeout < TIMEOUT_VAL);

    data = FL_SPI_ReadRXBuff(SPI3);

    return data;
}




int MSD0_GetCardInfo(PMSD_CARDINFO SD0_CardInfo)
{
		uint8_t r1;
		uint8_t CSD_Tab[16] = {0};
		uint8_t CID_Tab[16] = {0};

		
		SD_CS_L();	// 片选
		/* Send CMD9, Read CSD */
		r1 = SD_sendcmd(CMD9, 0, 0xFF);
		if(r1 != 0x00)
		{
				return r1;
		}

		if(SD_ReceiveData(CSD_Tab, 16))
		{
				return 1;
		}

		/* Send CMD10, Read CID */
		r1 = SD_sendcmd(CMD10, 0, 0xFF);
		if(r1 != 0x00)
		{
				return r1;
		}

		if(SD_ReceiveData(CID_Tab, 16))
		{
				return 2;
		}  
		SD_CS_H();

		/* Byte 0 */
		SD0_CardInfo->CSD.CSDStruct = (CSD_Tab[0] & 0xC0) >> 6;
		SD0_CardInfo->CSD.SysSpecVersion = (CSD_Tab[0] & 0x3C) >> 2;
		SD0_CardInfo->CSD.Reserved1 = CSD_Tab[0] & 0x03;
		/* Byte 1 */
		SD0_CardInfo->CSD.TAAC = CSD_Tab[1] ;
		/* Byte 2 */
		SD0_CardInfo->CSD.NSAC = CSD_Tab[2];
		/* Byte 3 */
		SD0_CardInfo->CSD.MaxBusClkFrec = CSD_Tab[3];
		/* Byte 4 */
		SD0_CardInfo->CSD.CardComdClasses = CSD_Tab[4] << 4;
		/* Byte 5 */
		SD0_CardInfo->CSD.CardComdClasses |= (CSD_Tab[5] & 0xF0) >> 4;
		SD0_CardInfo->CSD.RdBlockLen = CSD_Tab[5] & 0x0F;
		/* Byte 6 */
		SD0_CardInfo->CSD.PartBlockRead = (CSD_Tab[6] & 0x80) >> 7;
		SD0_CardInfo->CSD.WrBlockMisalign = (CSD_Tab[6] & 0x40) >> 6;
		SD0_CardInfo->CSD.RdBlockMisalign = (CSD_Tab[6] & 0x20) >> 5;
		SD0_CardInfo->CSD.DSRImpl = (CSD_Tab[6] & 0x10) >> 4;
		SD0_CardInfo->CSD.Reserved2 = 0; /* Reserved */


		if ((SD0_CardInfo->CardType == V2HC)) {
				/* Byte 7 */
				SD0_CardInfo->CSD.DeviceSize = (CSD_Tab[7] & 0x3F) << 16;

				/* Byte 8 */
				SD0_CardInfo->CSD.DeviceSize |= (CSD_Tab[8] << 8);

				/* Byte 9 */
				SD0_CardInfo->CSD.DeviceSize |= (CSD_Tab[9]);

				/* Byte 10 */  
				SD0_CardInfo->Capacity = (SD0_CardInfo->CSD.DeviceSize + 1) * 512 * 1024;
				SD0_CardInfo->BlockSize = 512;   
		}
		else {
				SD0_CardInfo->CSD.DeviceSize = (CSD_Tab[6] & 0x03) << 10;

				/* Byte 7 */
				SD0_CardInfo->CSD.DeviceSize |= (CSD_Tab[7]) << 2;

				/* Byte 8 */
				SD0_CardInfo->CSD.DeviceSize |= (CSD_Tab[8] & 0xC0) >> 6;

				SD0_CardInfo->CSD.MaxRdCurrentVDDMin = (CSD_Tab[8] & 0x38) >> 3;
				SD0_CardInfo->CSD.MaxRdCurrentVDDMax = (CSD_Tab[8] & 0x07);

				/* Byte 9 */
				SD0_CardInfo->CSD.MaxWrCurrentVDDMin = (CSD_Tab[9] & 0xE0) >> 5;
				SD0_CardInfo->CSD.MaxWrCurrentVDDMax = (CSD_Tab[9] & 0x1C) >> 2;
				SD0_CardInfo->CSD.DeviceSizeMul = (CSD_Tab[9] & 0x03) << 1;
				/* Byte 10 */
				SD0_CardInfo->CSD.DeviceSizeMul |= (CSD_Tab[10] & 0x80) >> 7;
				
				SD0_CardInfo->Capacity = (SD0_CardInfo->CSD.DeviceSize + 1) ;
				SD0_CardInfo->Capacity *= (1 << (SD0_CardInfo->CSD.DeviceSizeMul + 2));
				SD0_CardInfo->BlockSize = 1 << (SD0_CardInfo->CSD.RdBlockLen);
				SD0_CardInfo->Capacity *= SD0_CardInfo->BlockSize;
		}
		
		SD0_CardInfo->CSD.EraseGrSize = (CSD_Tab[10] & 0x40) >> 6;
		SD0_CardInfo->CSD.EraseGrMul = (CSD_Tab[10] & 0x3F) << 1;
		/* Byte 11 */
		SD0_CardInfo->CSD.EraseGrMul |= (CSD_Tab[11] & 0x80) >> 7;
		SD0_CardInfo->CSD.WrProtectGrSize = (CSD_Tab[11] & 0x7F);
		/* Byte 12 */
		SD0_CardInfo->CSD.WrProtectGrEnable = (CSD_Tab[12] & 0x80) >> 7;
		SD0_CardInfo->CSD.ManDeflECC = (CSD_Tab[12] & 0x60) >> 5;
		SD0_CardInfo->CSD.WrSpeedFact = (CSD_Tab[12] & 0x1C) >> 2;
		SD0_CardInfo->CSD.MaxWrBlockLen = (CSD_Tab[12] & 0x03) << 2;
		/* Byte 13 */
		SD0_CardInfo->CSD.MaxWrBlockLen |= (CSD_Tab[13] & 0xc0) >> 6;
		SD0_CardInfo->CSD.WriteBlockPaPartial = (CSD_Tab[13] & 0x20) >> 5;
		SD0_CardInfo->CSD.Reserved3 = 0;
		SD0_CardInfo->CSD.ContentProtectAppli = (CSD_Tab[13] & 0x01);
		/* Byte 14 */
		SD0_CardInfo->CSD.FileFormatGrouop = (CSD_Tab[14] & 0x80) >> 7;
		SD0_CardInfo->CSD.CopyFlag = (CSD_Tab[14] & 0x40) >> 6;
		SD0_CardInfo->CSD.PermWrProtect = (CSD_Tab[14] & 0x20) >> 5;
		SD0_CardInfo->CSD.TempWrProtect = (CSD_Tab[14] & 0x10) >> 4;
		SD0_CardInfo->CSD.FileFormat = (CSD_Tab[14] & 0x0C) >> 2;
		SD0_CardInfo->CSD.ECC = (CSD_Tab[14] & 0x03);
		/* Byte 15 */
		SD0_CardInfo->CSD.CSD_CRC = (CSD_Tab[15] & 0xFE) >> 1;
		SD0_CardInfo->CSD.Reserved4 = 1;


		/* Byte 0 */
		SD0_CardInfo->CID.ManufacturerID = CID_Tab[0];
		/* Byte 1 */
		SD0_CardInfo->CID.OEM_AppliID = CID_Tab[1] << 8;
		/* Byte 2 */
		SD0_CardInfo->CID.OEM_AppliID |= CID_Tab[2];
		/* Byte 3 */
		SD0_CardInfo->CID.ProdName1 = CID_Tab[3] << 24;
		/* Byte 4 */
		SD0_CardInfo->CID.ProdName1 |= CID_Tab[4] << 16;
		/* Byte 5 */
		SD0_CardInfo->CID.ProdName1 |= CID_Tab[5] << 8;
		/* Byte 6 */
		SD0_CardInfo->CID.ProdName1 |= CID_Tab[6];
		/* Byte 7 */
		SD0_CardInfo->CID.ProdName2 = CID_Tab[7];
		/* Byte 8 */
		SD0_CardInfo->CID.ProdRev = CID_Tab[8];
		/* Byte 9 */
		SD0_CardInfo->CID.ProdSN = CID_Tab[9] << 24;
		/* Byte 10 */
		SD0_CardInfo->CID.ProdSN |= CID_Tab[10] << 16;
		/* Byte 11 */
		SD0_CardInfo->CID.ProdSN |= CID_Tab[11] << 8;
		/* Byte 12 */
		SD0_CardInfo->CID.ProdSN |= CID_Tab[12];
		/* Byte 13 */
		SD0_CardInfo->CID.Reserved1 |= (CID_Tab[13] & 0xF0) >> 4;
		/* Byte 14 */
		SD0_CardInfo->CID.ManufactDate = (CID_Tab[13] & 0x0F) << 8;
		/* Byte 15 */
		SD0_CardInfo->CID.ManufactDate |= CID_Tab[14];
		/* Byte 16 */
		SD0_CardInfo->CID.CID_CRC = (CID_Tab[15] & 0xFE) >> 1;
		SD0_CardInfo->CID.Reserved2 = 1;

		return 0;  	
}





