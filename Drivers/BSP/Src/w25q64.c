#include "w25q64.h"

void W25Q64_SPI_Init(void)
{
    FL_SPI_InitTypeDef    SPI_InitStruct = {0};
    FL_GPIO_InitTypeDef    GPIO_InitStruct;
    /* 
			CS				PE7
			D0(MISO)	PD2
			CLK				PD0
			D1(MOSI)	PD1
		*/
    GPIO_InitStruct.pin           = FL_GPIO_PIN_7;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON1;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		
		GPIO_InitStruct.pin           = FL_GPIO_PIN_0 | FL_GPIO_PIN_1 | FL_GPIO_PIN_2;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON3;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOD, &GPIO_InitStruct);
		
    SPI_InitStruct.softControl    = FL_ENABLE;                       //软件控制SSN使能
    SPI_InitStruct.mode           = FL_SPI_WORK_MODE_MASTER;         //主机模式
    SPI_InitStruct.baudRate       = FL_SPI_PCLK_DIV4;                //波特率：80M/4=20M
    SPI_InitStruct.bitOrder       = FL_SPI_BIT_ORDER_MSB_FIRST;      //先发送MSB
    SPI_InitStruct.dataWidth_l    = FL_SPI_DATAL_LENGTH0;
    SPI_InitStruct.dataWidth_h    = FL_SPI_DATAH_LENGTH0;            //数据长度：8bit
    SPI_InitStruct.clockPhase     = FL_SPI_PHASE_EDGE1;              //时钟相位
    SPI_InitStruct.clockPolarity  = FL_SPI_POLARITY_NORMAL;            //时钟极性
    SPI_InitStruct.transferMode   = FL_SPI_TRANSFER_MODE_FULL_DUPLEX;//全双工

    FL_SPI_Init(SPI2, &SPI_InitStruct);
}


uint32_t W25Q64_ReadWriteByte(uint32_t data)
{
    uint32_t timeout = 0;

    FL_SPI_WriteTXBuff(SPI2, data);

    do {
        timeout++;
    } while(!FL_SPI_IsActiveFlag_TXBuffEmpty(SPI2) && timeout < TIMEOUT_VAL);

    timeout = 0;
    do {
        timeout++;
    } while(!FL_SPI_IsActiveFlag_RXBuffFull(SPI2) && timeout < TIMEOUT_VAL);

    data = FL_SPI_ReadRXBuff(SPI2);

    return data;
}

/*
获取W25Q64设备ID
返回值：高8位生产ID
		低8位器件ID
*/
uint16_t W25Q64_GetID(void)
{
		uint16_t id=0;
		//发送读制造/器件号指令 0x90
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x90);
		//发送24位地址
		W25Q64_ReadWriteByte(0x00);
		W25Q64_ReadWriteByte(0x00);
		W25Q64_ReadWriteByte(0x00);
		id = W25Q64_ReadWriteByte(0xFF)<<8;	//生产ID
		id |= W25Q64_ReadWriteByte(0xFF);		//器件ID
		W25Q64_CS_H();
		return id;
}

//读取状态寄存器
uint8_t W25Q64_ReadState(void)
{
		uint8_t state=0;
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x05);
		state = W25Q64_ReadWriteByte(0xFF);//读取状态值
		W25Q64_CS_H();
		return state;
}

//写使能
void W25Q64_WriteENABLE(void)
{
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x06);//写使能
		W25Q64_CS_H();
}

/*
	\brief：	扇区擦除
	\param：	addr 24位扇区地址
	\retval：	none
*/
void W25Q64_SectorErase(uint32_t addr)
{
		while(W25Q64_ReadState() & W25Q64_BUSY);//等待忙结束
		W25Q64_WriteENABLE();//写使能
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x20);//扇区擦除
		W25Q64_ReadWriteByte((addr&0xFF0000)>>16);//发送24位地址
		W25Q64_ReadWriteByte((addr&0xFF00)>>8);
		W25Q64_ReadWriteByte((addr&0xFF));
		W25Q64_CS_H();
}

/*
	\brief：	块擦除
	\param：	addr 24位块区地址
	\retval：	none
*/
void W25Q64_BlockErase(uint32_t addr)
{
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x06);//写使能
		W25Q64_ReadWriteByte(0xDB);//扇区擦除
		W25Q64_ReadWriteByte((uint8_t )(addr&0x00FF0000)>>16);//发送24位地址
		W25Q64_ReadWriteByte((uint8_t )(addr&0x0000FF00)>>8);
		W25Q64_ReadWriteByte((uint8_t )(addr&0x000000FF));
		W25Q64_CS_H();
}

