/*
 *******************************************************************************
 * @file		: Drv_MMA845xQ_Prv.h
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

#ifndef MMA845X_INC_DRV_MMA845X_PRV_H_
#define MMA845X_INC_DRV_MMA845X_PRV_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup GroupName
 * @{
 */

/* * * * * * * * * * * * * * *  Module Declarations * * * * * * * * * * * * * */

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "drv_mma845x.h"
#include "drv_mma845x_cfg.h"
/* Global function prototypes ------------------------------------------------*/

/* Global Types & enums  -----------------------------------------------------*/
enum {
	REG_MMA845x_STATUS 		= 0x00,
	REG_MMA845x_OUT_X_MSB= 0x01,
	REG_MMA845x_OUT_X_LSB= 0x02,
	REG_MMA845x_OUT_Y_MSB= 0x03,
	REG_MMA845x_OUT_Y_LSB= 0x04,
	REG_MMA845x_OUT_Z_MSB= 0x05,
	REG_MMA845x_OUT_Z_LSB= 0x06,
	REG_MMA845x_F_STATUS= 0x08,
	REG_MMA845x_F_SETUP= 0x09,
	REG_MMA845x_TRIG_CFG= 0x0A,
	REG_MMA845x_SYSMOD= 0x0B,
	REG_MMA845x_INT_SOURCE= 0x0C,
	REG_MMA845x_WHO_AM_I= 0x0D,
	REG_MMA845x_XYZ_DATA_CFG= 0x0E,
	REG_MMA845x_HP_FILTER_CUTOFF= 0x0F,
	REG_MMA845x_PL_STATUS= 0x10,
	REG_MMA845x_PL_CFG= 0x11,
	REG_MMA845x_PL_COUNT= 0x12,
	REG_MMA845x_PL_BF_ZCOMP= 0x13,
	REG_MMA845x_FF_MT_CFG = 0x15,
	REG_MMA845x_FF_MT_SRC= 0x16,
	REG_MMA845x_FF_MT_THS= 0x17,
	REG_MMA845x_FF_MT_COUNT= 0x18,
	REG_MMA845x_TRANSIENT_CFG= 0x1D,
	REG_MMA845x_TRANSIENT_SRC= 0x1E,
	REG_MMA845x_TRANSIENT_THS=  0x1F,
	REG_MMA845x_TRANSIENT_COUNT= 0x20,
	REG_MMA845x_PULSE_CFG=  0x21,
	REG_MMA845x_PULSE_SRC= 0x22,
	REG_MMA845x_PULSE_THSX=  0x23,
	REG_MMA845x_PULSE_THSY= 0x24,
	REG_MMA845x_PULSE_THSZ= 0x25,
	REG_MMA845x_PULSE_TMLT= 0x26,
	REG_MMA845x_PULSE_LTCY= 0x27,
	REG_MMA845x_PULSE_WIND= 0x28,
	REG_MMA845x_ASLP_COUNT= 0x29,
	REG_MMA845x_CTRL_REG1=  0x2A,
	REG_MMA845x_CTRL_REG2 = 0x2B,
	REG_MMA845x_CTRL_REG3=  0x2C,
	REG_MMA845x_CTRL_REG4= 0x2D,
	REG_MMA845x_CTRL_REG5= 0x2E,
	REG_MMA845x_OFF_X= 0x2F,
	REG_MMA845x_OFF_Y= 0x30,
	REG_MMA845x_OFF_Z=0x31

};

/* Global Defines & Macros ---------------------------------------------------*/

/*
 ** [0x00] STATUS Registers (Read Only)
 */
// Status Register Flags
#define REG_STATUS_ZYXOW_BIT             (7) 	// 1000 0000
#define REG_STATUS_ZOW_BIT               (6) 	// 0100 0000
#define REG_STATUS_YOW_BIT               (5) 	// 0010 0000
#define REG_STATUS_XOW_BIT               (4) 	// 0001 0000
#define REG_STATUS_ZYXDR_BIT             (3) 	// 0000 1000
#define REG_STATUS_ZDR_BIT               (2) 	// 0000 0100
#define REG_STATUS_YDR_BIT               (1) 	// 0000 0010
#define REG_STATUS_XDR_BIT               (0) 	// 0000 0001
// Register Bit Masks
#define REG_STATUS_ZYXOW_MASK            (0x80)		// 1000 0000
#define REG_STATUS_ZOW_MASK              (0x40)		// 0100 0000
#define REG_STATUS_YOW_MASK              (0x20)		// 0100 0000
#define REG_STATUS_XOW_MASK              (0x10)		// 0001 0000
#define REG_STATUS_ZYXDR_MASK            (0x08)		// 0000 1000
#define REG_STATUS_ZDR_MASK              (0x04)		// 0000 0100
#define REG_STATUS_YDR_MASK              (0x02)		// 0000 0010
#define REG_STATUS_XDR_MASK              (0x01)		// 0000 0001
// Read Macros
#define GET_REG_STATUS_ZYXOW(REG)		 (((REG) >> REG_STATUS_ZYXOW_BIT)	& 0x01)
#define GET_REG_STATUS_ZOW(REG) 		 (((REG) >> REG_STATUS_ZOW_BIT)		& 0x01)
#define GET_REG_STATUS_YOW(REG) 		 (((REG) >> REG_STATUS_YOW_BIT) 	& 0x01)
#define GET_REG_STATUS_XOW(REG) 		 (((REG) >> REG_STATUS_XOW_BIT) 	& 0x01)
#define GET_REG_STATUS_ZYXDR(REG)		 (((REG) >> REG_STATUS_ZYXDR_BIT)	& 0x01)
#define GET_REG_STATUS_ZDR(REG) 		 (((REG) >> REG_STATUS_ZDR_BIT) 	& 0x01)
#define GET_REG_STATUS_YDR(REG)		 	 (((REG) >> REG_STATUS_YDR_BIT) 	& 0x01)
#define GET_REG_STATUS_XDR(REG) 		 (((REG) >> REG_STATUS_XDR_BIT) 	& 0x01)

/*
 ** [0x01 - 0x06] XYZ Data Registers (Read Only)
 */
#define REG_OUT_X_MSB         			(0x01)
#define REG_OUT_X_LSB         			(0x02)
#define REG_OUT_Y_MSB         			(0x03)
#define REG_OUT_Y_LSB         			(0x04)
#define REG_OUT_Z_MSB         			(0x05)
#define REG_OUT_Z_LSB         			(0x06)

/*
 ** [0x07] WHO_AM_I Device ID Register
 */
#define REG_WHO_AM_I_MMA8451Q_ID        (0x1A)
#define REG_WHO_AM_I_MMA8452Q_ID        (0x2A)
#define REG_WHO_AM_I_MMA8453Q_ID        (0x3A)

/*
 **  F_STATUS FIFO Status Register
 */
// Register Flags
#define REG_F_STATUS_F_OVF_BIT          (7) // 1000 0000
#define REG_F_STATUS_F_WMRK_FLAG_BIT    (6) // 0100 0000
#define REG_F_STATUS_F_CNT5_BIT         (5) // 0010 0000
#define REG_F_STATUS_F_CNT4_BIT         (4) // 0001 0000
#define REG_F_STATUS_F_CNT3_BIT         (3) // 0000 1000
#define REG_F_STATUS_F_CNT2_BIT         (2) // 0000 0100
#define REG_F_STATUS_F_CNT1_BIT         (1) // 0000 0010
#define REG_F_STATUS_F_CNT0_BIT         (0) // 0000 0001
// Register Bit Masks
#define REG_F_STATUS_F_OVF_MASK         (0x80)
#define REG_F_STATUS_F_WMRK_FLAG_MASK   (0x40)
#define REG_F_STATUS_F_CNT5_MASK        (0x20)
#define REG_F_STATUS_F_CNT4_MASK        (0x10)
#define REG_F_STATUS_F_CNT3_MASK        (0x08)
#define REG_F_STATUS_F_CNT2_MASK        (0x04)
#define REG_F_STATUS_F_CNT1_MASK        (0x02)
#define REG_F_STATUS_F_CNT0_MASK        (0x01)
#define REG_F_STATUS_F_CNT_MASK         (0x3F)

/*
 **  F_SETUP FIFO Setup Register
 */
// Register flags
#define REG_F_SETUP_F_MODE1_BIT           (7) // 1000 0000
#define REG_F_SETUP_F_MODE0_BIT           (6) // 0100 0000
#define REG_F_SETUP_F_WMRK5_BIT           (5) // 0010 0000
#define REG_F_SETUP_F_WMRK4_BIT           (4) // 0001 0000
#define REG_F_SETUP_F_WMRK3_BIT           (3) // 0000 1000
#define REG_F_SETUP_F_WMRK2_BIT           (2) // 0000 0100
#define REG_F_SETUP_F_WMRK1_BIT           (1) // 0000 0010
#define REG_F_SETUP_F_WMRK0_BIT           (0) // 0000 0001
// Register Bit Masks
#define REG_F_SETUP_F_MODE1_MASK          (0x80)
#define REG_F_SETUP_F_MODE0_MASK          (0x40)
#define REG_F_SETUP_F_WMRK5_MASK          (0x20)
#define REG_F_SETUP_F_WMRK4_MASK          (0x10)
#define REG_F_SETUP_F_WMRK3_MASK          (0x08)
#define REG_F_SETUP_F_WMRK2_MASK          (0x04)
#define REG_F_SETUP_F_WMRK1_MASK          (0x02)
#define REG_F_SETUP_F_WMRK0_MASK          (0x01)
#define REG_F_SETUP_F_MODE_MASK           (0xC0)
#define REG_F_SETUP_F_WMRK_MASK           (0x3F)

