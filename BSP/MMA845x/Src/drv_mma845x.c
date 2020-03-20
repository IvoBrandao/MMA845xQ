/*
 *******************************************************************************
 * @file		: Drv_MMA845xQ.c
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

/** @addtogroup Driver_MMA845xQ
 * @{
 */

/* * * * * * * * * * * * * * *  Module Declarations * * * * * * * * * * * * * */

/* Includes ------------------------------------------------------------------*/
#include <drv_mma845x.h>
#include <drv_mma845x_prv.h>
#include <drv_mma845x_cfg.h>
/* Global function prototypes ------------------------------------------------*/

/* Local function prototypes -------------------------------------------------*/

/* Local Types & enums  ------------------------------------------------------*/

/* Local Defines & Macros ----------------------------------------------------*/

/* Local variables  ----------------------------------------------------------*/

/* Global variables ----------------------------------------------------------*/

/* * * * * * * * * * * * * * * Module Functions * * * * * * * * * * * * * * * */

/* Global Functions ----------------------------------------------------------*/

Std_ReturnType Drv_MMA845x_Init(MMA845x_HandleTypeDef *hMMA845x) {

	if (Drv_MMA845x_GetDeviceID(hMMA845x) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	/* Control Register 1 configuration */
	if (Drv_MMA845x_EnableStandbyMode(hMMA845x) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_DisableFastreadMode(hMMA845x) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_EnableLowNoiseMode(hMMA845x) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_SetDataRate(hMMA845x, hMMA845x->Init.DataRate) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_SetAutoSleepRate(hMMA845x, hMMA845x->Init.SleepRate)
			!= E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/* Control Register 2 configuration*/
	if (Drv_MMA845x_SetSleepModePowerScheme(hMMA845x,
			hMMA845x->Init.SleepSamplingMode) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_SetActiveModePowerScheme(hMMA845x,
			hMMA845x->Init.ActiveSamplingMode) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/* XYZ Data configuration */
	if (Drv_MMA845x_SetDynamicRange(hMMA845x, hMMA845x->Init.DynamicRange)
			!= E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}
	if (Drv_MMA845x_DisableHPF(hMMA845x) != E_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if(Drv_MMA845x_EnableActiveMode(hMMA845x) != E_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}

	return (E_OK);
}


/*!
* This method is used to set initialize Orientation module in MMA845X chip with default settings.
* pChipInfo  : Chip structure of MMA845x.
* return 0 	      : For successful chip initialization, -EINVAL : For failure
*/

static int Drv_MMA845x_InitOrientationModule(MMA845x_HandleTypeDef *hMMA845x)
{
	int ret = 0;
/*
	WriteRegValue((REG845X_PL_CFG) , 6, 1 , pChip->ornt_enable);
	ret = i2c_smbus_read_byte_data(pClient, (REG845X_PL_CFG));

	WriteRegValue((REG845X_PL_BF_ZCOMP) , 6, 2 , pChip->bf_trip_angle);
	WriteRegValue((REG845X_PL_BF_ZCOMP) , 0, 3 , pChip->zlock_angle_ths);				//PL_BF_ZCOMP = 0x82


	WriteRegValue((REG845X_PL_THS_REG) , 3, 5 , pChip->trip_angle_threshold);
	WriteRegValue((REG845X_PL_THS_REG) , 0, 3 , pChip->trip_angle_hysteresis);

	i2c_smbus_write_byte_data(pClient, (REG845X_CTRL_REG4), 0x10);
*/
	return 0;
}

/*!
* This method is used to set initialize Motion module in MMA845X chip with default settings.
* pChipInfo  : Chip structure of MMA845x.
* return 0 	      : For successful chip initialization, -EINVAL : For failure
*/

static int Drv_MMA845x_InitMotionModule(MMA845x_HandleTypeDef *hMMA845x)
{
	//bool latch;

	/* Set condition for motion detection */
	//WriteRegValue((REG845X_FF_MT_CFG) , 3, 3 , pChip->fm_enable); 					 // X Y Enable
	//latch = ((pChip->fm_enable > 0 )? 1 : 0);
	//WriteRegValue((REG845X_FF_MT_CFG) , 7, 1 , latch);
   //     WriteRegValue((REG845X_FF_MT_CFG) , 6, 1 , pChip->fm_threshold_logic);

	/* Set threshold value */
	//WriteRegValue((REG845X_FF_MT_THS) , 0, 7 , pChip->fm_threshold);

	/* Debounce */
	//WriteRegValue((REG845X_FF_MT_COUNT) , 0, 8 , pChip->fm_debounce_count);

	//i2c_smbus_write_byte_data(pClient, (REG845X_CTRL_REG4), 0x04);

	return 0;
}

/*!
* This method is used to set initialize Tap detection module in MMA845X chip with default settings.
* pChipInfo  : Chip structure of MMA845x.
* return 0 	      : For successful chip initialization, -EINVAL : For failure
*/

static int Drv_MMA845x_nitTapDetectionModule(MMA845x_HandleTypeDef *hMMA845x)
{
	/* Set pulse detection configuration */
	//bool latch;
//	WriteRegValue((REG845X_PULSE_CFG) , 0, 6 , pChip->tap_enable);  				// X Y Enable
	//	latch = ((pChip->tap_enable > 0 )? 1 : 0);
	//	WriteRegValue((REG845X_PULSE_CFG) , 6, 1 , latch);  						//0x7F

	/* Set thresholds */
	//WriteRegValue((REG845X_PULSE_THSX) , 0, 7 , pChip->tap_threshold_x); 				//0x20

	//WriteRegValue((REG845X_PULSE_THSY) , 0, 7 , pChip->tap_threshold_y); 				//0x20

	//WriteRegValue((REG845X_PULSE_THSZ) , 0, 7 , pChip->tap_threshold_z);				//0x40

	/* Set time limit */
	//WriteRegValue((REG845X_PULSE_TMLT) , 0, 8 , pChip->pulse_time_limit); 				// 0x0

	//WriteRegValue((REG845X_PULSE_LTCY) , 0, 8 , pChip->pulse_latency_time);				//0x0

	//	WriteRegValue((REG845X_PULSE_WIND) , 0, 8 , pChip->pulse_window_time);				//0x0

	//i2c_smbus_write_byte_data(pClient, (REG845X_CTRL_REG4), 0x08);

	return 0;
}
/*!
* This method is used to set initialize Transient module in MMA845X chip with default settings.
* pChipInfo  : Chip structure of MMA845x.
* return 0 	      : For successful chip initialization, -EINVAL : For failure
*/

static int Drv_MMA845x_InitTransientDetectionModule(MMA845x_HandleTypeDef *hMMA845x)
{
	/* Set thresholds */
	//bool latch;
	//WriteRegValue((REG845X_TRANSIENT_CFG) , 1, 3 , pChip->trans_enable);  				// X Y Enable
	//latch = ((pChip->trans_enable > 0 )? 1 : 0);
	//WriteRegValue((REG845X_TRANSIENT_CFG) , 4, 1 , latch);						//0x16

	//WriteRegValue((REG845X_TRANSIENT_THS) , 0, 7 , pChip->trans_threshold);  			//0x10

	//WriteRegValue((REG845X_TRANSIENT_COUNT) , 0, 8 , pChip->trans_debounce_count); 			//0xA

	//i2c_smbus_write_byte_data(pClient, (REG845X_CTRL_REG4), 0x20);

	return 0;
}



Std_ReturnType Drv_MMA845x_MainFunction(MMA845x_HandleTypeDef *hMMA845x) {
	// Pooling Mode
	/*
	 ** Poll the ZYXDR status bit and wait for it to set.
	 */
	if (Drv_MMA845x_UpdateStatus(hMMA845x) == E_NOT_OK) {
		return (E_NOT_OK);
	}

	if (hMMA845x->Status.ZYXOW == 1) {

		/*
		 ** Read 14/12/10-bit XYZ results using a 6 byte IIC access.
		 */
		if (Drv_MMA845x_GetXYZ(hMMA845x) == E_OK) {
			// Process the data
			Drv_MMA845x_RxXYZCpltCallback(hMMA845x);

			return (E_OK);
		} else {
			return (E_NOT_OK);
		}
	}
	return (E_OK);
}

void Drv_MMA845x_MainFunction_IT(MMA845x_HandleTypeDef *hMMA845x) {
	// Interrupt Mode

	//Drv_MMA845x_UpdateInterruptSource(hMMA845x)

}



/**
 * @brief Rx XYZ data completed callback.
 * @param handle MMA845x handle.
 * @retval None
 */
__attribute__((weak)) void Drv_MMA845x_RxXYZCpltCallback(
		MMA845x_HandleTypeDef *handle) {
}

__attribute__((weak)) void Drv_MMA845x_Int1Callback(
		MMA845x_HandleTypeDef *handle) {
}

__attribute__((weak)) void Drv_MMA845x_Int2Callback(
		MMA845x_HandleTypeDef *handle) {
}

Std_ReturnType Drv_MMA845x_DeInit(MMA845x_HandleTypeDef *hMMA845x) {

	Drv_MMA845x_EnableStandbyMode(hMMA845x);
	return (E_OK);
}
/* local Functions -----------------------------------------------------------*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/**
 * @}
 */
