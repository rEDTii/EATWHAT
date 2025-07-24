/**
 *******************************************************************************************************
 * @file    fm33fk5xx_fl_can.c
 * @author  FMSH Application Team
 * @brief   Source file of CAN FL Module
 *******************************************************************************************************   */
#include "fm33fk5xx_fl.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */

/** @addtogroup CAN
  * @{
  */

#ifdef FL_CAN_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup CAN_FL_Private_Macros
  * @{
  */

#define     IS_CAN_INSTANCE(INSTANCE)                     (((INSTANCE) == CAN))

#define     IS_CAN_SJW(__VALUE__)                        (((__VALUE__) == FL_CAN_SJW_1Tq) ||\
                                                          ((__VALUE__) == FL_CAN_SJW_2Tq) ||\
                                                          ((__VALUE__) == FL_CAN_SJW_3Tq) ||\
                                                          ((__VALUE__) == FL_CAN_SJW_4Tq))

#define     IS_CAN_TS1(__VALUE__)                        (((__VALUE__) == FL_CAN_TS1_1Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_2Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_3Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_4Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_5Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_6Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_7Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_8Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_9Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_10Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_11Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_12Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_13Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_14Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_15Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS1_16Tq))

#define     IS_CAN_TS2(__VALUE__)                        (((__VALUE__) == FL_CAN_TS2_1Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_2Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_3Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_4Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_5Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_6Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_7Tq) ||\
                                                          ((__VALUE__) == FL_CAN_TS2_8Tq))

#define    IS_CAN_TX_PRIORITY(__VALUE__)                 (((__VALUE__) == FL_CAN_TX_PRIORITY_ID) ||\
                                                          ((__VALUE__) == FL_CAN_TX_PRIORITY_BUFFER))

#define    IS_CAN_FILTER_EN(__VALUE__)                   (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_AFx(__VALUE__)                         (((__VALUE__) == FL_CAN_FILTER1) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER2) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER3) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER4) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER5) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER6) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER7) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER8) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER9) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER10) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER11) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER12) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER13) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER14) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER15) ||\
                                                          ((__VALUE__) == FL_CAN_FILTER16))

#define    IS_CAN_AFMRx(__VALUE__)                       (((__VALUE__) == FL_CAN_FILTERMASK1) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERMASK2) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERMASK3) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERMASK4))

#define    IS_CAN_AFIRx(__VALUE__)                       (((__VALUE__) == FL_CAN_FILTERID1) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERID2) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERID3) ||\
                                                          ((__VALUE__) == FL_CAN_FILTERID4))

#define    IS_CAN_MODE(__VALUE__)                        (((__VALUE__) == FL_CAN_MODE_NORMAL)   ||\
                                                          ((__VALUE__) == FL_CAN_MODE_LOOPBACK) ||\
                                                          ((__VALUE__) == FL_CAN_MODE_CONFIG)   ||\
                                                          ((__VALUE__) == FL_CAN_MODE_SLEEP))

#define    IS_CAN_CLK(__VALUE__)                         (((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_RCHF) ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_XTHF) ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_PLL)  ||\
                                                          ((__VALUE__) == FL_CMU_FSCAN_CLK_SOURCE_APBCLK))

#define    IS_CAN_ABOM(__VALUE__)                        (((__VALUE__) == FL_CAN_AUTO_MANAGE_HARDWARE)      ||\
                                                          ((__VALUE__) == FL_CAN_AUTO_MANAGE_SOFTWARE_WAIT) ||\
                                                          ((__VALUE__) == FL_CAN_AUTO_MANAGE_SOFTWARE_INTERGRATION))

#define    IS_CAN_WAKEUP(__VALUE__)                      (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_SRR(__VALUE__)                         (((__VALUE__) == FL_CAN_SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_SRR_BIT_HIGH))

#define    IS_CAN_STD1SRR(__VALUE__)                     (((__VALUE__) == FL_CAN_STD1SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_STD1SRR_BIT_HIGH))

#define    IS_CAN_STD2SRR(__VALUE__)                     (((__VALUE__) == FL_CAN_STD2SRR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_STD2SRR_BIT_HIGH))

#define    IS_CAN_IDE(__VALUE__)                         (((__VALUE__) == FL_CAN_IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_IDE_BIT_HIGH))

#define    IS_CAN_STD1IDE(__VALUE__)                     (((__VALUE__) == FL_CAN_STD1IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_STD1IDE_BIT_HIGH))