/*
 ** TRIG CFG Register
 */
// Register flags
#define REG_TRIG_CFG_TRANS_BIT      	 (5) // 0010 0000
#define REG_TRIG_CFG_LNDPRT_BIT     	 (4) // 0001 0000
#define REG_TRIG_CFG_PULSE_BIT      	 (3) // 0000 1000
#define REG_TRIG_CFG_FF_MT_BIT      	 (2) // 0000 0100
//  Register Bit Masks
#define REG_TRIG_CFG_TRANS_MASK     	 (0x20)
#define REG_TRIG_CFG_LNDPRT_MASK    	 (0x10)
#define REG_TRIG_CFG_PULSE_MASK     	 (0x08)
#define REG_TRIG_CFG_FF_MT_MASK     	 (0x04)

/*
 **  SYSMOD System Mode Register
 */
// Register flags
#define REG_SYSMOD_FGERR_BIT             (7) // 1000 0000
#define REG_SYSMOD_FGT_4_BIT             (6) // 0100 0000
#define REG_SYSMOD_FGT_3_BIT             (5) // 0010 0000
#define REG_SYSMOD_FGT_2_BIT             (4) // 0001 0000
#define REG_SYSMOD_FGT_1_BIT             (3) // 0000 1000
#define REG_SYSMOD_FGT_0_BIT             (2) // 0000 0100
#define REG_SYSMOD_SYSMOD1_BIT           (1) // 0000 0010
#define REG_SYSMOD_SYSMOD0_BIT           (0) // 0000 0001
// Register bit masks
#define REG_SYSMOD_FGERR_MASK            (0x80)
#define REG_SYSMOD_FGT_4MASK             (0x40)
#define REG_SYSMOD_FGT_3MASK             (0x20)
#define REG_SYSMOD_FGT_2MASK             (0x10)
#define REG_SYSMOD_FGT_1MASK             (0x08)
#define REG_SYSMOD_FGT_0MASK             (0x04)
#define REG_SYSMOD_FGT_MASK              (0x7C)
#define REG_SYSMOD_SYSMOD1_MASK          (0x02)
#define REG_SYSMOD_SYSMOD0_MASK          (0x01)
#define REG_SYSMOD_SYSMOD_MASK           (0x03)
// Read Macros
#define GET_REG_SYSMOD_SYSMOD(REG)	 (((REG) >> REG_SYSMOD_SYSMOD_MASK) 	& 0x01)

/*
 **  INT_SOURCE System Interrupt Status Register
 */
// Register flags
#define REG_INT_SOURCE_SRC_ASLP_BIT      (7) // 1000 0000
#define REG_INT_SOURCE_SRC_FIFO_BIT      (6) // 0100 0000
#define REG_INT_SOURCE_SRC_TRANS_BIT     (5) // 0010 0000
#define REG_INT_SOURCE_SRC_LNDPRT_BIT    (4) // 0001 0000
#define REG_INT_SOURCE_SRC_PULSE_BIT     (3) // 0000 1000
#define REG_INT_SOURCE_SRC_FF_MT_1_BIT   (2) // 0000 0100
#define REG_INT_SOURCE_SRC_FF_MT_2_BIT   (1) // 0000 0010
#define REG_INT_SOURCE_SRC_DRDY_BIT      (0) // 0000 0001
// Register bit masks
#define REG_INT_SOURCE_SRC_ASLP_MASK     (0x80)
#define REG_INT_SOURCE_SRC_FIFO_MASK     (0x40)
#define REG_INT_SOURCE_SRC_TRANS_MASK    (0x20)
#define REG_INT_SOURCE_SRC_LNDPRT_MASK   (0x10)
#define REG_INT_SOURCE_SRC_PULSE_MASK    (0x08)
#define REG_INT_SOURCE_SRC_FF_MT_1_MASK  (0x04)
#define REG_INT_SOURCE_SRC_FF_MT_2_MASK  (0x02)
#define REG_INT_SOURCE_SRC_DRDY_MASK     (0x01)
// Read Macros
#define GET_REG_INT_SOURCE_SRC_ASLP(REG)	 		(((REG) >> REG_INT_SOURCE_SRC_ASLP_BIT) 	 & 0x01)
#define GET_REG_INT_SOURCE_SRC_FIFO(REG)	 		(((REG) >> REG_INT_SOURCE_SRC_FIFO_BIT) 	 & 0x01)
#define GET_REG_INT_SOURCE_SRC_TRANS(REG)	 		(((REG) >> REG_INT_SOURCE_SRC_TRANS_BIT) 	 & 0x01)
#define GET_REG_INT_SOURCE_SRC_LNDPRT(REG)	 	(((REG) >> REG_INT_SOURCE_SRC_LNDPRT_BIT)  & 0x01)
#define GET_REG_INT_SOURCE_SRC_PULSE(REG)	 		(((REG) >> REG_INT_SOURCE_SRC_PULSE_BIT) 	 & 0x01)
#define GET_REG_INT_SOURCE_SRC_FF_MT_1(REG)	 	(((REG) >> REG_INT_SOURCE_SRC_FF_MT_1_BIT) & 0x01)
#define GET_REG_INT_SOURCE_SRC_FF_MT_2(REG)	 	(((REG) >> REG_INT_SOURCE_SRC_FF_MT_2_BIT) & 0x01)
#define GET_REG_INT_SOURCE_SRC_DRDY(REG)	 		(((REG) >> REG_INT_SOURCE_SRC_DRDY_BIT) 	 & 0x01)

/*
 **  XYZ_DATA_CFG Sensor Data Configuration Register
 */
// Register flags
#define REG_XYZ_DATA_CFG_HPF_OUT_BIT           (4) // 0001 0000
#define REG_XYZ_DATA_CFG_FS1_BIT               (1) // 0000 0010
#define REG_XYZ_DATA_CFG_FS0_BIT               (0) // 0000 0001
// Register Bit Masks
#define REG_XYZ_DATA_CFG_HPF_OUT_MASK          (0x10)
#define REG_XYZ_DATA_CFG_FS1_MASK              (0x02)
#define REG_XYZ_DATA_CFG_FS0_MASK              (0x01)
#define REG_XYZ_DATA_CFG_FS_MASK               (0x03)
// write macros

#define SET_REG_XYZ_DATA_CFG_FS0(REG)  	((REG) |= (1UL  << REG_XYZ_DATA_CFG_FS0_BIT))
#define CLR_REG_XYZ_DATA_CFG_FS0(REG)	((REG) &= ~(1UL  << (REG_XYZ_DATA_CFG_FS0_BIT)))

#define SET_REG_XYZ_DATA_CFG_FS1(REG)  	((REG) |= (1UL  << REG_XYZ_DATA_CFG_FS1_BIT))
#define CLR_REG_XYZ_DATA_CFG_FS1(REG)	((REG) &= ~(1UL  << (REG_XYZ_DATA_CFG_FS1_BIT)))

#define SET_REG_XYZ_DATA_CFG_HPF_OUT(REG)  	((REG) |= (1UL  << REG_XYZ_DATA_CFG_HPF_OUT_BIT))
#define CLR_REG_XYZ_DATA_CFG_HPF_OUT(REG)		((REG) &= ~(1UL  << (REG_XYZ_DATA_CFG_HPF_OUT_BIT)))

// Read Macros
#define GET_REG_XYZ_DATA_CFG_FULL_SCALE(REG)	(((REG) >> REG_XYZ_DATA_CFG_FS_MASK) 	 & 0x01)

/*
 **  HP_FILTER_CUTOFF High Pass Filter Register
 */
// Register flags
#define REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP_BIT     (5) // 0010 0000
#define REG_HP_FILTER_CUTOFF_PULSE_LPF_EN_BIT      (4) // 0001 0000
#define REG_HP_FILTER_CUTOFF_SEL1_BIT              (1) // 0000 0010
#define REG_HP_FILTER_CUTOFF_SEL0_BIT              (0) // 0000 0001
//Register Bit Masks
#define REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP_MASK    (0x20)
#define REG_HP_FILTER_CUTOFF_PULSE_LPF_EN_MASK     (0x10)
#define REG_HP_FILTER_CUTOFF_SEL1_MASK             (0x02)
#define REG_HP_FILTER_CUTOFF_SEL0_MASK             (0x01)
#define REG_HP_FILTER_CUTOFF_SEL_MASK              (0x03)
// Write Macros
#define SET_REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP(REG)  		((REG) |= (1UL  << REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP_BIT))
#define CLR_REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP(REG)		((REG) &= ~(1UL  << (REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP_BIT)))
#define SET_REG_HP_FILTER_CUTOFF_PULSE_LPF_EN(REG)  		((REG) |= (1UL  << REG_HP_FILTER_CUTOFF_PULSE_LPF_EN_BIT))
#define CLR_REG_HP_FILTER_CUTOFF_PULSE_LPF_EN(REG)		((REG) &= ~(1UL  << (REG_HP_FILTER_CUTOFF_PULSE_LPF_EN_BIT)))
#define SET_REG_HP_FILTER_CUTOFF_SEL1(REG)  				((REG) |= (1UL  << REG_HP_FILTER_CUTOFF_SEL1_BIT))
#define CLR_REG_HP_FILTER_CUTOFF_SEL1(REG)				((REG) &= ~(1UL  << (REG_HP_FILTER_CUTOFF_SEL1_BIT)))
#define SET_REG_HP_FILTER_CUTOFF_SEL0(REG)  				((REG) |= (1UL  << REG_HP_FILTER_CUTOFF_SEL0_MASK))
#define CLR_REG_HP_FILTER_CUTOFF_SEL0(REG)				((REG) &= ~(1UL  << (REG_HP_FILTER_CUTOFF_SEL0_MASK)))
// Read Macros
#define GET_REG_HP_FILTER_CUTOFF_SEL(REG)					(((REG) >> REG_HP_FILTER_CUTOFF_SEL_MASK) & 0x01)
#define GET_REG_HP_FILTER_CUTOFF_PULSE_LPF_EN(REG)		(((REG) >> REG_HP_FILTER_CUTOFF_PULSE_LPF_EN_BIT) & 0x01)
#define GET_REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP(REG)		(((REG) >> REG_HP_FILTER_CUTOFF_PULSE_HPF_BYP_BIT) & 0x01)

