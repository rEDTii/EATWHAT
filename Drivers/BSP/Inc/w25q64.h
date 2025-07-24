#ifndef __W25Q64_H__
#define __W25Q64_H__

#include "fm33fk5xx_fl.h"

#define TIMEOUT_VAL     (0xFFFFFFFFUL)

#define W25Q64_CS_H() FL_SPI_SetSSNPin(SPI2, FL_SPI_SSN_HIGH)	//片选取消
#define W25Q64_CS_L() FL_SPI_SetSSNPin(SPI2, FL_SPI_SSN_LOW)	//片选选中

#define W25Q64_PAGE_SIZE	256		//页大小256字节
#define W25Q64_SECTOR_SIZE	4096	//扇区大小4096字节
#define W25Q64_START_ADDR	(uint32_t )0x000000		//起始地址
#define W25Q64_END_ADDR				(uint32_t )0x7FFFFF		//结束地址

// 用于FATFS文件系统的中文名字库
#define W25Q64_uni2oem_ADDR		(uint32_t )0x000000	
#define W25Q64_oem2uni_ADDR		(uint32_t )0x100000	
// 用于LCD中文显示的GBK字库
#define W25Q64_GBK_ADDR	(uint32_t )0x200000
// 用于存用户配置信息
#define W25Q64_ALARM_HOUR_ADDR		(uint32_t )0x300000
#define W25Q64_ALARM_MINUTE_ADDR	W25Q64_ALARM_HOUR_ADDR + 1
#define W25Q64_BRIGHTNESS_ADDR		W25Q64_ALARM_HOUR_ADDR + 2
#define W25Q64_VOLUME_ADDR	 			W25Q64_ALARM_HOUR_ADDR + 3

//状态位
#define W25Q64_BUSY			0x01	//忙位
#define W25Q64_WEL			0x02	//写保护位

void W25Q64_SPI_Init(void);
uint32_t W25Q64_ReadWriteByte(uint32_t data);
uint16_t W25Q64_GetID(void);
void W25Q64_SectorErase(uint32_t addr);
void W25Q64_BlockErase(uint32_t addr);
void W25Q64_WriteData(uint32_t addr, uint8_t *data, uint32_t size);
void W25Q64_ReadData(uint32_t addr, uint8_t *data, uint16_t size);

#endif