#define    IS_CAN_STD2IDE(__VALUE__)                     (((__VALUE__) == FL_CAN_STD2IDE_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_STD2IDE_BIT_HIGH))

#define    IS_CAN_RTR(__VALUE__)                         (((__VALUE__) == FL_CAN_RTR_BIT_LOW) ||\
                                                          ((__VALUE__) == FL_CAN_RTR_BIT_HIGH))

#define    IS_CAN_ID29_MASK(__VALUE__)                    ((__VALUE__) <= 0x1FFFFFFFU)
#define    IS_CAN_ID11_MASK(__VALUE__)                    ((__VALUE__) <= 0x7FFU)

#define    IS_CAN_STD1ID29_MASK(__VALUE__)                ((__VALUE__) <= 0X1FFFFFFFU)
#define    IS_CAN_STD1ID11_MASK(__VALUE__)                ((__VALUE__) <= 0x7FFU)

#define    IS_CAN_STD2ID29_MASK(__VALUE__)                ((__VALUE__) <= 0X1FFFFFFFU)
#define    IS_CAN_STD2ID11_MASK(__VALUE__)                ((__VALUE__) <= 0x7FFU)

#define    IS_CAN_SRR_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_IDE_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_STD1SRR_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_STD1IDE_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_STD2SRR_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_STD2IDE_MASK(__VALUE__)                (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_RTR_MASK(__VALUE__)                    (((__VALUE__) == FL_ENABLE) ||\
                                                          ((__VALUE__) == FL_DISABLE))

#define    IS_CAN_MASKMODE(__VALUE__)                    (((__VALUE__) == FL_CAN_MASKMODE_ID) ||\
                                                          ((__VALUE__) == FL_CAN_MASKMODE_MASK))

#define    IS_CAN_IDMODE(__VALUE__)                      (((__VALUE__) == FL_CAN_IDMODE_16BIT) ||\
                                                          ((__VALUE__) == FL_CAN_IDMODE_32BIT))