/*
 **  PL_STATUS Portrait/Landscape Status Register
 */

#define REG_PL_STATUS_NEWLP_BIT             (7) // 1000 0000
#define REG_PL_STATUS_LO_BIT               	(6) // 0100 0000
#define REG_PL_STATUS_LAPO1_BIT            	(2) // 0000 0100
#define REG_PL_STATUS_LAPO0_BIT            	(1) // 0000 0010
#define REG_PL_STATUS_BAFRO_BIT             (0) // 0000 0001

#define GET_REG_PL_STATUS_NEWLP(REG)		(((REG) >> (REG_PL_STATUS_NEWLP_BIT)) & 0x01)
#define GET_REG_PL_STATUS_LO(REG)			(((REG) >> (REG_PL_STATUS_LO_BIT)) 	& 0x01)
#define GET_REG_PL_STATUS_LAPO(REG)		(((REG) >> (REG_PL_STATUS_LAPO1_BIT | REG_PL_STATUS_LAPO0_BIT)) & 0x01)
#define GET_REG_PL_STATUS_BAFRO(REG)		(((REG) >> (REG_PL_STATUS_BAFRO_BIT)) & 0x01)

/*
 **  PL_CFG Portrait/Landscape Configuration Register
 */
//
#define REG_PL_CFG_DBCNTM_BIT            	(7) // 1000 0000
#define REG_PL_CFG_PL_EN_BIT             	(6) // 0100 0000
//
#define REG_PL_CFG_DBCNTM_MASK          	(0x80)
#define REG_PL_CFG_PL_EN_MASK            	(0x40)

#define SET_REG_PL_CFG_DBCNTM (REG)		((REG) |= (1UL  << REG_PL_CFG_DBCNTM_BIT))
#define CLR_REG_PL_CFG_DBCNTM (REG)		((REG) &= ~(1UL 	   << (REG_PL_CFG_DBCNTM_BIT)))

#define SET_REG_PL_CFG_PL_EN(REG)			((REG) |= (1UL  << REG_PL_CFG_DBCNTM_BIT))
#define CLR_REG_PL_CFG_PL_EN(REG)			((REG) &= ~(1UL 	   << (REG_PL_CFG_DBCNTM_BIT)))

/*
 **  PL_COUNT Portrait/Landscape Debounce Register
 */
#define PL_COUNT_REG          				  (0x12)

/*
 **  PL_BF_ZCOMP Back/Front and Z Compensation Register
 */
#define REG_PL_BF_ZCOMP_BKFR1_BIT             (7) // 1000 0000
#define REG_PL_BF_ZCOMP_BKFR0_BIT             (6) // 0100 0000
#define REG_PL_BF_ZCOMP_ZLOCK2_BIT            (2) // 0000 0100
#define REG_PL_BF_ZCOMP_ZLOCK1_BIT            (1) // 0000 0010
#define REG_PL_BF_ZCOMP_ZLOCK0_BIT            (0) // 0000 0001

#define REG_PL_BF_ZCOMP_BKFR1_MASK            (0x80)
#define REG_PL_BF_ZCOMP_BKFR0_MASK            (0x40)
#define REG_PL_BF_ZCOMP_ZLOCK2_MASK           (0x04)
#define REG_PL_BF_ZCOMP_ZLOCK1_MASK           (0x02)
#define REG_PL_BF_ZCOMP_ZLOCK0_MASK           (0x01)
#define REG_PL_BF_ZCOMP_BKFR_MASK             (0xC0)
#define REG_PL_BF_ZCOMP_ZLOCK_MASK            (0x07)

#define GET_REG_PL_BF_ZCOMP_BKFR1(REG)	  (((REG) >> (REG_PL_BF_ZCOMP_BKFR_MASK)) & 0x01)		// Back front trip angle fixed threshold = 01 which is ≥ ±75°.
#define GET_REG_PL_BF_ZCOMP_ZLOCK(REG)	  (((REG) >> (REG_PL_BF_ZCOMP_ZLOCK_MASK)) & 0x01)	// Z-lock angle fixed threshold = 100 which is 29°.

/*
 **  PL_P_L_THS Portrait to Landscape Threshold Registers
 */
#define REG_PL_P_L_THS        0x14
//
#define REG_PL_P_L_THS_THS4_BIT          (7) // 1000 0000
#define REG_PL_P_L_THS_THS3_BIT          (6) // 0100 0000
#define REG_PL_P_L_THS_THS2_BIT          (5) // 0010 0000
#define REG_PL_P_L_THS_THS1_BIT          (4) // 0001 0000
#define REG_PL_P_L_THS_THS0_BIT          (3) // 0000 1000
#define REG_PL_P_L_THS_HYS2_BIT          (2) // 0000 0100
#define REG_PL_P_L_THS_HYS1_BIT          (1) // 0000 0010
#define REG_PL_P_L_THS_HYS0_BIT          (0) // 0000 0001
//
#define REG_PL_P_L_THS_THS4_MASK         (0x80)
#define REG_PL_P_L_THS_THS3_MASK         (0x40)
#define REG_PL_P_L_THS_THS2_MASK         (0x20)
#define REG_PL_P_L_THS_THS1_MASK         (0x10)
#define REG_PL_P_L_THS_THS0_MASK         (0x08)
#define REG_PL_P_L_THS_MASK          	 (0xF8)
#define REG_PL_P_L_THS_HYS2_MASK         (0x04)
#define REG_PL_P_L_THS_HYS1_MASK         (0x02)
#define REG_PL_P_L_THS_HYS0_MASK         (0x01)
#define REG_PL_P_L_THS_HYS_MASK          (0x07)
//
#define SET_REG_PL_P_L_THS_THS4(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_THS4_BIT))
#define CLR_REG_PL_P_L_THS_THS4(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_THS4_BIT))
#define SET_REG_PL_P_L_THS_THS3(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_THS3_BIT))
#define CLR_REG_PL_P_L_THS_THS3(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_THS3_BIT))
#define SET_REG_PL_P_L_THS_THS2(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_THS2_BIT))
#define CLR_REG_PL_P_L_THS_THS2(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_THS2_BIT))
#define SET_REG_PL_P_L_THS_THS1(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_THS1_BIT))
#define CLR_REG_PL_P_L_THS_THS1(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_THS1_BIT))
#define SET_REG_PL_P_L_THS_THS0(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_THS0_BIT))
#define CLR_REG_PL_P_L_THS_THS0(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_THS0_BIT))
#define SET_REG_PL_P_L_THS_HYS2(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_HYS2_BIT))
#define CLR_REG_PL_P_L_THS_HYS2(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_HYS2_BIT))
#define SET_REG_PL_P_L_THS_HYS1(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_HYS1_BIT))
#define CLR_REG_PL_P_L_THS_HYS1(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_HYS1_BIT))
#define SET_REG_PL_P_L_THS_HYS0(REG)			((REG) |= (1UL  << REG_PL_P_L_THS_HYS0_BIT))
#define CLR_REG_PL_P_L_THS_HYS0(REG)			((REG) &= ~(1UL << REG_PL_P_L_THS_HYS0_BIT))

/*
 **  FF_MT_CFG Freefall and Motion Configuration Registers
 */
#define REG_FF_MT_CFG_1       				(0x15)
#define REG_FF_MT_CFG_2       				(0x19)
//
#define REG_FF_MT_CFG_ELE_BIT               (7) // 1000 0000
#define REG_FF_MT_CFG_OAE_BIT               (6) // 0100 0000
#define REG_FF_MT_CFG_ZEFE_BIT              (5) // 0010 0000
#define REG_FF_MT_CFG_YEFE_BIT              (4) // 0001 0000
#define REG_FF_MT_CFG_XEFE_BIT              (3) // 0000 1000
//
#define REG_FF_MT_CFG_ELE_MASK              (0x80)
#define REG_FF_MT_CFG_OAE_MASK              (0x40)
#define REG_FF_MT_CFG_ZEFE_MASK             (0x20)
#define REG_FF_MT_CFG_YEFE_MASK             (0x10)
#define REG_FF_MT_CFG_XEFE_MASK             (0x08)

