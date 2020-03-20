/*
 *******************************************************************************
 * @file		: Drv_MMA845x_Prv.c
 * @Created on	: Jan 3, 2018
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

/** @addtogroup Driver_MMA845x
 * @{
 */

/* * * * * * * * * * * * * * *  Module Declarations * * * * * * * * * * * * * */

/* Includes ------------------------------------------------------------------*/
#include <drv_mma845x.h>
#include <drv_mma845x_prv.h>
#include <drv_mma845x_cfg.h>
/* Global function prototypes ------------------------------------------------*/

/* Local function prototypes -------------------------------------------------*/

Std_ReturnType Drv_MMA845x_WriteReg(MMA845x_HandleTypeDef *hMMA845x,
		uint8_t RegisterAddress, const uint8_t * RegisterValue);

Std_ReturnType Drv_MMA845x_ReadReg(MMA845x_HandleTypeDef *hMMA845x,
		uint8_t RegisterAddress, const uint8_t * RegisterValue);

Std_ReturnType Drv_MMA845x_CalulateXYZ(MMA845x_HandleTypeDef *hMMA845x);
/* Local Types & enums  ------------------------------------------------------*/

/* Local Defines & Macros ----------------------------------------------------*/

/* Local variables  ----------------------------------------------------------*/

/* Global variables ----------------------------------------------------------*/

/* * * * * * * * * * * * * * * Module Functions * * * * * * * * * * * * * * * */

/* Global Functions ----------------------------------------------------------*/

/* Status Register */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_UpdateStatus(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_STATUS, (uint8_t *) &rxbuf)
			== E_OK) {

		hMMA845x->Registers.STATUS = rxbuf;
		// Update Status Structure
		hMMA845x->Status.ZYXOW = GET_REG_STATUS_ZYXOW(
				hMMA845x->Registers.STATUS);
		hMMA845x->Status.ZOW = GET_REG_STATUS_ZOW(hMMA845x->Registers.STATUS);
		hMMA845x->Status.YOW = GET_REG_STATUS_YOW(hMMA845x->Registers.STATUS);
		hMMA845x->Status.XOW = GET_REG_STATUS_XOW(hMMA845x->Registers.STATUS);
		hMMA845x->Status.ZYXDR = GET_REG_STATUS_ZYXDR(
				hMMA845x->Registers.STATUS);
		hMMA845x->Status.ZDR = GET_REG_STATUS_ZDR(hMMA845x->Registers.STATUS);
		hMMA845x->Status.YDR = GET_REG_STATUS_YDR(hMMA845x->Registers.STATUS);
		hMMA845x->Status.XDR = GET_REG_STATUS_XDR(hMMA845x->Registers.STATUS);

		return (E_OK);
	}
	return (E_NOT_OK);
}

/* Registers OUT_X, OUT_Y , OUT_Z*/

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_GetXYZ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_X_MSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_X_MSB = rxbuf;
	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_X_LSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_X_LSB = rxbuf;
	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_Y_MSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_Y_MSB = rxbuf;
	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_Y_LSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_Y_LSB = rxbuf;
	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_Z_MSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_Z_MSB = rxbuf;
	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_OUT_Z_LSB, (uint8_t *) &rxbuf)
			!= E_OK) {
		return (E_NOT_OK);
	}
	hMMA845x->Registers.OUT_Z_LSB = rxbuf;
	Drv_MMA845x_CalulateXYZ(hMMA845x);
	return (E_OK);
}


float u8tofloat(uint8_t x)
{
    union { float f; uint32_t i; } u; u.f = 32768.0f; u.i |= x;
    return u.f - 32768.0f;
}