/*
	\brief：	读数据
	\param：	addr：要读取的地址
				data：保存读取的数据
				size：读取的字节数（数据长度）
	\retval：	none
*/
void W25Q64_ReadData(uint32_t addr, uint8_t *data, uint16_t size)
{
		if(addr+size > W25Q64_END_ADDR) 
		{
				return ;
		}
		uint8_t *pData=data;
		while(W25Q64_ReadState() & W25Q64_BUSY);//等待忙结束
		W25Q64_CS_L();
		W25Q64_ReadWriteByte(0x03);//读数据指令
		W25Q64_ReadWriteByte((addr&0xFF0000)>>16);//发送24位地址
		W25Q64_ReadWriteByte((addr&0xFF00)>>8);
		W25Q64_ReadWriteByte((addr&0xFF));
		while(size--)
		{
				*pData=W25Q64_ReadWriteByte(0xFF);//保存数据
				pData++;
		}
		W25Q64_CS_H();
}

//页编程
void W25Q64_PageWrite(uint32_t addr, uint8_t *data, uint16_t size)
{
		if(addr+size > W25Q64_END_ADDR) 
				return ;
		uint8_t *pData = data;
		while(W25Q64_ReadState() & W25Q64_BUSY);//等待忙结束
		W25Q64_WriteENABLE();//写使能
		W25Q64_CS_L();
		//while(!(W25Q64_ReadState() & W25Q64_WEL));//等待写使能完成
		W25Q64_ReadWriteByte(0x02);//页写指令
		W25Q64_ReadWriteByte((addr&0xFF0000)>>16);//发送24位地址
		W25Q64_ReadWriteByte((addr&0xFF00)>>8);
		W25Q64_ReadWriteByte((addr&0xFF));
		while(size--)
		{
				W25Q64_ReadWriteByte(*pData);
				pData++;
		}
		W25Q64_CS_H();
}

/*
	\brief：	可跨页写数据（不考虑擦除，认为写入的地址都为0xFF）
	\param：	addr：要写入的地址
				data：写入的数据
				size：数据的数量（字节数）
	\retval：	none
*/
void W25Q64_StepOverPageWrite(uint32_t addr, uint8_t *data, uint32_t size)
{
		uint32_t addr_remain= 256 - addr%256;//当前页地址剩余
		uint8_t *pData=data;
		if(size <= addr_remain)
		{
				addr_remain = size;
		}
		while(1)
		{
				W25Q64_PageWrite(addr,pData,addr_remain);
				if(addr_remain == size) break;		//数据全部写入
				pData += addr_remain;	//数据地址偏移
				addr += addr_remain;	//地址偏移
				size -= addr_remain;	//计算剩余数据
				addr_remain = 256;//写入一页数据
				if(size <= addr_remain)	//计算当前页是否够写入剩余数据
				{
						addr_remain = size;
				}
		}
}

/*
	\brief：	可跨页写数据（考虑擦除和原有数据）
	\param：	addr：要写入的地址
				data：写入的数据
				size：数据的数量（字节数）
	\retval：	none
*/
uint8_t sector_data[W25Q64_SECTOR_SIZE];
void W25Q64_WriteData(uint32_t addr, uint8_t *data, uint32_t size)
{
		uint16_t sector_offset = addr%4096;	//计算当前扇区的地址偏移
		uint16_t sector_remain = 4096 - sector_offset;	//计算当前扇区剩余
		uint32_t sector_addr = addr - sector_offset;	//计算当前扇区的起始地址
		uint8_t *pData=data;
		uint32_t i;
		if(size <= sector_remain)
		{
				sector_remain=(uint16_t )size;
		}
		while(1)
		{
				W25Q64_ReadData(addr,sector_data,sector_remain);//读取要写入地址的数据
				for(i=0;i<sector_remain;i++)
				{
						if(sector_data[i]!=0xFF) break;
				}
				if(i!=sector_remain)//判断是否需要擦除扇区
				{
						//擦除前保存当前扇区前一段数据
						W25Q64_ReadData(sector_addr,sector_data,sector_offset);
						//擦除前保存当前扇区后一段数据
						W25Q64_ReadData(addr + sector_remain,sector_data+(sector_offset+sector_remain),W25Q64_SECTOR_SIZE - (sector_offset+sector_remain));
						W25Q64_SectorErase(sector_addr);//擦除扇区
						//将要写入的数据插入缓冲区
						for(i=0;i<sector_remain;i++)
						{
							sector_data[sector_offset+i]= pData[i];
						}
						W25Q64_StepOverPageWrite(sector_addr,sector_data,W25Q64_SECTOR_SIZE);
						sector_offset = 0;
				}
				else
				{
						W25Q64_StepOverPageWrite(addr,pData,sector_remain);//向当前扇区写入数据
				}
				if(sector_remain == size) break;//全部数据完全写入
				
				pData += sector_remain;	//数据地址偏移
				addr += sector_remain;	//flash地址偏移
				sector_addr = addr;		//当前扇区起始地址
				size -= sector_remain;	//数据量减少
				sector_remain = W25Q64_SECTOR_SIZE;//当前扇区剩余
				if(size <= W25Q64_SECTOR_SIZE)//计算当前扇区是否够写入剩余数据
				{
						sector_remain = size;
				}
		}
}