#define GET_REG_FF_MT_CFG_ELE(REG)		(((REG) >> (REG_FF_MT_CFG_ELE_BIT)) & 0x01)
#define SET_REG_FF_MT_CFG_ELE(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_ELE_BIT)))
#define CLR_REG_FF_MT_CFG_ELE(REG)		((REG) &= ~(1UL 	   << (REG_FF_MT_CFG_ELE_BIT)))
#define GET_REG_FF_MT_CFG_ZEFE(REG)		(((REG) >> (REG_FF_MT_CFG_ZEFE_BIT)) & 0x01)
#define SET_REG_FF_MT_CFG_ZEFE(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_ZEFE_BIT)))
#define CLR_REG_FF_MT_CFG_ZEFE(REG)		((REG) &= ~(1UL 	   << (REG_FF_MT_CFG_ZEFE_BIT)))
#define GET_REG_FF_MT_CFG_OAE(REG)		(((REG) >> (REG_FF_MT_CFG_OAE_BIT)) & 0x01)
#define SET_REG_FF_MT_CFG_OAE(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_OAE_BIT)))
#define CLR_REG_FF_MT_CFG_OAE(REG)		((REG) &= ~(1UL 	   << (REG_FF_MT_CFG_OAE_BIT)))
#define GET_REG_FF_MT_CFG_YEFE(REG)		(((REG) >> (REG_FF_MT_CFG_YEFE_BIT)) & 0x01)
#define SET_REG_FF_MT_CFG_YEFE(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_YEFE_BIT)))
#define CLR_REG_FF_MT_CFG_YEFE(REG)		((REG) &= ~(1UL 	   << (REG_FF_MT_CFG_YEFE_BIT))
#define GET_REG_FF_MT_CFG_XEFE(REG)		(((REG) >> (REG_FF_MT_CFG_XEFE_BIT)) & 0x01)
#define SET_REG_FF_MT_CFG_XEFE(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_XEFE_BIT)))
#define CLR_REG_FF_MT_CFG_XEFE(REG)		((REG) &= ~(1UL 	   << (REG_FF_MT_CFG_XEFE_BIT)))

/*
 **  FF_MT_SRC Freefall and Motion Source Registers
 */
#define REG_FF_MT_SRC_1       (0x16)
#define REG_FF_MT_SRC_2       (0x1A)
//Bit flags
#define REG_FF_MT_SRC_EA_BIT                (7) // 1000 0000
#define REG_FF_MT_SRC_ZHE_BIT               (5) // 0010 0000
#define REG_FF_MT_SRC_ZHP_BIT               (4) // 0001 0000
#define REG_FF_MT_SRC_YHE_BIT               (3) // 0000 1000
#define REG_FF_MT_SRC_YHP_BIT               (2) // 0000 0100
#define REG_FF_MT_SRC_XHE_BIT               (1) // 0000 0010
#define REG_FF_MT_SRC_XHP_BIT               (0) // 0000 0001
// Register bit masks
#define REG_FF_MT_SRC_EA_MASK               (0x80)
#define REG_FF_MT_SRC_ZHE_MASK              (0x20)
#define REG_FF_MT_SRC_ZHP_MASK              (0x10)
#define REG_FF_MT_SRC_YHE_MASK              (0x08)
#define REG_FF_MT_SRC_YHP_MASK              (0x04)
#define REG_FF_MT_SRC_XHE_MASK              (0x02)
#define REG_FF_MT_SRC_XHP_MASK              (0x01)
// Read Macros
#define GET_REG_FF_MT_SRC_EA(REG)			(((REG) >> (REG_FF_MT_SRC_EA_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_ZHE(REG)		(((REG) >> (REG_FF_MT_SRC_ZHE_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_ZHP(REG)		(((REG) >> (REG_FF_MT_SRC_ZHP_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_YHE(REG)		(((REG) >> (REG_FF_MT_SRC_YHE_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_YHP(REG)		(((REG) >> (REG_FF_MT_SRC_YHP_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_XHE(REG)		(((REG) >> (REG_FF_MT_SRC_XHE_BIT)) & 0x01)
#define GET_REG_FF_MT_SRC_XHP(REG)		(((REG) >> (REG_FF_MT_SRC_XHP_BIT)) & 0x01)

/*
 **  FF_MT_THS Freefall and Motion Threshold Registers
 **  TRANSIENT_THS Transient Threshold Register
 */
#define REG_FT_MT_THS_1       (0x17)
#define REG_FT_MT_THS_2       (0x1B)
#define REG_TRANSIENT_THS     (0x1F)
//
#define REG_FF_MT_THS_DBCNTM_BIT            (7) // 1000 0000
#define REG_FF_MT_THS_THS6_BIT              (6) // 0100 0000
#define REG_FF_MT_THS_THS5_BIT              (5) // 0010 0000
#define REG_FF_MT_THS_THS4_BIT              (4) // 0001 0000
#define REG_FF_MT_THS_THS3_BIT              (3) // 0000 1000
#define REG_FF_MT_THS_THS2_BIT              (2) // 0000 0100
#define REG_FF_MT_THS_THS1_BIT              (1) // 0000 0010
#define REG_FF_MT_THS_THS0_BIT              (0) // 0000 0001
//
#define REG_FF_MT_THS_DBCNTM_MASK           (0x80)
#define REG_FF_MT_THS_THS6_MASK             (0x40)
#define REG_FF_MT_THS_THS5_MASK             (0x20)
#define REG_FF_MT_THS_THS4_MASK             (0x10)
#define REG_FF_MT_THS_THS3_MASK             (0x08)
#define REG_FF_MT_THS_THS2_MASK             (0x04)
#define REG_FF_MT_THS_THS1_MASK             (0x02)
#define REG_FF_MT_THS_THS0_MASK             (0x01)
#define REG_FF_MT_THS_THS_MASK              (0x7F)

#define GET_REG_FF_MT_THS_DBCNTM(REG)		(((REG) >> (REG_FF_MT_CFG_ELE_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_DBCNTM(REG)		((REG) |= (1UL << (REG_FF_MT_CFG_ELE_BIT)))
#define CLR_REG_FF_MT_THS_DBCNTM(REG)		((REG) &= ~(1UL << (REG_FF_MT_CFG_ELE_BIT)))
#define GET_REG_FF_MT_THS_THS6(REG)		(((REG) >> (REG_FF_MT_THS_THS6_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS6(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS6_BIT)))
#define CLR_REG_FF_MT_THS_THS6(REG)		((REG) &= ~(1UL << (REG_FF_MT_THS_THS6_BIT)))
#define GET_REG_FF_MT_THS_THS5(REG)		(((REG) >> (REG_FF_MT_THS_THS5_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS5(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS5_BIT)))
#define CLR_REG_FF_MT_THS_THS5(REG)		((REG) &= ~(1UL  << (REG_FF_MT_THS_THS5_BIT)))
#define GET_REG_FF_MT_THS_THS4(REG)		(((REG) >> (REG_FF_MT_THS_THS4_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS4(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS4_BIT)))
#define CLR_REG_FF_MT_THS_THS4(REG)		((REG) &= ~(1UL  << (REG_FF_MT_THS_THS4_BIT)))
#define GET_REG_FF_MT_THS_THS3(REG)		(((REG) >> (REG_FF_MT_THS_THS3_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS3(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS3_BIT)))
#define CLR_REG_FF_MT_THS_THS3(REG)		((REG) &= ~(1UL  << (REG_FF_MT_THS_THS3_BIT)))
#define GET_REG_FF_MT_THS_THS2(REG)		(((REG) >> (REG_FF_MT_THS_THS2_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS2(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS2_BIT)))
#define CLR_REG_FF_MT_THS_THS2(REG)		((REG) &= ~(1UL  << (REG_FF_MT_THS_THS2_BIT)))
#define GET_REG_FF_MT_THS_THS1(REG)		(((REG) >> (REG_FF_MT_THS_THS1_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS1(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS1_BIT)))
#define CLR_REG_FF_MT_THS_THS1(REG)		((REG) &= ~(1UL  << (REG_FF_MT_THS_THS1_BIT)))
#define GET_REG_FF_MT_THS_THS0(REG)		(((REG) >> (REG_FF_MT_THS_THS0_BIT)) & 0x01)
#define SET_REG_FF_MT_THS_THS0(REG)		((REG) |= (1UL << (REG_FF_MT_THS_THS0_BIT)))
#define CLR_REG_FF_MT_THS_THS0(REG)		((REG) &= ~(1UL << (REG_FF_MT_THS_THS0_BIT)))

/*
 **  FF_MT_COUNT Freefall Motion Count Registers
 */
#define REG_FF_MT_COUNT_1     (0x18)
#define REG_FF_MT_COUNT_2     (0x1C)

/*
 **  TRANSIENT_CFG Transient Configuration Register
 */
#define REG_TRANSIENT_CFG     (0x1D)
//
#define REG_TRANSIENT_CFG_TELE_BIT              (4) // 0001 0000
#define REG_TRANSIENT_CFG_ZTEFE_BIT             (3) // 0000 1000
#define REG_TRANSIENT_CFG_YTEFE_BIT             (2) // 0000 0100
#define REG_TRANSIENT_CFG_XTEFE_BIT             (1) // 0000 0010
#define REG_TRANSIENT_CFG_HPF_BYP_BIT           (0) // 0000 0001
//
#define REG_TRANSIENT_CFG_TELE_MASK             (0x10)
#define REG_TRANSIENT_CFG_ZTEFE_MASK            (0x08)
#define REG_TRANSIENT_CFGT_YTEFE_MASK           (0x04)
#define REG_TRANSIENT_CFG_XTEFE_MASK            (0x02)
#define REG_TRANSIENT_CFG_HPF_BYP_MASK          (0x01)