/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup CAN_FL_Private_Consts
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup CAN_FL_EF_Init
  * @{
  */

/**
  * @brief  CAN初始化
  * @param  CANx外设入口地址
  * @param  CAN_InitStruct 指向一个@ref FL_CAN_InitTypeDef  结构体的指针
  * @retval 错误状态可能值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_CAN_Init(CAN_Type *CANx, FL_CAN_InitTypeDef *CAN_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(CAN_InitStruct != NULL)
    {
        /*参数检查*/
        assert_param(IS_CAN_INSTANCE(CANx));
        assert_param(IS_CAN_SJW(CAN_InitStruct->SJW));
        assert_param(IS_CAN_TS1(CAN_InitStruct->TS1));
        assert_param(IS_CAN_TS2(CAN_InitStruct->TS2));
        assert_param(IS_CAN_TX_PRIORITY(CAN_InitStruct->TXPriority));
        assert_param(IS_CAN_CLK(CAN_InitStruct->clockSource));
        assert_param(IS_CAN_MODE(CAN_InitStruct->mode));
        assert_param(IS_CAN_WAKEUP(CAN_InitStruct->wakeup));
        assert_param(IS_CAN_ABOM(CAN_InitStruct->ABOM));
        /*时钟总线配置*/
        if(CANx == CAN)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_FSCAN);
            FL_CMU_EnableGroup2OperationClock(FL_CMU_OPCLK_FSCAN);
            /*CAN时钟源选择*/
            FL_CMU_SetFSCANClockSource(CAN_InitStruct->clockSource);
        }

        /*复位CAN模块*/
        FL_CAN_EnableSoftwareReset(CANx);
        FL_CAN_SetAutoBusOffManagement(CANx, CAN_InitStruct->ABOM);
        FL_CAN_SetTXPriority(CANx, CAN_InitStruct->TXPriority);
        /*设置重同步宽度*/
        FL_CAN_WriteSyncJumpWidth(CANx, CAN_InitStruct->SJW);
        /*设置时间段11*/
        FL_CAN_WriteTimeSegment1Length(CANx, CAN_InitStruct->TS1);
        /*设置时间段22*/
        FL_CAN_WriteTimeSegment2Length(CANx, CAN_InitStruct->TS2);
        /*设置波特率*/
        FL_CAN_WriteBaudRatePrescaler(CANx, CAN_InitStruct->BRP);
        if(CAN_InitStruct->wakeup == FL_ENABLE)
        {
            FL_CAN_EnableWakeup(CANx);
        }
        else
        {
            FL_CAN_DisableWakeup(CANx);
        }
        if(CAN_InitStruct->AREN  == FL_ENABLE)
        {
            FL_CAN_EnableAutoResend(CANx);
        }
        else
        {
            FL_CAN_DisableAutoResend(CANx);
        }
        if(CAN_InitStruct->mode == FL_CAN_MODE_NORMAL)
        {
            FL_CAN_DisableSleepMode(CANx);
            FL_CAN_DisableLoopBackMode(CANx);    /* Normal模式 */
            FL_CAN_Enable(CANx);
        }
        else if(CAN_InitStruct->mode == FL_CAN_MODE_LOOPBACK)
        {
            FL_CAN_EnableLoopBackMode(CANx);    /* Loop Back模式*/
            FL_CAN_DisableSleepMode(CANx);
            FL_CAN_Enable(CANx);
        }
        else if(CAN_InitStruct->mode == FL_CAN_MODE_SLEEP)
        {
            FL_CAN_EnableSleepMode(CANx);         /*Sleep模式*/
            FL_CAN_DisableLoopBackMode(CANx);
            FL_CAN_Enable(CANx);
        }
        else
        {
            FL_CAN_Disable(CANx);    /* Configuration模式 */
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 CAN_InitStruct 为默认模式
  * @param  CAN_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_CAN_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_CAN_StructInit(FL_CAN_InitTypeDef *CAN_InitStruct)
{
    if(CAN_InitStruct != NULL)
    {
        CAN_InitStruct->mode = FL_CAN_MODE_NORMAL;
        CAN_InitStruct->BRP = 0;
        CAN_InitStruct->clockSource = FL_CMU_FSCAN_CLK_SOURCE_RCHF;
        CAN_InitStruct->SJW = FL_CAN_SJW_1Tq;
        CAN_InitStruct->TS1 = FL_CAN_TS1_5Tq;
        CAN_InitStruct->TS2 = FL_CAN_TS2_4Tq;
        CAN_InitStruct->ABOM = FL_CAN_AUTO_MANAGE_HARDWARE;
        CAN_InitStruct->AREN = FL_ENABLE;
        CAN_InitStruct->TXPriority = FL_CAN_TX_PRIORITY_BUFFER;
        CAN_InitStruct->wakeup = FL_DISABLE;
    }
}

/**
  * @brief  CAN滤波器初始化
  * @param  CANx外设入口地址
  * @param  filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param  CAN_InitFilterStruct 指向一个@ref FL_CAN_FilterInitTypeDef  结构体的指针
  * @retval 错误状态可能值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置过程
  */
FL_ErrorStatus FL_CAN_FilterInit(CAN_Type *CANx, FL_CAN_FilterInitTypeDef *CAN_FilterInitStruct, uint32_t filterX)
{
    FL_ErrorStatus status = FL_FAIL;
    if(CAN_FilterInitStruct != NULL)
    {
        assert_param(IS_CAN_SRR(CAN_FilterInitStruct->filterIdSRR));
        assert_param(IS_CAN_IDE(CAN_FilterInitStruct->filterIdIDE));
        assert_param(IS_CAN_STD1SRR(CAN_FilterInitStruct->filterSTD1IdSRR));
        assert_param(IS_CAN_STD1IDE(CAN_FilterInitStruct->filterSTD1IdIDE));
        assert_param(IS_CAN_STD2SRR(CAN_FilterInitStruct->filterSTD2IdSRR));
        assert_param(IS_CAN_STD2IDE(CAN_FilterInitStruct->filterSTD2IdIDE));
        assert_param(IS_CAN_RTR(CAN_FilterInitStruct->filterIdRTR));
        assert_param(IS_CAN_FILTER_EN(CAN_FilterInitStruct->filterEn));
        assert_param(IS_CAN_ID29_MASK(CAN_FilterInitStruct->filterMaskIdExtend));
        assert_param(IS_CAN_ID11_MASK(CAN_FilterInitStruct->filterMaskIdStandard));
        assert_param(IS_CAN_STD1ID29_MASK(CAN_FilterInitStruct->filterSTD1MaskIdExtend));
        assert_param(IS_CAN_STD1ID11_MASK(CAN_FilterInitStruct->filterSTD1MaskIdStandard));
        assert_param(IS_CAN_STD2ID29_MASK(CAN_FilterInitStruct->filterSTD2MaskIdExtend));
        assert_param(IS_CAN_STD2ID11_MASK(CAN_FilterInitStruct->filterSTD2MaskIdStandard));
        assert_param(IS_CAN_SRR_MASK(CAN_FilterInitStruct->filterMaskIdSRR));
        assert_param(IS_CAN_IDE_MASK(CAN_FilterInitStruct->filterMaskIdIDE));
        assert_param(IS_CAN_STD1SRR_MASK(CAN_FilterInitStruct->filterSTD1MaskIdSRR));
        assert_param(IS_CAN_STD1IDE_MASK(CAN_FilterInitStruct->filterSTD1MaskIdIDE));
        assert_param(IS_CAN_STD2SRR_MASK(CAN_FilterInitStruct->filterSTD2MaskIdSRR));
        assert_param(IS_CAN_STD2IDE_MASK(CAN_FilterInitStruct->filterSTD2MaskIdIDE));
        assert_param(IS_CAN_RTR_MASK(CAN_FilterInitStruct->filterMaskIdRTR));
        assert_param(IS_CAN_IDMODE(CAN_FilterInitStruct->filterIDMode));
        assert_param(IS_CAN_MASKMODE(CAN_FilterInitStruct->filterMaskMode));
        assert_param(IS_CAN_AFx(filterX));
        while(FL_CAN_IsActiveFlag_FilterBusy(CANx) != 0)
        {
        }
        /* 掩码模式设置*/
        FL_CAN_Filter_SetMaskMode(CANx, filterX, CAN_FilterInitStruct->filterMaskMode);
        /* ID模式设置*/
        FL_CAN_Filter_SetIDMode(CANx, filterX, CAN_FilterInitStruct->filterIDMode);
        /* 滤波器32bit模式 */
        if(CAN_FilterInitStruct->filterIDMode  == FL_CAN_IDMODE_32BIT)
        {
            if(CAN_FilterInitStruct->filterIdIDE == FL_CAN_IDE_BIT_HIGH)
            {
                /* 滤波器ID设置 */
                FL_CAN_FilterEXT_WriteIDCompare(CANx, filterX, ((CAN_FilterInitStruct->filterIdExtend) >> 18) & 0X000007FFU);
                FL_CAN_FilterEXT_WriteEXTIDCompare(CANx, filterX, (CAN_FilterInitStruct->filterIdExtend) & 0X0003FFFFU);
                /* 滤波器ID掩码设置 */
                FL_CAN_FilterEXT_WriteIDCompareMask(CANx, filterX, ((CAN_FilterInitStruct->filterMaskIdExtend) >> 18) & 0X000007FFU);
                FL_CAN_FilterEXT_WriteEXTIDCompareMask(CANx, filterX, (CAN_FilterInitStruct->filterMaskIdExtend) & 0X0003FFFFU);
            }
            else
            {
                /* 滤波器ID设置 */
                FL_CAN_FilterEXT_WriteIDCompare(CANx, filterX, (CAN_FilterInitStruct->filterIdStandard) & 0X000007FFU);
                /* 滤波器ID掩码设置 */
                FL_CAN_FilterEXT_WriteIDCompareMask(CANx, filterX, (CAN_FilterInitStruct->filterMaskIdStandard) & 0X000007FFU);
            }
            FL_CAN_FilterEXT_SetSRRCompare(CANx, filterX, CAN_FilterInitStruct->filterIdSRR);
            /* 滤波器ID设置 */
            FL_CAN_FilterEXT_SetIDECompare(CANx, filterX, CAN_FilterInitStruct->filterIdIDE);
            FL_CAN_FilterEXT_SetRTRCompare(CANx, filterX, CAN_FilterInitStruct->filterIdRTR);
            if((CAN_FilterInitStruct->filterMaskIdSRR) == FL_ENABLE)
            {
                /* SRR参与滤波器比较 */
                FL_CAN_FilterEXT_EnableSRRCompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterEXT_DisableSRRCompare(CANx, filterX);
            }
            if((CAN_FilterInitStruct->filterMaskIdIDE) == FL_ENABLE)
            {
                /* IDE位参与滤波器比较 */
                FL_CAN_FilterEXT_EnableIDECompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterEXT_DisableIDECompare(CANx, filterX);
            }
            if((CAN_FilterInitStruct->filterMaskIdRTR) == FL_ENABLE)
            {
                /* RTR位参与滤波器比较 */
                FL_CAN_FilterEXT_EnableRTRCompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterEXT_DisableRTRCompare(CANx, filterX);
            }
        }
        else /* 滤波器16bit模式 */
        {
            /* 滤波器低16位参数设置 */
            if(CAN_FilterInitStruct->filterSTD1IdIDE == FL_CAN_STD1IDE_BIT_HIGH)
            {
                /* 滤波器1 ID设置 */
                FL_CAN_FilterSTD1_WriteIDCompare(CANx, filterX, ((CAN_FilterInitStruct->filterSTD1IdExtend) >> 18) & 0X000007FFU);
                FL_CAN_FilterSTD1_WriteEXTIDCompare(CANx, filterX, ((CAN_FilterInitStruct->filterSTD1IdExtend >> 15)) & 0X7U);
                /* 滤波器1 ID掩码设置 */
                FL_CAN_FilterSTD1_WriteIDCompareMask(CANx, filterX, (CAN_FilterInitStruct->filterSTD1MaskIdExtend >> 18) & 0X000007FFU);
                FL_CAN_FilterSTD1_WriteEXTIDCompareMask(CANx, filterX, (CAN_FilterInitStruct->filterSTD1MaskIdExtend >> 15) & 0X7U);
            }
            else
            {
                /* 滤波器1 ID设置 */
                FL_CAN_FilterSTD1_WriteIDCompare(CANx, filterX, (CAN_FilterInitStruct->filterSTD1IdStandard) & 0X000007FFU);
                /* 滤波器1 ID掩码设置 */
                FL_CAN_FilterSTD1_WriteIDCompareMask(CANx, filterX, (CAN_FilterInitStruct->filterSTD1MaskIdStandard) & 0X000007FFU);
            }
            FL_CAN_FilterSTD1_SetSRRCompare(CANx, filterX, CAN_FilterInitStruct->filterSTD1IdSRR);
            FL_CAN_FilterSTD1_SetIDECompare(CANx, filterX, CAN_FilterInitStruct->filterSTD1IdIDE);
            if((CAN_FilterInitStruct->filterSTD1MaskIdSRR) == FL_ENABLE)
            {
                /* SRR参与滤波器比较 */
                FL_CAN_FilterSTD1_EnableSRRCompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterSTD1_DisableSRRCompare(CANx, filterX);
            }
            if((CAN_FilterInitStruct->filterSTD1MaskIdIDE) == FL_ENABLE)
            {
                /* IDE位参与滤波器比较 */
                FL_CAN_FilterSTD1_EnableIDECompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterSTD1_DisableIDECompare(CANx, filterX);
            }
            /* 滤波器高16位参数设置 */
            if(CAN_FilterInitStruct->filterSTD2IdIDE == FL_CAN_STD2IDE_BIT_HIGH)
            {
                /* 滤波器2 ID设置 */
                FL_CAN_FilterSTD2_WriteIDCompare(CANx, filterX, ((CAN_FilterInitStruct->filterSTD2IdExtend) >> 18) & 0X000007FFU);
                FL_CAN_FilterSTD2_WriteEXTIDCompare(CANx, filterX, ((CAN_FilterInitStruct->filterSTD2IdExtend >> 15)) & 0X7U);
                /* 滤波器2 ID掩码设置 */
                FL_CAN_FilterSTD2_WriteIDCompareMask(CANx, filterX, ((CAN_FilterInitStruct->filterSTD2MaskIdExtend) >> 18) & 0X000007FFU);
                FL_CAN_FilterSTD2_WriteEXTIDCompareMask(CANx, filterX, ((CAN_FilterInitStruct->filterSTD2MaskIdExtend) >> 15) & 0X7U);
            }
            else
            {
                /* 滤波器2 ID设置 */
                FL_CAN_FilterSTD2_WriteIDCompare(CANx, filterX, (CAN_FilterInitStruct->filterSTD2IdStandard) & 0X000007FFU);
                /* 滤波器2 ID掩码设置 */
                FL_CAN_FilterSTD2_WriteIDCompareMask(CANx, filterX, ((CAN_FilterInitStruct->filterSTD2MaskIdStandard)) & 0X000007FFU);
            }
            FL_CAN_FilterSTD2_SetSRRCompare(CANx, filterX, CAN_FilterInitStruct->filterSTD2IdSRR);
            FL_CAN_FilterSTD2_SetIDECompare(CANx, filterX, CAN_FilterInitStruct->filterSTD2IdIDE);
            if((CAN_FilterInitStruct->filterSTD2MaskIdSRR) == FL_ENABLE)
            {
                /* SRR参与滤波器比较 */
                FL_CAN_FilterSTD2_EnableSRRCompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterSTD2_DisableSRRCompare(CANx, filterX);
            }
            if((CAN_FilterInitStruct->filterSTD2MaskIdIDE) == FL_ENABLE)
            {
                /* IDE位参与滤波器比较 */
                FL_CAN_FilterSTD2_EnableIDECompare(CANx, filterX);
            }
            else
            {
                FL_CAN_FilterSTD2_DisableIDECompare(CANx, filterX);
            }
        }
        if((CAN_FilterInitStruct->filterEn) == FL_ENABLE)
        {
            /* 滤波器使能 */
            FL_CAN_Filter_Enable(CANx, filterX);
        }
        else
        {
            FL_CAN_Filter_Disable(CANx, filterX);
        }
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  设置CAN_FilterInitStruct 为默认配置
  * @param  CAN_FilterInitStruct 指向需要将值设置为默认的结构体 @ref FL_CAN_FilterInitTypeDef 结构体
  *
  * @retval None
  */
void FL_CAN_StructFilterInit(FL_CAN_FilterInitTypeDef *CAN_FilterInitStruct)
{
    if(CAN_FilterInitStruct != NULL)
    {
        CAN_FilterInitStruct->filterEn = FL_DISABLE;
        CAN_FilterInitStruct->filterIdExtend = 0;
        CAN_FilterInitStruct->filterMaskIdStandard = 0x7FF;
        CAN_FilterInitStruct->filterIdIDE = FL_CAN_IDE_BIT_LOW;
        CAN_FilterInitStruct->filterMaskIdIDE = FL_DISABLE;
        CAN_FilterInitStruct->filterMaskIdExtend = 0x1FFFFFFF;
        CAN_FilterInitStruct->filterIdRTR = FL_CAN_RTR_BIT_LOW;
        CAN_FilterInitStruct->filterMaskIdRTR = FL_DISABLE;
        CAN_FilterInitStruct->filterIdSRR = FL_CAN_SRR_BIT_LOW;
        CAN_FilterInitStruct->filterMaskIdSRR = FL_DISABLE;
        CAN_FilterInitStruct->filterIdStandard = 0;
        CAN_FilterInitStruct->filterSTD1IdExtend = 0;
        CAN_FilterInitStruct->filterSTD1MaskIdStandard = 0x7FF;
        CAN_FilterInitStruct->filterSTD1IdIDE = FL_CAN_IDE_BIT_LOW;
        CAN_FilterInitStruct->filterSTD1MaskIdIDE = FL_DISABLE;
        CAN_FilterInitStruct->filterSTD1MaskIdExtend = 0x1FFFFFFF;
        CAN_FilterInitStruct->filterSTD1IdSRR = FL_CAN_SRR_BIT_LOW;
        CAN_FilterInitStruct->filterSTD1MaskIdSRR = FL_DISABLE;
        CAN_FilterInitStruct->filterSTD1IdStandard = 0;
        CAN_FilterInitStruct->filterSTD2IdExtend = 0;
        CAN_FilterInitStruct->filterSTD2MaskIdStandard = 0x7FF;
        CAN_FilterInitStruct->filterSTD2IdIDE = FL_CAN_IDE_BIT_LOW;
        CAN_FilterInitStruct->filterSTD2MaskIdIDE = FL_DISABLE;
        CAN_FilterInitStruct->filterSTD2MaskIdExtend = 0x1FFFFFFF;
        CAN_FilterInitStruct->filterSTD2IdSRR = FL_CAN_SRR_BIT_LOW;
        CAN_FilterInitStruct->filterSTD2MaskIdSRR = FL_DISABLE;
        CAN_FilterInitStruct->filterSTD2IdStandard = 0;
    }
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup CAN_FL_Private_Functions CAN Private Functions
  * @{
  */

/* #error 在此处编写私有函数，并删除该行 */

/**
  * @}
  */

#endif /* FL_CAN_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
