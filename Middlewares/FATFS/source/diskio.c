/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */

#include "sd_driver.h"
#include "rtc.h"

/* Definitions of physical drive number for each drive */
#define DEV_SD		0	/* Map SD to physical drive 0 */


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	uint8_t result;

	if (pdrv == DEV_SD) {
			result = SD_init();
		  if (result) 
					return STA_NOINIT;
			else
					return RES_OK;
	}
	else
			return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	uint8_t result;

	if (pdrv == DEV_SD) {
			result = SD_ReadDisk(buff, sector, count);
		  if (result)
					return RES_ERROR;
			else
					return RES_OK;
	}
	else
			return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	uint8_t result;

	if (pdrv == DEV_SD) {
			result = SD_WriteDisk((uint8_t*)buff, sector, count);
		  if (result)
					return RES_ERROR;
			else
					return RES_OK;
	}
	else
			return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;

	if(pdrv==DEV_SD)
	{
	    switch(cmd)
	    {
		    case CTRL_SYNC:
						res = RES_OK; 
		        break;	 
		    case GET_SECTOR_SIZE:
						*(DWORD*)buff = 512; 
		        res = RES_OK;
		        break;	 
		    case GET_BLOCK_SIZE:
						*(WORD*)buff = SD0_CardInfo.BlockSize;
		        res = RES_OK;
		        break;	 
		    case GET_SECTOR_COUNT:
		        *(DWORD*)buff = SD0_CardInfo.Capacity/512;
		        res = RES_OK;
		        break;
		    default:
		        res = RES_PARERR;
		        break;
	    }
	}
	else
			res = RES_PARERR;
	
	return res;
}


DWORD get_fattime(void)
{
	//获得时间
  //DWORD 记录文件日期和时间信息的是一个32位的寄存器，
  //以下描述在32位的不同的不同范围内分别代表的值
	//31-25: Year(0-127 org.1980), 24-21: Month(1-12), 20-16: Day(1-31) 
	//15-11: Hour(0-23), 10-5: Minute(0-59), 4-0: Second(0-29 *2) */

	FL_RTCB_InitTypeDef  GetTime;
	RTCB_GetRTCB(&GetTime);; //从RTC中获取当前日期和时间
	
  DWORD dateTime;
	//由于RTC中保存的年份是0-99所以要加2000到正确年份。
	//由于fatfs中的年份又是在实际年份上减1980才得到真正保存的年份
	//待从文件信息中读取日期时间时需要加1980得到实际年份
	dateTime = ( BCD2Oct(GetTime.year) + 20 );
	dateTime = dateTime << 25; //偏移到年份所处的位
	dateTime |= ( BCD2Oct(GetTime.month) ) << 21; 
	dateTime |= ( BCD2Oct(GetTime.day) ) << 16;
	dateTime |= ( BCD2Oct(GetTime.hour) ) << 11;
	dateTime |= ( BCD2Oct(GetTime.minute) ) << 5;
	//实际秒数除以2得到保存的秒数
	//4-0: Second(0-29 *2) 由于描述占5位（1 1 1 1 1），最大只能保存的值是 31
	dateTime |= ( BCD2Oct(GetTime.second) >> 1 ); 
	return dateTime;
}