#define GET_REG_TRANSIENT_CFG_TELE(REG)		(((REG) >> (REG_TRANSIENT_CFG_TELE_BIT)) & 0x01)
#define SET_REG_TRANSIENT_CFG_TELE(REG)		((REG) |= (1UL << (REG_TRANSIENT_CFG_TELE_BIT)))
#define CLR_REG_TRANSIENT_CFG_TELE(REG)		((REG) &= ~(1UL << (REG_TRANSIENT_CFG_TELE_BIT)))
#define GET_REG_TRANSIENT_CFG_ZTEFE(REG)		(((REG) >> (REG_TRANSIENT_CFG_ZTEFE_BIT)) & 0x01)
#define SET_REG_TRANSIENT_CFG_ZTEFE(REG)		((REG) |= (1UL << (REG_TRANSIENT_CFG_ZTEFE_BIT)))
#define CLR_REG_TRANSIENT_CFG_ZTEFE(REG)		((REG) &= ~(1UL << (REG_TRANSIENT_CFG_ZTEFE_BIT)))
#define GET_REG_TRANSIENT_CFGT_YTEFE(REG)		(((REG) >> (REG_TRANSIENT_CFG_YTEFE_BIT)) & 0x01)
#define SET_REG_TRANSIENT_CFGT_YTEFE(REG)		((REG) |= (1UL << (REG_TRANSIENT_CFG_YTEFE_BIT)))
#define CLR_REG_TRANSIENT_CFGT_YTEFE(REG)		((REG) &= ~(1UL << (REG_TRANSIENT_CFG_YTEFE_BIT)))
#define GET_REG_TRANSIENT_CFG_XTEFE(REG)		(((REG) >> (REG_TRANSIENT_CFG_XTEFE_BIT)) & 0x01)
#define SET_REG_TRANSIENT_CFG_XTEFE(REG)		((REG) |= (1UL << (REG_TRANSIENT_CFG_XTEFE_BIT)))
#define CLR_REG_TRANSIENT_CFG_XTEFE(REG)		((REG) &= ~(1UL << (REG_TRANSIENT_CFG_XTEFE_BIT)))
#define GET_REG_TRANSIENT_CFG_HPF_BYP(REG)	(((REG) >> (REG_TRANSIENT_CFG_HPF_BYP_BIT)) & 0x01)
#define SET_REG_TRANSIENT_CFG_HPF_BYP(REG)	((REG) |= (1UL << (REG_TRANSIENT_CFG_HPF_BYP_BIT)))
#define CLR_REG_TRANSIENT_CFG_HPF_BYP(REG)	((REG) &= ~(1UL << (REG_TRANSIENT_CFG_HPF_BYP_BIT)))

/*
 **  TRANSIENT_SRC Transient Source Register
 */
#define REG_TRANSIENT_SRC 	  (0x1E)
//
#define REG_TRANSIENT_SRC_TEA_BIT               (6) // 0100 0000
#define REG_TRANSIENT_SRC_ZTRANSE_BIT           (5) // 0010 0000
#define REG_TRANSIENT_SRC_ZTRANSPOL_BIT         (4) // 0001 0000
#define REG_TRANSIENT_SRC_YTRANSE_BIT           (3) // 0000 1000
#define REG_TRANSIENT_SRC_YTRANSPOL_BIT         (2) // 0000 0100
#define REG_TRANSIENT_SRC_XTRANSE_BIT           (1) // 0000 0010
#define REG_TRANSIENT_SRC_XTRANSPOL_BIT         (0) // 0000 0001
//
#define REG_TRANSIENT_SRC_TEA_MASK              (0x40)
#define REG_TRANSIENT_SRC_ZTRANSE_MASK          (0x20)
#define REG_TRANSIENT_SRC_ZTRANSEPOL_MASK       (0x10)
#define REG_TRANSIENT_SRC_YTRANSE_MASK          (0x08)
#define REG_TRANSIENT_SRC_YTRANSEPOL_MASK       (0x04)
#define REG_TRANSIENT_SRC_XTRANSE_MASK          (0x02)
#define REG_TRANSIENT_SRC_XTRANSEPOL_MASK       (0x01)

#define GET_REG_TRANSIENT_SRC_TEA(REG)		(((REG) >> (REG_TRANSIENT_SRC_TEA_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_ZTRANSE(REG)	(((REG) >> (REG_TRANSIENT_SRC_ZTRANSE_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_ZTRANSPOL(REG)	(((REG) >> (REG_TRANSIENT_SRC_ZTRANSPOL_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_YTRANSE(REG)	(((REG) >> (REG_TRANSIENT_SRC_YTRANSE_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_YTRANSPOL(REG)	(((REG) >> (REG_TRANSIENT_SRC_YTRANSPOL_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_XTRANSE(REG)	(((REG) >> (REG_TRANSIENT_SRC_XTRANSE_BIT)) & 0x01)
#define GET_REG_TRANSIENT_SRC_XTRANSPOL(REG)	(((REG) >> (REG_TRANSIENT_SRC_XTRANSPOL_BIT)) & 0x01)

/*
 **  TRANSIENT_COUNT Transient Debounce Register
 */
#define REG_TRANSIENT_COUNT   (0x20)

/*
 **  PULSE_CFG Pulse Configuration Register
 */
#define REG_PULSE_CFG         (0x21)
//
#define REG_PULSE_CFG_DPA_BIT               (7) // 1000 0000
#define REG_PULSE_CFG_PELE_BIT              (6) // 0100 0000
#define REG_PULSE_CFG_ZDPEFE_BIT            (5) // 0010 0000
#define REG_PULSE_CFG_ZSPEFE_BIT            (4) // 0001 0000
#define REG_PULSE_CFG_YDPEFE_BIT            (3) // 0000 1000
#define REG_PULSE_CFG_YSPEFE_BIT            (2) // 0000 0100
#define REG_PULSE_CFG_XDPEFE_BIT            (1) // 0000 0010
#define REG_PULSE_CFG_XSPEFE_BIT            (0) // 0000 0001
//
#define REG_PULSE_CFG_DPA_MASK              (0x80)
#define REG_PULSE_CFG_PELE_MASK             (0x40)
#define REG_PULSE_CFG_ZDPEFE_MASK           (0x20)
#define REG_PULSE_CFG_ZSPEFE_MASK           (0x10)
#define REG_PULSE_CFG_YDPEFE_MASK           (0x08)
#define REG_PULSE_CFG_YSPEFE_MASK           (0x04)
#define REG_PULSE_CFG_XDPEFE_MASK           (0x02)
#define REG_PULSE_CFG_XSPEFE_MASK           (0x01)

#define GET_REG_PULSE_CFG_DPA(REG)	(((REG) >> (REG_PULSE_CFG_DPA_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_DPA(REG)	((REG) |= (1UL << (REG_PULSE_CFG_DPA_BIT)))
#define CLR_REG_PULSE_CFG_DPA(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_DPA_BIT)))
#define GET_REG_PULSE_CFG_PELE(REG)	(((REG) >> (REG_PULSE_CFG_PELE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_PELE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_PELE_BIT)))
#define CLR_REG_PULSE_CFG_PELE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_PELE_BIT)))
#define GET_REG_PULSE_CFG_ZDPEFE(REG)	(((REG) >> (REG_PULSE_CFG_ZDPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_ZDPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_ZDPEFE_BIT)))
#define CLR_REG_PULSE_CFG_ZDPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_ZDPEFE_BIT)))
#define GET_REG_PULSE_CFG_ZSPEFE(REG)	(((REG) >> (REG_PULSE_CFG_ZSPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_ZSPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_ZSPEFE_BIT)))
#define CLR_REG_PULSE_CFG_ZSPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_ZSPEFE_BIT)))
#define GET_REG_PULSE_CFG_YDPEFE(REG)	(((REG) >> (REG_PULSE_CFG_YDPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_YDPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_YDPEFE_BIT)))
#define CLR_REG_PULSE_CFG_YDPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_YDPEFE_BIT)))
#define GET_REG_PULSE_CFG_YSPEFE(REG)	(((REG) >> (REG_PULSE_CFG_YSPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_YSPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_YSPEFE_BIT)))
#define CLR_REG_PULSE_CFG_YSPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_YSPEFE_BIT)))
#define GET_REG_PULSE_CFG_XDPEFE(REG)	(((REG) >> (REG_PULSE_CFG_XDPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_XDPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_XDPEFE_BIT)))
#define CLR_REG_PULSE_CFG_XDPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_XDPEFE_BIT)))
#define GET_REG_PULSE_CFG_XSPEFE(REG)	(((REG) >> (REG_PULSE_CFG_XSPEFE_BIT)) & 0x01)
#define SET_REG_PULSE_CFG_XSPEFE(REG)	((REG) |= (1UL << (REG_PULSE_CFG_XSPEFE_BIT)))
#define CLR_REG_PULSE_CFG_XSPEFE(REG)	((REG) &= ~(1UL << (REG_PULSE_CFG_XSPEFE_BIT)))

/*
 **  PULSE_SRC Pulse Source Register
 */