Std_ReturnType Drv_MMA845x_CalulateXYZ(MMA845x_HandleTypeDef *hMMA845x) {

	 union { float f; uint32_t i; } uToFloat32;

	hMMA845x->Data.x = CONVERT_TO_U16(hMMA845x->Registers.OUT_X_MSB,
			hMMA845x->Registers.OUT_X_LSB);
	hMMA845x->Data.y = CONVERT_TO_U16(hMMA845x->Registers.OUT_Y_MSB,
			hMMA845x->Registers.OUT_Y_LSB);

	hMMA845x->Data.z = CONVERT_TO_U16(hMMA845x->Registers.OUT_Z_MSB,
			hMMA845x->Registers.OUT_Z_LSB);

	if (hMMA845x->Registers.OUT_X_MSB > 0x7F) {
		hMMA845x->Data.x &= 0xFFFC;
		hMMA845x->Data.x = ~hMMA845x->Data.x + 1;
	}
	if (hMMA845x->Registers.OUT_Y_MSB > 0x7F) {
		hMMA845x->Data.x &= 0xFFFC;
		hMMA845x->Data.y = ~hMMA845x->Data.y + 1;
	}
	if (hMMA845x->Registers.OUT_Z_MSB > 0x7F) {
		hMMA845x->Data.x &= 0xFFFC;
		hMMA845x->Data.z = ~hMMA845x->Data.z + 1;
	}
	/* Convertion to the Fraction in g */

	//MMA8452Q
	// 1. 12-bit data
	// 2g (1024 counts/g = 1 mg/LSB) 4g (512 counts/g = 2 mg /LSB) 8g (256 counts/g = 3.9 mg/LSB)

	switch (hMMA845x->Init.DynamicRange) {
	case HAL_MMA845x_FULL_SCALE_2G:

		hMMA845x->Data.gx = ((hMMA845x->Registers.OUT_X_MSB & 0x20) >> 5);
		hMMA845x->Data.gx = (float) hMMA845x->Data.x/ 1024.0;
		hMMA845x->Data.gy = ((hMMA845x->Registers.OUT_Y_MSB & 0x20) >> 5);
		hMMA845x->Data.gy = (float) hMMA845x->Data.y/ 1024.0;
		hMMA845x->Data.gz = ((hMMA845x->Registers.OUT_Z_MSB & 0x20) >> 5);
		hMMA845x->Data.gz = (float) hMMA845x->Data.z/ 1024.0;
		break;

	case HAL_MMA845x_FULL_SCALE_4G:
		hMMA845x->Data.gx = ((hMMA845x->Registers.OUT_X_MSB & 0x30) >> 4);
		hMMA845x->Data.gx = (float) hMMA845x->Data.x/ 512.0;
		hMMA845x->Data.gy = ((hMMA845x->Registers.OUT_Y_MSB & 0x30) >> 4);
		hMMA845x->Data.gy = (float) hMMA845x->Data.y/ 512.0;
		hMMA845x->Data.gz = ((hMMA845x->Registers.OUT_Z_MSB & 0x30) >> 4);
		hMMA845x->Data.gz = (float) hMMA845x->Data.z/ 512.0;
		break;

	case HAL_MMA845x_FULL_SCALE_8G:
		hMMA845x->Data.gx = ((hMMA845x->Registers.OUT_X_MSB & 0x38) >> 3);
		hMMA845x->Data.gx = (float) hMMA845x->Data.x/ 256.0;
		hMMA845x->Data.gy = ((hMMA845x->Registers.OUT_Y_MSB & 0x38) >> 3);
		hMMA845x->Data.gy = (float) hMMA845x->Data.y/ 256.0;
		hMMA845x->Data.gz = ((hMMA845x->Registers.OUT_Z_MSB & 0x38) >> 3);
		hMMA845x->Data.gz = (float) hMMA845x->Data.z/ 256.0;
		break;
	}

	return (E_OK);
}

