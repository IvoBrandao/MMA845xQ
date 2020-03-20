/*
 *******************************************************************************
 * @file		: Drv_MMA8452Q.h
 * @Created on	: Jan 2, 2018
 * @Author		: Ivo
 *******************************************************************************
 *
 * Copyright 2018 Ivo
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy  
 * of this software and associated documentation files (the "Software"), to deal 
 * in the Software without restriction, including without limitation the rights  
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR INCONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 *******************************************************************************
 * @brief		: Description of the file.
 *******************************************************************************
 */

#ifndef MMA8452Q_INC_DRV_MMA8452Q_H_
#define MMA8452Q_INC_DRV_MMA8452Q_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Driver_MMA8452Q
 * @{
 */

/* * * * * * * * * * * * * * *  Module Declarations * * * * * * * * * * * * * */

/* Includes ------------------------------------------------------------------*/
#include "drv_mma845x_cfg.h"
/* Global function prototypes ------------------------------------------------*/
/* Global Defines & Macros ---------------------------------------------------*/
#define DRIVER_VERSION	"Ver. 1.0"
#define VENDOR_NAME		"Freescale Semiconductors"

#define MMA845X_BASE_ADDR_SA0 (0x38)
#define MMA845X_BASE_ADDR_SA1 (0x3A)

#define MMA845X_INSTANCE1              (MMA845X_BASE_ADDR_SA0)
#define MMA845X_INSTANCE2              (MMA845X_BASE_ADDR_SA1)

/* Global Types & enums  -----------------------------------------------------*/


/**
 * @brief HAL MMA8452Q State structures definition
 */
typedef enum {
	HAL_MMA845x_STATE_STANDBY = 0x00U, /*!< Peripheral is not initialized                  */
	HAL_MMA845x_STATE_WAKE = 0x01U, /*!< Peripheral Initialized and ready for use       */
	HAL_MMA845x_STATE_SLEEP = 0x02U, /*!< an internal process is ongoing                 */
} MMA845x_StateTypeDef;

typedef enum {

	HAL_MMA845x_DATA_RATE_800Hz = 0x00,
	HAL_MMA845x_DATA_RATE_400Hz,
	HAL_MMA845x_DATA_RATE_200Hz,
	HAL_MMA845x_DATA_RATE_100Hz,
	HAL_MMA845x_DATA_RATE_50Hz,
	HAL_MMA845x_DATA_RATE_12_5Hz,
	HAL_MMA845x_DATA_RATE_6_25Hz,
	HAL_MMA845x_DATA_RATE_1_56Hz,
} MMA845x_ODR_TypeDef;
typedef enum {

	HAL_MMA845x_ASLP_RATE_50Hz = 0x00,
	HAL_MMA845x_ASLP_RATE_12_5Hz,
	HAL_MMA845x_ASLP_RATE_6_25Hz,
	HAL_MMA845x_ASLP_RATE_1_56Hz,
} MMA845x_ASLPR_TypeDef;

typedef enum {
	HAL_MMA845x_OVSM_MODE_NORMAL = 0,
	HAL_MMA845x_OVSM_LOW_NOISE_LOW_POWER = 1,
	HAL_MMA845x_OVSM_HIGH_RESOLUTION = 2,
	HAL_MMA845x_OVSM_MODE_LOW_POWER = 3
} MMA845x_OVSM_TypeDef;

typedef enum {

	HAL_MMA845x_FULL_SCALE_2G = 0,
	HAL_MMA845x_FULL_SCALE_4G = 1,
	HAL_MMA845x_FULL_SCALE_8G = 2
} MMA845x_DynamicRange_TypeDef;


/**
 * @brief MMA845x Shadow Registers
 */
typedef struct {
	 uint8_t STATUS;          		/*!<  Address: 0x00 Real time status */
	 uint8_t OUT_X_MSB;              /*!<  Address: 0x01 [7:0] are 8 MSBs of 12-bit sample. */
	 uint8_t OUT_X_LSB;              /*!<  Address: 0x02 [7:4] are 4 LSBs of 12-bit sample. */
	 uint8_t OUT_Y_MSB;              /*!<  Address: 0x03 [7:0] are 8 MSBs of 12-bit sample. */
	 uint8_t OUT_Y_LSB;              /*!<  Address: 0x04 [7:4] are 4 LSBs of 12-bit sample. */
	 uint8_t OUT_Z_MSB;              /*!<  Address: 0x05 [7:0] are 8 MSBs of 12-bit sample. */
	 uint8_t OUT_Z_LSB;              /*!<  Address: 0x06 [7:4] are 4 LSBs of 12-bit sample. */
	 uint8_t RESERVED0;				 /*!<  Address: 0x07 Reserved. Read return 0x00. */
	 uint8_t RESERVED1;              /*!<  Address: 0x08 Reserved. Read return 0x00. */
	 uint8_t RESERVED2;              /*!<  Address: 0x09 Reserved. Read return 0x00. */
	 uint8_t RESERVED3;              /*!<  Address: 0x0A Reserved. Read return 0x00. */
	 uint8_t SYSMOD;                 /*!<  Address: 0x0B Current System mode */
	 uint8_t INT_SOURCE;             /*!<  Address: 0x0C Interrupt status */
	 uint8_t WHO_AM_I;               /*!<  Address: 0x0D Device ID */
	 uint8_t XYZ_DATA_CFG;           /*!<  Address: 0x0E HPF data out and dynamic range settings */
	 uint8_t HP_FILTER_CUTOFF;       /*!<  Address: 0x0F Cutoff frequency */
	 uint8_t PL_STATUS;              /*!<  Address: 0x10 Landscape/portrait orientation status */
	 uint8_t PL_CFG;                 /*!<  Address: 0x11 Landscape/portrait configuration. */
	 uint8_t PL_COUNT;               /*!<  Address: 0x12 Landscape/portrait debounce counter */
	 uint8_t PL_BF_ZCOMP;            /*!<  Address: 0x13 Back/front, Z-lock trip threshold */
	 uint8_t PL_P_L_THS_REG;         /*!<  Address: 0x14 Portrait to landscape trip angle is 29° */
	 uint8_t FF_MT_CFG;              /*!<  Address: 0x15 Freefall/motion functional block configuration */
	 uint8_t FF_MT_SRC;              /*!<  Address: 0x16 Freefall/motion event source register */
	 uint8_t FF_MT_THS;              /*!<  Address: 0x17 Freefall/motion threshold register */
	 uint8_t FF_MT_COUNT;            /*!<  Address: 0x18 Freefall/motion debounce counter */
	 uint8_t RESERVED4;              /*!<  Address: 0x19 Reserved. Read return 0x00. */
	 uint8_t RESERVED5;              /*!<  Address: 0x1A Reserved. Read return 0x00. */
	 uint8_t RESERVED6;              /*!<  Address: 0x1B Reserved. Read return 0x00. */
	 uint8_t RESERVED7;              /*!<  Address: 0x1C Reserved. Read return 0x00. */
	 uint8_t TRANSIENT_CFG;          /*!<  Address: 0x1D Transient functional block configuration */
	 uint8_t TRANSIENT_SRC;          /*!<  Address: 0x1E Transient event status register */
	 uint8_t TRANSIENT_THS;          /*!<  Address: 0x1F Transient event threshold */
	 uint8_t TRANSIENT_COUNT;        /*!<  Address: 0x20 Transient debounce counter */
	 uint8_t PULSE_CFG;              /*!<  Address: 0x21 ELE, Double_XYZ or Single_XYZ */
	 uint8_t PULSE_SRC;              /*!<  Address: 0x22 EA, Double_XYZ or Single_XYZ */
	 uint8_t PULSE_THSX;             /*!<  Address: 0x23 X pulse threshold */
	 uint8_t PULSE_THSY;             /*!<  Address: 0x24 Y pulse threshold */
	 uint8_t PULSE_THSZ;             /*!<  Address: 0x25 Z pulse threshold */
	 uint8_t PULSE_TMLT;             /*!<  Address: 0x26 Time limit for pulse */
	 uint8_t PULSE_LTCY;             /*!<  Address: 0x27 Latency time for 2nd pulse */
	 uint8_t PULSE_WIND;             /*!<  Address: 0x28 Window time for 2nd pulse */
	 uint8_t ASLP_COUNT;             /*!<  Address: 0x29 Counter setting for auto-sleep */
	 uint8_t CTRL_REG1;              /*!<  Address: 0x2A Data rate, active mode */
	 uint8_t CTRL_REG2;              /*!<  Address: 0x2B Sleep enable, OS modes, RST, ST */
	 uint8_t CTRL_REG3;              /*!<  Address: 0x2C Wake from sleep, IPOL, PP_OD */
	 uint8_t CTRL_REG4;              /*!<  Address: 0x2D Interrupt enable register */
	 uint8_t CTRL_REG5;              /*!<  Address: 0x2E Interrupt pin (INT1/INT2) map */
	 uint8_t OFF_X;                  /*!<  Address: 0x2F X-axis offset adjust */
	 uint8_t OFF_Y;                  /*!<  Address: 0x30 Y-axis offset adjust */
	 uint8_t OFF_Z;                  /*!<  Address: 0x31 Z-axis offset adjust */
} MMA845x_TypeDef;


/**
 * @brief MMA845x Init Structure definition
 */
typedef struct
{
	MMA845x_ODR_TypeDef DataRate;
	MMA845x_OVSM_TypeDef SleepSamplingMode;
	MMA845x_OVSM_TypeDef ActiveSamplingMode;
	MMA845x_ASLPR_TypeDef SleepRate;
	MMA845x_DynamicRange_TypeDef DynamicRange;
} MMA845x_InitTypeDef;


/**
 * @brief MMA845x Status Structure definition
 */
typedef struct
{
	uint8_t ZYXOW:1;	/*!< Is Previous X, Y, or Z data was overwritten by new X, Y, or Z data before it was read */
	uint8_t ZOW:1;		/*!< Is Previous Z-axis data was overwritten by new Z-axis data before it was read */
	uint8_t YOW:1;		/*!< Is Previous Y-axis data was overwritten by new Y-axis data before it was read*/
	uint8_t XOW:1; 		/*!< Is Previous X-axis data was overwritten by new X-axis data before it was read*/
	uint8_t ZYXDR:1; 	/*!< Is A new set of data is ready*/
	uint8_t ZDR:1; 		/*!< Is A new Z-axis data is ready*/
	uint8_t YDR:1; 		/*!< Is A new Y-axis data is ready*/
	uint8_t XDR:1; 		/*!< Is A new X-axis data is ready*/
}MMA845x_StatusTypeDef;

typedef struct
{
	uint8_t SRC_DRDY:1;
	uint8_t RESERVED1:1;
	uint8_t SRC_FF_MT:1;
	uint8_t SRC_PULSE:1;
	uint8_t SRC_LNDPRT:1;
	uint8_t SRC_TRANS:1;
	uint8_t RESERVED2:1;
	uint8_t SRC_ASLP:1;
}MMA845x_IntSrcTypeDef;

/**
 * @brief MMA845x Acceleration data Structure definition
 */
typedef struct {
	short x;
	short y;
	short z;
	float gx;
	float gy;
	float gz;
} AccelerationData_TypeDef;

/**
 * @brief  MMA8452Q handle Structure definition
 */
typedef struct  __MMA845x_HandleTypeDef{

	MMA845x_InitTypeDef Init; 			/*!< MMA845x communication parameters   */
	uint8_t Instance;					/*!< MMA845x Instance					*/
	uint8_t DeviceID;
	MMA845x_TypeDef Registers;			/*!< MMA845x registers base address     */
	MMA845x_StateTypeDef State; 		/*!< MMA845x state        				*/
	MMA845x_StatusTypeDef Status;		/*!< MMA845x Status						*/
	MMA845x_IntSrcTypeDef IntSrc;		/*!< MMA845x Status						*/
	uint8_t Int1;
	uint8_t Int2;
	AccelerationData_TypeDef Data;		/*!< MMA845x Data Pointer 				*/
} MMA845x_HandleTypeDef;




/* Global Defines & Macros ---------------------------------------------------*/


/* * * * * * * * * * * * * * * Module Functions * * * * * * * * * * * * * * * */

/* Global Functions ----------------------------------------------------------*/

Std_ReturnType Drv_MMA845x_Init(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_MainFunction(MMA845x_HandleTypeDef *hMMA845x);
// data Functions
//void Drv_MMA845x_RxXYZCpltCallback(MMA845x_HandleTypeDef *handle);
Std_ReturnType Drv_MMA845x_DeInit(MMA845x_HandleTypeDef *hMMA845x);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* MMA8452Q_INC_DRV_MMA8452Q_H_ */
