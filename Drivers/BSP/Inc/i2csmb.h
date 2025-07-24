#ifndef __I2CSMB_H__
#define __I2CSMB_H__
#include "fm33fk5xx_fl.h"

#define I2CREAD     1                                                         //I2C读操作
#define I2CWRITE    0                                                         //I2C写操作

#define STARTBIT    0
#define RESTARTBIT  1
#define STOPBIT     2

#define DEVICE_EE256    0xA0                                                  //FM24C256的器件地址
#define ADDRLEN_EE256   2                                                     //FM24C256的数据地址长度为2字节

#define DEVICE_CTP    	0x28                                                  //触摸屏芯片GT911的器件地址
#define ADDRLEN_CTP   	2                                                     //GT911的数据地址长度为2字节


uint8_t I2C_Send_Bit(I2CSMB_Type *I2CSMBx, uint8_t BIT_def);
uint8_t I2C_Send_Byte(I2CSMB_Type *I2CSMBx, uint8_t x_byte);
uint8_t I2C_Receive_Byte(I2CSMB_Type *I2CSMBx, uint8_t *x_byte);
uint8_t Sendaddr(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t Opt);
uint8_t Wait_for_end(I2CSMB_Type *I2CSMBx, uint8_t Device);
uint8_t I2C_Write_Bottom(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len);
uint8_t I2C_Read_Bottom(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len);

void I2C_Init(void);
uint8_t GT911_I2C_Write(uint16_t reg, uint8_t *buf, uint8_t len);
uint8_t GT911_I2C_Read(uint16_t reg, uint8_t *buf, uint8_t len);

#endif