/* INT_SOURCE(1)(2) register */
Std_ReturnType Drv_MMA845x_UpdateInterruptSource(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_STATUS, (uint8_t *) &rxbuf)
			== E_OK) {

		hMMA845x->Registers.INT_SOURCE = rxbuf;

		// Update Status Structure
		hMMA845x->IntSrc.SRC_ASLP = GET_REG_INT_SOURCE_SRC_ASLP(
				hMMA845x->Registers.INT_SOURCE);
		hMMA845x->IntSrc.SRC_TRANS = GET_REG_INT_SOURCE_SRC_TRANS(
				hMMA845x->Registers.INT_SOURCE);
		hMMA845x->IntSrc.SRC_PULSE = GET_REG_INT_SOURCE_SRC_PULSE(
				hMMA845x->Registers.INT_SOURCE);
		hMMA845x->IntSrc.SRC_LNDPRT = GET_REG_INT_SOURCE_SRC_LNDPRT(
				hMMA845x->Registers.INT_SOURCE);
		hMMA845x->IntSrc.SRC_FF_MT = GET_REG_INT_SOURCE_SRC_FF_MT_2(
				hMMA845x->Registers.INT_SOURCE);
		hMMA845x->IntSrc.SRC_DRDY = GET_REG_INT_SOURCE_SRC_DRDY(
				hMMA845x->Registers.INT_SOURCE);

		return (E_OK);
	}
	return (E_NOT_OK);
}

/* WHO_AM_I register */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_GetDeviceID(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_WHO_AM_I, (uint8_t *) &rxbuf) == E_OK) {

	    hMMA845x->Registers.WHO_AM_I = rxbuf;

	    // Update Status Structure
		hMMA845x->DeviceID = hMMA845x->Registers.WHO_AM_I;

		return (E_OK);
	}
	return (E_NOT_OK);
}

/* SYSMOD Status */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_UpdateSystemMode(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set

	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_SYSMOD, (uint8_t *) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.SYSMOD = rxbuf;
		switch (hMMA845x->Registers.SYSMOD) {
		case HAL_MMA845x_STATE_STANDBY:
			hMMA845x->State = HAL_MMA845x_STATE_STANDBY;
			break;
		case HAL_MMA845x_STATE_WAKE:
			hMMA845x->State = HAL_MMA845x_STATE_WAKE;
			break;
		case HAL_MMA845x_STATE_SLEEP:
			hMMA845x->State = HAL_MMA845x_STATE_SLEEP;
			break;
		default:
			return (E_NOT_OK);
		}
	}

	return (E_NOT_OK);
}