#define REG_PULSE_SRC         0x22
//
#define REG_PULSE_SRC_PEA_BIT               (7) // 1000 0000
#define REG_PULSE_SRC_PAXZ_BIT              (6) // 0100 0000
#define REG_PULSE_SRC_PAXY_BIT              (5) // 0010 0000
#define REG_PULSE_SRC_PAXX_BIT              (4) // 0001 0000
#define REG_PULSE_SRC_PDPE_BIT              (3) // 0000 1000
#define REG_PULSE_SRC_POLZ_BIT              (2) // 0000 0100
#define REG_PULSE_SRC_POLY_BIT              (1) // 0000 0010
#define REG_PULSE_SRC_POLX_BIT              (0) // 0000 0001
//
#define REG_PULSE_SRC_PEA_MASK              (0x80)
#define REG_PULSE_SRC_PAXZ_MASK             (0x40)
#define REG_PULSE_SRC_PAXY_MASK             (0x20)
#define REG_PULSE_SRC_PAXX_MASK             (0x10)
#define REG_PULSE_SRC_PDPE_MASK             (0x08)
#define REG_PULSE_SRC_POLZ_MASK             (0x04)
#define REG_PULSE_SRC_POLY_MASK             (0x02)
#define REG_PULSE_SRC_POLX_MASK             (0x01)

#define GET_REG_PULSE_SRC_PEA(REG)	(((REG) >> (REG_PULSE_SRC_PEA_BIT))  & 0x01)
#define GET_REG_PULSE_SRC_PAXZ(REG)	(((REG) >> (REG_PULSE_SRC_PAXZ_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_PAXY(REG)	(((REG) >> (REG_PULSE_SRC_PAXY_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_PAXX(REG)	(((REG) >> (REG_PULSE_SRC_PAXX_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_PDPE(REG)	(((REG) >> (REG_PULSE_SRC_PDPE_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_POLZ(REG)	(((REG) >> (REG_PULSE_SRC_POLZ_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_POLY(REG)	(((REG) >> (REG_PULSE_SRC_POLY_BIT)) & 0x01)
#define GET_REG_PULSE_SRC_POLX(REG)	(((REG) >> (REG_PULSE_SRC_POLX_BIT)) & 0x01)

/*
 **  PULSE_THS XYZ Pulse Threshold Registers
 */
#define REG_PULSE_THSX        (0x23)
#define REG_PULSE_THSY        (0x24)
#define REG_PULSE_THSZ        (0x25)
//
#define REG_PTHS_MASK         (0x7F)

/*
 **  PULSE_TMLT Pulse Time Window Register
 */
#define REG_PULSE_TMLT	       (0x26)

/*
 **  PULSE_LTCY Pulse Latency Timer Register
 */
#define REG_PULSE_LTCY	        (0x27)

/*
 **  PULSE_WIND Second Pulse Time Window Register
 */
#define REG_PULSE_WIND        	(0x28)

/*
 **  ASLP_COUNT Auto Sleep Inactivity Timer Register
 */
#define REG_ASLP_COUNT        (0x29)

/*
 **  CTRL_REG1 System Control 1 Register
 */
#define REG_CTRL_REG1          (0x2A)
//
#define REG_CTRL_REG1_ASLP_RATE1_BIT        (7) // 1000 0000
#define REG_CTRL_REG1_ASLP_RATE0_BIT        (6) // 0100 0000
#define REG_CTRL_REG1_DR2_BIT               (5) // 0010 0000
#define REG_CTRL_REG1_DR1_BIT               (4) // 0001 0000
#define REG_CTRL_REG1_DR0_BIT               (3) // 0000 1000
#define REG_CTRL_REG1_LNOISE_BIT            (2) // 0000 0100
#define REG_CTRL_REG1_FREAD_BIT             (1) // 0000 0010
#define REG_CTRL_REG1_ACTIVE_BIT            (0) // 0000 0001
//
#define REG_CTRL_REG1_ASLP_RATE1_MASK       0x80
#define REG_CTRL_REG1_ASLP_RATE0_MASK       0x40
#define REG_CTRL_REG1_DR2_MASK              0x20
#define REG_CTRL_REG1_DR1_MASK              0x10
#define REG_CTRL_REG1_DR0_MASK              0x08
#define REG_CTRL_REG1_LNOISE_MASK           0x04
#define REG_CTRL_REG1_FREAD_MASK            0x02
#define REG_CTRL_REG1_ACTIVE_MASK           0x01
#define REG_CTRL_REG1_ASLP_RATE_MASK        0xC0
#define REG_CTRL_REG1_DR_MASK               0x38

#define GET_REG_CTRL_REG1_ASLP_RATE1(REG)	(((REG) >> (REG_CTRL_REG1_ASLP_RATE1_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_ASLP_RATE1(REG)	((REG) |= (1UL << (REG_CTRL_REG1_ASLP_RATE1_BIT)))
#define CLR_REG_CTRL_REG1_ASLP_RATE1(REG)	((REG) &= ~(1UL << (REG_CTRL_REG1_ASLP_RATE1_BIT)))
#define GET_REG_CTRL_REG1_ASLP_RATE0(REG)	(((REG) >> (REG_CTRL_REG1_ASLP_RATE0_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_ASLP_RATE0(REG)	((REG) |= (1UL << (REG_CTRL_REG1_ASLP_RATE0_BIT)))
#define CLR_REG_CTRL_REG1_ASLP_RATE0(REG)	((REG) &= ~(1UL << (REG_CTRL_REG1_ASLP_RATE0_BIT)))
#define GET_REG_CTRL_REG1_DR2(REG)		(((REG) >> (REG_CTRL_REG1_DR2_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_DR2(REG)		((REG) |= (1UL << (REG_CTRL_REG1_DR2_BIT)))
#define CLR_REG_CTRL_REG1_DR2(REG)		((REG) &= ~(1UL << (REG_CTRL_REG1_DR2_BIT)))
#define GET_REG_CTRL_REG1_DR1(REG)		(((REG) >> (REG_CTRL_REG1_DR1_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_DR1(REG)		((REG) |= (1UL << (REG_CTRL_REG1_DR1_BIT)))
#define CLR_REG_CTRL_REG1_DR1(REG)		((REG) &= ~(1UL << (REG_CTRL_REG1_DR1_BIT)))
#define GET_REG_CTRL_REG1_DR0(REG)		(((REG) >> (REG_CTRL_REG1_DR0_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_DR0(REG)		((REG) |= (1UL << (REG_CTRL_REG1_DR0_BIT)))
#define CLR_REG_CTRL_REG1_DR0(REG)		((REG) &= ~(1UL << (REG_CTRL_REG1_DR0_BIT)))
#define GET_REG_CTRL_REG1_LNOISE(REG)		(((REG) >> (REG_CTRL_REG1_LNOISE_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_LNOISE(REG)		((REG) |= (1UL << (REG_CTRL_REG1_LNOISE_BIT)))
#define CLR_REG_CTRL_REG1_LNOISE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG1_LNOISE_BIT)))
#define GET_REG_CTRL_REG1_FREAD(REG)		(((REG) >> (REG_CTRL_REG1_FREAD_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_FREAD(REG)		((REG) |= (1UL << (REG_CTRL_REG1_FREAD_BIT)))
#define CLR_REG_CTRL_REG1_FREAD(REG)		((REG) &= ~(1UL << REG_CTRL_REG1_FREAD_BIT))

#define GET_REG_CTRL_REG1_ACTIVE(REG)		(((REG) >> (REG_CTRL_REG1_ACTIVE_BIT)) & 0x01)
#define SET_REG_CTRL_REG1_ACTIVE(REG)		((REG) |= (1UL << (REG_CTRL_REG1_ACTIVE_BIT)))
#define CLR_REG_CTRL_REG1_ACTIVE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG1_ACTIVE_BIT)))

/*
 **  CTRL_REG2 System Control 2 Register
 */
#define REG_CTRL_REG2             0x2B
//
#define REG_CTRL_REG2_ST_BIT                (7) // 1000 0000
#define REG_CTRL_REG2_RST_BIT              (6) // 0100 0000
#define REG_CTRL_REG2_SMODS1_BIT            (4) // 0001 0000
#define REG_CTRL_REG2_SMODS0_BIT            (3) // 0000 1000
#define REG_CTRL_REG2_SLPE_BIT              (2) // 0000 0100
#define REG_CTRL_REG2_MODS1_BIT             (1) // 0000 0010
#define REG_CTRL_REG2_MODS0_BIT             (0) // 0000 0001
//
#define REG_CTRL_REG2_ST_MASK               (0x80)
#define REG_CTRL_REG2_RST_MASK              (0x40)
#define REG_CTRL_REG2_SMODS1_MASK           (0x10)   // FL, correction
#define REG_CTRL_REG2_SMODS0_MASK           (0x08)  // FL, correction
#define REG_CTRL_REG2_SLPE_MASK             (0x04)
#define REG_CTRL_REG2_MODS1_MASK            (0x02)
#define REG_CTRL_REG2_MODS0_MASK            (0x01)
#define REG_CTRL_REG2_SMODS_MASK            (0x18)
#define REG_CTRL_REG2_MODS_MASK             (0x03)