/* XYZ_DATA_CFG Register */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetDynamicRange(MMA845x_HandleTypeDef *hMMA845x,
		MMA845x_DynamicRange_TypeDef DynamicRange) {
	uint8_t rxbuf;
// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
			(uint8_t*) &rxbuf) == E_OK) {
		hMMA845x->Registers.XYZ_DATA_CFG = rxbuf;
		switch (DynamicRange) {
		case HAL_MMA845x_FULL_SCALE_2G:
			CLR_REG_XYZ_DATA_CFG_FS0(hMMA845x->Registers.XYZ_DATA_CFG);
			CLR_REG_XYZ_DATA_CFG_FS1(hMMA845x->Registers.XYZ_DATA_CFG);

			break;
		case HAL_MMA845x_FULL_SCALE_4G:
			SET_REG_XYZ_DATA_CFG_FS0(hMMA845x->Registers.XYZ_DATA_CFG);
			CLR_REG_XYZ_DATA_CFG_FS1(hMMA845x->Registers.XYZ_DATA_CFG);
			break;
		case HAL_MMA845x_FULL_SCALE_8G:
			CLR_REG_XYZ_DATA_CFG_FS0(hMMA845x->Registers.XYZ_DATA_CFG);
			SET_REG_XYZ_DATA_CFG_FS1(hMMA845x->Registers.XYZ_DATA_CFG);
			break;
		default:
			return (E_NOT_OK);
			break;
		}

		// Enable standby mode
		Drv_MMA845x_EnableStandbyMode(hMMA845x);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
				&hMMA845x->Registers.XYZ_DATA_CFG) == E_OK) {
			return (E_OK);
		}

	}
	return (E_NOT_OK);

}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableHPF(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
			(uint8_t*) &rxbuf) == E_OK) {
		hMMA845x->Registers.XYZ_DATA_CFG = rxbuf;
		// Update the register
		SET_REG_XYZ_DATA_CFG_HPF_OUT(hMMA845x->Registers.XYZ_DATA_CFG);

		// Enable standby mode
		Drv_MMA845x_EnableStandbyMode(hMMA845x);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
				&hMMA845x->Registers.XYZ_DATA_CFG) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);

}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableHPF(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;

// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
			(uint8_t*) &rxbuf) == E_OK) {
		hMMA845x->Registers.XYZ_DATA_CFG = rxbuf;
		// Update the register
		CLR_REG_XYZ_DATA_CFG_HPF_OUT(hMMA845x->Registers.XYZ_DATA_CFG);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_XYZ_DATA_CFG,
				&hMMA845x->Registers.XYZ_DATA_CFG) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* Control Register 1 */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableFastreadMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG1_FREAD(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableFastreadMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG1_FREAD(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableActiveMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG1_ACTIVE(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableStandbyMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG1_ACTIVE(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {

			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableLowNoiseMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG1_LNOISE(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableLowNoiseMode(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG1_LNOISE(hMMA845x->Registers.CTRL_REG1);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetDataRate(MMA845x_HandleTypeDef *hMMA845x,
		MMA845x_ODR_TypeDef OutputDataRate) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		switch (OutputDataRate) {

		case HAL_MMA845x_DATA_RATE_800Hz:
			CLR_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);
			break;
		case HAL_MMA845x_DATA_RATE_400Hz:
			SET_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);
			break;
		case HAL_MMA845x_DATA_RATE_200Hz:
			CLR_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_DATA_RATE_100Hz:
			SET_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_DATA_RATE_50Hz:
			CLR_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_DATA_RATE_12_5Hz:
			SET_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_DATA_RATE_6_25Hz:
			CLR_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);
			break;
		case HAL_MMA845x_DATA_RATE_1_56Hz:
			SET_REG_CTRL_REG1_DR0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR1(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_DR2(hMMA845x->Registers.CTRL_REG1);
			break;
		}

		// Set the device in Stadby mode
		Drv_MMA845x_EnableStandbyMode(hMMA845x);
		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetAutoSleepRate(MMA845x_HandleTypeDef *hMMA845x,
		MMA845x_ASLPR_TypeDef AutoSleepRate) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}
	// Set the device in Stadby mode
	Drv_MMA845x_EnableStandbyMode(hMMA845x);

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG1, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG1 = rxbuf;
		// Update the register
		switch (AutoSleepRate) {

		case HAL_MMA845x_ASLP_RATE_50Hz:
			CLR_REG_CTRL_REG1_ASLP_RATE0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_ASLP_RATE1(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_ASLP_RATE_12_5Hz:
			SET_REG_CTRL_REG1_ASLP_RATE0(hMMA845x->Registers.CTRL_REG1);
			CLR_REG_CTRL_REG1_ASLP_RATE1(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_ASLP_RATE_6_25Hz:
			CLR_REG_CTRL_REG1_ASLP_RATE0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_ASLP_RATE1(hMMA845x->Registers.CTRL_REG1);

			break;
		case HAL_MMA845x_ASLP_RATE_1_56Hz:
			SET_REG_CTRL_REG1_ASLP_RATE0(hMMA845x->Registers.CTRL_REG1);
			SET_REG_CTRL_REG1_ASLP_RATE1(hMMA845x->Registers.CTRL_REG1);
			break;
		}

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG1,
				&hMMA845x->Registers.CTRL_REG1) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* Control Register 2 */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableSelfTest(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}
	// Set the device in Stadby mode
	Drv_MMA845x_EnableStandbyMode(hMMA845x);

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG2_ST(hMMA845x->Registers.CTRL_REG2);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableSelfTest(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG2_ST(hMMA845x->Registers.CTRL_REG2);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SoftReset(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG2_RST(hMMA845x->Registers.CTRL_REG2);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableAutoSleep(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG2_SLPE(hMMA845x->Registers.CTRL_REG2);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableAutoSleep(MMA845x_HandleTypeDef *hMMA845x) {

	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG2_SLPE(hMMA845x->Registers.CTRL_REG2);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetActiveModePowerScheme(
		MMA845x_HandleTypeDef *hMMA845x, MMA845x_OVSM_TypeDef OverSamplingMode) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		switch (OverSamplingMode) {
		case HAL_MMA845x_OVSM_MODE_NORMAL:
			CLR_REG_CTRL_REG2_SMODS0(hMMA845x->Registers.CTRL_REG2);
			CLR_REG_CTRL_REG2_SMODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_LOW_NOISE_LOW_POWER:
			SET_REG_CTRL_REG2_SMODS0(hMMA845x->Registers.CTRL_REG2);
			CLR_REG_CTRL_REG2_SMODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_HIGH_RESOLUTION:
			CLR_REG_CTRL_REG2_SMODS0(hMMA845x->Registers.CTRL_REG2);
			SET_REG_CTRL_REG2_SMODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_MODE_LOW_POWER:
			SET_REG_CTRL_REG2_SMODS0(hMMA845x->Registers.CTRL_REG2);
			SET_REG_CTRL_REG2_SMODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		default:
			return (E_NOT_OK);
			break;
		}

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetSleepModePowerScheme(
		MMA845x_HandleTypeDef *hMMA845x, MMA845x_OVSM_TypeDef OverSamplingMode) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG2, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG2 = rxbuf;
		switch (OverSamplingMode) {
		case HAL_MMA845x_OVSM_MODE_NORMAL:
			CLR_REG_CTRL_REG2_MODS0(hMMA845x->Registers.CTRL_REG2);
			CLR_REG_CTRL_REG2_MODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_LOW_NOISE_LOW_POWER:
			SET_REG_CTRL_REG2_MODS0(hMMA845x->Registers.CTRL_REG2);
			CLR_REG_CTRL_REG2_MODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_HIGH_RESOLUTION:
			CLR_REG_CTRL_REG2_MODS0(hMMA845x->Registers.CTRL_REG2);
			SET_REG_CTRL_REG2_MODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		case HAL_MMA845x_OVSM_MODE_LOW_POWER:
			SET_REG_CTRL_REG2_MODS0(hMMA845x->Registers.CTRL_REG2);
			SET_REG_CTRL_REG2_MODS1(hMMA845x->Registers.CTRL_REG2);
			break;
		default:
			return (E_NOT_OK);
			break;
		}

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG2,
				&hMMA845x->Registers.CTRL_REG2) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* Control Register 3 */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableIRQTransientWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_WAKE_TRANS(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableIRQTransientWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_WAKE_TRANS(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableIRQOrientationWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_WAKE_LNDPRT(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableIRQOrientationWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_WAKE_LNDPRT(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableIRQPulseWakeUp(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_WAKE_PULSE(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableIRQPulseWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_WAKE_PULSE(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableIRQFreeFallMotionWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_WAKE_FF_MT_2(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableIRQFreeFallMotionWakeUp(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_WAKE_FF_MT_2(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetIRQPolarityActivehigh(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_IPOL(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetIRQPolariyActiveLow(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_IPOL(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetIRQOpenDrain(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG3_PP_OD(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_SetIRQPushPull(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG3, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG3 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG3_PP_OD(hMMA845x->Registers.CTRL_REG3);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG3,
				&hMMA845x->Registers.CTRL_REG3) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* Control Register 4 */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableAutoSleepWakeUpIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG4_INT_EN_ASLP(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableAutoSleepWakeUpIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_ASLP(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableTransientIRQ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG4_INT_EN_TRANS(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableTransientIRQ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_TRANS(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableOrientationIRQ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG4_INT_EN_LNDPRT(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableOrientationIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_LNDPRT(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnablePulseDetectionIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG4_INT_EN_PULSE(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisablePulseDetectionIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_PULSE(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableDataReadyIRQ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		SET_REG_CTRL_REG4_INT_EN_DRDY(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableDataReadyIRQ(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;
		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_DRDY(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_EnableFreefallMotionIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG4_INT_EN_FF_MT_2(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_DisableFreefallMotionIRQ(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG4, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG4 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG4_INT_EN_FF_MT_2(hMMA845x->Registers.CTRL_REG4);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG4,
				&hMMA845x->Registers.CTRL_REG4) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* Control Register 5 */

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteAutoSleepIRQInt1(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_ASLP(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteAutoSleepIRQInt2(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_ASLP(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteTransientIRQInt1(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_TRANS(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteTransientIRQInt2(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_TRANS(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteOrientationIRQInt1(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;
		s
		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_LNDPRT(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteOrientationIRQInt2(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_LNDPRT(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RoutePulseIRQInt1(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_PULSE(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RoutePulseIRQInt2(MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_PULSE(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteFreefallMotionIRQInt1(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_FF_MT_2(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteFreefallMotionIRQInt2(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_FF_MT_2(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteDataReadyIRQInt1(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		SET_REG_CTRL_REG5_INT_CFG_DRDY(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_RouteDataReadyIRQInt2(
		MMA845x_HandleTypeDef *hMMA845x) {
	uint8_t rxbuf;
	// Check if the handle is set
	if (hMMA845x == 0) {
		return (E_NOT_OK);
	}

	// Read the register From the device
	if (Drv_MMA845x_ReadReg(hMMA845x, REG_MMA845x_CTRL_REG5, (uint8_t*) &rxbuf)
			== E_OK) {
		hMMA845x->Registers.CTRL_REG5 = rxbuf;

		// Update the register
		CLR_REG_CTRL_REG5_INT_CFG_DRDY(hMMA845x->Registers.CTRL_REG5);

		// Write the updated register to the device
		if (Drv_MMA845x_WriteReg(hMMA845x, REG_MMA845x_CTRL_REG5,
				&hMMA845x->Registers.CTRL_REG5) == E_OK) {
			return (E_OK);
		}
	}
	return (E_NOT_OK);
}

/* local Functions -----------------------------------------------------------*/

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @param RegisterAddress device register address
 * @param RegisterValue pointer to the register value
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_ReadReg(MMA845x_HandleTypeDef *hMMA845x,
		uint8_t RegisterAddress, const uint8_t * RegisterValue) {

	uint16_t DeviceAddr_ReadOP = (uint16_t) ((hMMA845x->Instance) |= (1UL << (0U)));

	uint8_t * val = (uint8_t *) RegisterValue;
	/* Check the hMMA845x handle allocation */
	if (hMMA845x == 0L) {
		return E_NOT_OK;
	}

	if (HAL_I2C_Mem_Read(&hi2c1, DeviceAddr_ReadOP, RegisterAddress, 1, val, 1, 100) != HAL_OK) {
		return (E_NOT_OK);
	}
	return (E_OK);
}

/**
 * @brief Description of the function
 * @param hMMA845x Pointer to the Handling structure.
 * @retval E_OK if the Operation is Successful, E_NOT_OK otherwise
 */
Std_ReturnType Drv_MMA845x_WriteReg(MMA845x_HandleTypeDef *hMMA845x,
		uint8_t RegisterAddress, const uint8_t * RegisterValue) {

	uint16_t DeviceAddr_WriteOP = (uint16_t) ((hMMA845x->Instance) &= ~(1UL<< (0U)));
	uint8_t * val = (uint8_t *) RegisterValue;
	/* Check the hMMA845x handle allocation */
	if (hMMA845x == 0L) {
		return E_NOT_OK;
	}

	if (HAL_I2C_Mem_Write(&hi2c1, DeviceAddr_WriteOP, RegisterAddress, 1, val, 1, 1000) != HAL_OK) {
		return (E_NOT_OK);
	}

	return (E_OK);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/**
 * @}
 */