#define GET_REG_CTRL_REG2_ST(REG)			(((REG) >> (REG_CTRL_REG2_ST_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_ST(REG)			((REG) |= (1UL << (REG_CTRL_REG2_ST_BIT)))
#define CLR_REG_CTRL_REG2_ST(REG)			((REG) &= ~(1UL << (REG_CTRL_REG2_ST_BIT)))
#define SET_REG_CTRL_REG2_RST(REG)		((REG) |= (1UL << (REG_CTRL_REG2_RST_BIT)))
#define GET_REG_CTRL_REG2_SMODS1(REG)		(((REG) >> (REG_CTRL_REG2_SMODS1_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_SMODS1(REG)		((REG) |= (1UL << (REG_CTRL_REG2_SMODS1_BIT)))
#define CLR_REG_CTRL_REG2_SMODS1(REG)		((REG) &= ~(1UL << (REG_CTRL_REG2_SMODS1_BIT)))
#define GET_REG_CTRL_REG2_SMODS0(REG)		(((REG) >> (REG_CTRL_REG2_SMODS0_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_SMODS0(REG)		((REG) |= (1UL << (REG_CTRL_REG2_SMODS0_BIT)))
#define CLR_REG_CTRL_REG2_SMODS0(REG)		((REG) &= ~(1UL << (REG_CTRL_REG2_SMODS0_BIT)))
#define GET_REG_CTRL_REG2_SLPE(REG)		(((REG) >> (REG_CTRL_REG2_SLPE_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_SLPE(REG)		((REG) |= (1UL << (REG_CTRL_REG2_SLPE_BIT)))
#define CLR_REG_CTRL_REG2_SLPE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG2_SLPE_BIT)))
#define GET_REG_CTRL_REG2_MODS1(REG)		(((REG) >> (REG_CTRL_REG2_MODS1_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_MODS1(REG)		((REG) |= (1UL << (REG_CTRL_REG2_MODS1_BIT)))
#define CLR_REG_CTRL_REG2_MODS1(REG)		((REG) &= ~(1UL << (REG_CTRL_REG2_MODS1_BIT)))
#define GET_REG_CTRL_REG2_MODS0(REG)		(((REG) >> (REG_CTRL_REG2_MODS0_BIT)) & 0x01)
#define SET_REG_CTRL_REG2_MODS0(REG)		((REG) |= (1UL << (REG_CTRL_REG2_MODS0_BIT)))
#define CLR_REG_CTRL_REG2_MODS0(REG)		((REG) &= ~(1UL << (REG_CTRL_REG2_MODS0_BIT)))

/*
 **  CTRL_REG3 Interrupt Control Register
 */
#define REG_CTRL_REG3             0x2C
//
#define REG_CTRL_REG3_FIFO_GATE_BIT         (7) // 1000 0000
#define REG_CTRL_REG3_WAKE_TRANS_BIT        (6) // 0100 0000
#define REG_CTRL_REG3_WAKE_LNDPRT_BIT       (5) // 0010 0000
#define REG_CTRL_REG3_WAKE_PULSE_BIT        (4) // 0001 0000
#define REG_CTRL_REG3_WAKE_FF_MT_1_BIT      (3) // 0000 1000
#define REG_CTRL_REG3_WAKE_FF_MT_2_BIT      (2) // 0000 0100
#define REG_CTRL_REG3_IPOL_BIT              (1) // 0000 0010
#define REG_CTRL_REG3_PP_OD_BIT             (0) // 0000 0001
//
#define REG_CTRL_REG3_FIFO_GATE_MASK        0x80
#define REG_CTRL_REG3_WAKE_TRANS_MASK       0x40
#define REG_CTRL_REG3_WAKE_LNDPRT_MASK      0x20
#define REG_CTRL_REG3_WAKE_PULSE_MASK       0x10
#define REG_CTRL_REG3_WAKE_FF_MT_1_MASK     0x08
#define REG_CTRL_REG3_WAKE_FF_MT_2_MASK     0x04
#define REG_CTRL_REG3_IPOL_MASK             0x02
#define REG_CTRL_REG3_PP_OD_MASK            0x01

#define GET_REG_CTRL_REG3_FIFO_GATE(REG)		(((REG) >> (REG_CTRL_REG3_FIFO_GATE_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_FIFO_GATE(REG)		((REG) |= (1UL << (REG_CTRL_REG3_FIFO_GATE_BIT)))
#define CLR_REG_CTRL_REG3_FIFO_GATE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG3_FIFO_GATE_BIT)))
#define GET_REG_CTRL_REG3_WAKE_TRANS(REG)		(((REG) >> (REG_CTRL_REG3_WAKE_TRANS_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_WAKE_TRANS(REG)		((REG) |= (1UL << (REG_CTRL_REG3_WAKE_TRANS_BIT)))
#define CLR_REG_CTRL_REG3_WAKE_TRANS(REG)		((REG) &= ~(1UL << (REG_CTRL_REG3_WAKE_TRANS_BIT)))
#define GET_REG_CTRL_REG3_WAKE_LNDPRT(REG)	(((REG) >> (REG_CTRL_REG3_WAKE_LNDPRT_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_WAKE_LNDPRT(REG)	((REG) |= (1UL << (REG_CTRL_REG3_WAKE_LNDPRT_BIT)))
#define CLR_REG_CTRL_REG3_WAKE_LNDPRT(REG)	((REG) &= ~(1UL << (REG_CTRL_REG3_WAKE_LNDPRT_BIT)))
#define GET_REG_CTRL_REG3_WAKE_PULSE(REG)		(((REG) >> (REG_CTRL_REG3_WAKE_PULSE_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_WAKE_PULSE(REG)		((REG) |= (1UL << (REG_CTRL_REG3_WAKE_PULSE_BIT)))
#define CLR_REG_CTRL_REG3_WAKE_PULSE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG3_WAKE_PULSE_BIT)))
#define GET_REG_CTRL_REG3_WAKE_FF_MT_1(REG)	(((REG) >> (REG_CTRL_REG3_WAKE_FF_MT_1_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_WAKE_FF_MT_1(REG)	((REG) |= (1UL << (REG_CTRL_REG3_WAKE_FF_MT_1_BIT)))
#define CLR_REG_CTRL_REG3_WAKE_FF_MT_1(REG)	((REG) &= ~(1UL << (REG_CTRL_REG3_WAKE_FF_MT_1_BIT)))
#define GET_REG_CTRL_REG3_WAKE_FF_MT_2(REG)	(((REG) >> (REG_CTRL_REG3_WAKE_FF_MT_2_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_WAKE_FF_MT_2(REG)	((REG) |= (1UL << (REG_CTRL_REG3_WAKE_FF_MT_2_BIT)))
#define CLR_REG_CTRL_REG3_WAKE_FF_MT_2(REG)	((REG) &= ~(1UL << (REG_CTRL_REG3_WAKE_FF_MT_2_BIT)))
#define GET_REG_CTRL_REG3_IPOL(REG)			(((REG) >> (REG_CTRL_REG3_IPOL_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_IPOL(REG)			((REG) |= (1UL << (REG_CTRL_REG3_IPOL_BIT)))
#define CLR_REG_CTRL_REG3_IPOL(REG)			((REG) &= ~(1UL << (REG_CTRL_REG3_IPOL_BIT)))
#define GET_REG_CTRL_REG3_PP_OD(REG)			(((REG) >> (REG_CTRL_REG3_PP_OD_BIT)) & 0x01)
#define SET_REG_CTRL_REG3_PP_OD(REG)			((REG) |= (1UL << (REG_CTRL_REG3_PP_OD_BIT)))
#define CLR_REG_CTRL_REG3_PP_OD(REG)			((REG) &= ~(1UL << (REG_CTRL_REG3_PP_OD_BIT)))

/*
 **  CTRL_REG4 Interrupt Enable Register
 */
#define REG_CTRL_REG4             0x2D
//
#define REG_CTRL_REG4_INT_EN_ASLP_BIT       (7) // 1000 0000
#define REG_CTRL_REG4_INT_EN_FIFO_BIT       (6) // 0100 0000
#define REG_CTRL_REG4_INT_EN_TRANS_BIT      (5) // 0010 0000
#define REG_CTRL_REG4_INT_EN_LNDPRT_BIT     (4) // 0001 0000
#define REG_CTRL_REG4_INT_EN_PULSE_BIT      (3) // 0000 1000
#define REG_CTRL_REG4_INT_EN_FF_MT_1_BIT    (2) // 0000 0100
#define REG_CTRL_REG4_INT_EN_FF_MT_2_BIT    (1) // 0000 0010
#define REG_CTRL_REG4_INT_EN_DRDY_BIT       (0) // 0000 0001
//
#define REG_CTRL_REG4_INT_EN_ASLP_MASK      (0x80)
#define REG_CTRL_REG4_INT_EN_FIFO_MASK      (0x40)
#define REG_CTRL_REG4_INT_EN_TRANS_MASK     (0x20)
#define REG_CTRL_REG4_INT_EN_LNDPRT_MASK    (0x10)
#define REG_CTRL_REG4_INT_EN_PULSE_MASK     (0x08)
#define REG_CTRL_REG4_INT_EN_FF_MT_1_MASK   (0x04)
#define REG_CTRL_REG4_INT_EN_FF_MT_2_MASK   (0x02)
#define REG_CTRL_REG4_INT_EN_DRDY_MASK      (0x01)

#define GET_REG_CTRL_REG4_INT_EN_ASLP(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_ASLP_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_ASLP(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_ASLP_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_ASLP(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_ASLP_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_FIFO(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_FIFO_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_FIFO(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_FIFO_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_FIFO(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_FIFO_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_TRANS(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_TRANS_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_TRANS(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_TRANS_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_TRANS(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_TRANS_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_LNDPRT(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_LNDPRT_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_LNDPRT(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_LNDPRT_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_LNDPRT(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_LNDPRT_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_PULSE(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_PULSE_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_PULSE(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_PULSE_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_PULSE(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_PULSE_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_FF_MT_1(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_FF_MT_1_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_FF_MT_1(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_FF_MT_1_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_FF_MT_1(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_FF_MT_1_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_FF_MT_2(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_FF_MT_2_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_FF_MT_2(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_FF_MT_2_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_FF_MT_2(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_FF_MT_2_BIT)))
#define GET_REG_CTRL_REG4_INT_EN_DRDY(REG)			(((REG) >> (REG_CTRL_REG4_INT_EN_DRDY_BIT)) & 0x01)
#define SET_REG_CTRL_REG4_INT_EN_DRDY(REG)			((REG) |= (1UL << (REG_CTRL_REG4_INT_EN_DRDY_BIT)))
#define CLR_REG_CTRL_REG4_INT_EN_DRDY(REG)			((REG) &= ~(1UL << (REG_CTRL_REG4_INT_EN_DRDY_BIT)))

/*
 **  CTRL_REG5 Interrupt Configuration Register
 */
#define REG_CTRL_REG5             0x2E
//
#define REG_CTRL_REG5_INT_CFG_ASLP_BIT      (7)
#define REG_CTRL_REG5_INT_CFG_FIFO_BIT      (6)
#define REG_CTRL_REG5_INT_CFG_TRANS_BIT     (5)
#define REG_CTRL_REG5_INT_CFG_LNDPRT_BIT    (4)
#define REG_CTRL_REG5_INT_CFG_PULSE_BIT     (3)
#define REG_CTRL_REG5_INT_CFG_FF_MT_1_BIT   (2)
#define REG_CTRL_REG5_INT_CFG_FF_MT_2_BIT   (1)
#define REG_CTRL_REG5_INT_CFG_DRDY_BIT      (0)
//
#define REG_CTRL_REG5_INT_CFG_ASLP_MASK     (0x80) // 1000 0000
#define REG_CTRL_REG5_INT_CFG_FIFO_MASK     (0x40) // 0100 0000
#define REG_CTRL_REG5_INT_CFG_TRANS_MASK    (0x20) // 0010 0000
#define REG_CTRL_REG5_INT_CFG_LNDPRT_MASK   (0x10) // 0001 0000
#define REG_CTRL_REG5_INT_CFG_PULSE_MASK    (0x08) // 0000 1000
#define REG_CTRL_REG5_INT_CFG_FF_MT_1_MASK  (0x04) // 0000 0100
#define REG_CTRL_REG5_INT_CFG_FF_MT_2_MASK  (0x02) // 0000 0010
#define REG_CTRL_REG5_INT_CFG_DRDY_MASK     (0x01) // 0000 0001

#define GET_REG_CTRL_REG5_INT_CFG_ASLP(REG)			(((REG) >> (REG_CTRL_REG5_INT_CFG_ASLP_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_ASLP(REG)			((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_ASLP_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_ASLP(REG)			((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_ASLP_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_FIFO(REG)			(((REG) >> (REG_CTRL_REG5_INT_CFG_FIFO_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_FIFO(REG)			((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_FIFO_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_FIFO(REG)			((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_FIFO_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_TRANS(REG)		(((REG) >> (REG_CTRL_REG5_INT_CFG_TRANS_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_TRANS(REG)		((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_TRANS_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_TRANS(REG)		((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_TRANS_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_LNDPRT(REG)		(((REG) >> (REG_CTRL_REG5_INT_CFG_LNDPRT_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_LNDPRT(REG)		((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_LNDPRT_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_LNDPRT(REG)		((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_LNDPRT_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_PULSE(REG)		(((REG) >> (REG_CTRL_REG5_INT_CFG_PULSE_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_PULSE(REG)		((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_PULSE_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_PULSE(REG)		((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_PULSE_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_FF_MT_1(REG)		(((REG) >> (REG_CTRL_REG5_INT_CFG_FF_MT_1_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_FF_MT_1(REG)		((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_FF_MT_1_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_FF_MT_1(REG)		((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_FF_MT_1_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_FF_MT_2(REG)		(((REG) >> (REG_CTRL_REG5_INT_CFG_FF_MT_2_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_FF_MT_2(REG)		((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_FF_MT_2_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_FF_MT_2(REG)		((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_FF_MT_2_BIT)))
#define GET_REG_CTRL_REG5_INT_CFG_DRDY(REG)			(((REG) >> (REG_CTRL_REG5_INT_CFG_DRDY_BIT)) & 0x01)
#define SET_REG_CTRL_REG5_INT_CFG_DRDY(REG)			((REG) |= (1UL << (REG_CTRL_REG5_INT_CFG_DRDY_BIT)))
#define CLR_REG_CTRL_REG5_INT_CFG_DRDY(REG)			((REG) &= ~(1UL << (REG_CTRL_REG5_INT_CFG_DRDY_BIT)))

/*
 **  XYZ Offset Correction Registers
 */
#define REG_OFF_X             0x2F
#define REG_OFF_Y             0x30
#define REG_OFF_Z             0x31

#define CONVERT_TO_U16(value_2,value_1) ((uint16_t)((value_1 << 8) | value_2))

#define FRAC_2d1 5000
#define FRAC_2d2 2500
#define FRAC_2d3 1250
#define FRAC_2d4 625
#define FRAC_2d5 313
#define FRAC_2d6 156
#define FRAC_2d7 78
#define FRAC_2d8 39
#define FRAC_2d9 20
#define FRAC_2d10 10
#define FRAC_2d11 5
#define FRAC_2d12 2

/* * * * * * * * * * * * * * * Module Functions * * * * * * * * * * * * * * * */

/* Global Functions ----------------------------------------------------------*/
/* Status Rgister */

Std_ReturnType Drv_MMA845x_UpdateStatus(MMA845x_HandleTypeDef *hMMA845x);

Std_ReturnType Drv_MMA845x_UpdateSystemMode(MMA845x_HandleTypeDef *hMMA845x);

/* XYZ Data register */
Std_ReturnType Drv_MMA845x_XYZ(MMA845x_HandleTypeDef *hMMA845x);

/* INT Source register */
Std_ReturnType Drv_MMA845x_UpdateInterruptSource(MMA845x_HandleTypeDef *hMMA845x) ;

/* WHO_AM_I register */
Std_ReturnType Drv_MMA845x_GetDeviceID(MMA845x_HandleTypeDef *hMMA845x);

/* SYSMOD Status */
Std_ReturnType Drv_MMA845x_UpdateSystemMode(MMA845x_HandleTypeDef *hMMA845x);

/* XYZ_DATA_CFG Register */
Std_ReturnType Drv_MMA845x_SetDynamicRange(MMA845x_HandleTypeDef *hMMA845x,
		MMA845x_DynamicRange_TypeDef DynamicRange) ;
Std_ReturnType Drv_MMA845x_EnableHPF(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableHPF(MMA845x_HandleTypeDef *hMMA845x);

/* Control Register 1*/
Std_ReturnType Drv_MMA845x_EnableFastreadMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableFastreadMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableActiveMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableStandbyMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableLowNoiseMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableLowNoiseMode(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_SetDataRate(MMA845x_HandleTypeDef *hMMA845x,MMA845x_ODR_TypeDef OutputDataRate);
Std_ReturnType Drv_MMA845x_SetAutoSleepRate(MMA845x_HandleTypeDef *hMMA845x,MMA845x_ASLPR_TypeDef AutoSleepRate) ;

/* Control Register 2 */
Std_ReturnType Drv_MMA845x_EnableSelfTest(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableSelfTest(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_SoftReset(MMA845x_HandleTypeDef *hMMA845x) ;
Std_ReturnType Drv_MMA845x_EnableAutoSleep(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableAutoSleep(MMA845x_HandleTypeDef *hMMA845x) ;
Std_ReturnType Drv_MMA845x_SetActiveModePowerScheme(MMA845x_HandleTypeDef *hMMA845x, MMA845x_OVSM_TypeDef OverSamplingMode);
Std_ReturnType Drv_MMA845x_SetSleepModePowerScheme(MMA845x_HandleTypeDef *hMMA845x, MMA845x_OVSM_TypeDef OverSamplingMode);

/* Control Register 3 */
Std_ReturnType Drv_MMA845x_EnableIRQTransientWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableIRQTransientWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableIRQOrientationWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableIRQOrientationWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableIRQPulseWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableIRQPulseWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableIRQFreeFallMotionWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableIRQFreeFallMotionWakeUp(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_SetIRQPolarityActivehigh(MMA845x_HandleTypeDef *hMMA845x) ;
Std_ReturnType Drv_MMA845x_SetIRQPolariyActiveLow(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_SetIRQOpenDrain(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_SetIRQPushPull(MMA845x_HandleTypeDef *hMMA845x);

/* Control Register 4 */
Std_ReturnType Drv_MMA845x_EnableAutoSleepWakeUpIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableAutoSleepWakeUpIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableTransientIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableTransientIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableOrientationIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableOrientationIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnablePulseDetectionIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisablePulseDetectionIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableDataReadyIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableDataReadyIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_EnableFreefallMotionIRQ(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_DisableFreefallMotionIRQ(MMA845x_HandleTypeDef *hMMA845x);

/* Control Register 5 */
Std_ReturnType Drv_MMA845x_RouteAutoSleepIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteAutoSleepIRQInt2(MMA845x_HandleTypeDef *hMMA845x) ;
Std_ReturnType Drv_MMA845x_RouteTransientIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteTransientIRQInt2(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteOrientationIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteOrientationIRQInt2(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RoutePulseIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RoutePulseIRQInt2(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteFreefallMotionIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteFreefallMotionIRQInt2(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteDataReadyIRQInt1(MMA845x_HandleTypeDef *hMMA845x);
Std_ReturnType Drv_MMA845x_RouteDataReadyIRQInt2(MMA845x_HandleTypeDef *hMMA845x) ;









/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* MMA845X_INC_DRV_MMA845X_PRV_H_ */
