

/*
 *******************************************************************************
 * @file		: PlatformTypes.h
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


#ifndef PLATFORMTYPES_H_
#define PLATFORMTYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup GroupName
  * @{
  */

/* * * * * * * * * * * * * * *  Module Declarations * * * * * * * * * * * * * */

/* Includes ------------------------------------------------------------------*/

/* Global function prototypes ------------------------------------------------*/

/* Global Types & enums  -----------------------------------------------------*/
typedef enum
{
	E_NOT_OK = 0,
	E_OK,
}Std_ReturnType;
/* Global Defines & Macros ---------------------------------------------------*/


/* * * * * * * * * * * * * * * Module Functions * * * * * * * * * * * * * * * */

/* Global Functions ----------------------------------------------------------*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PLATFORMTYPES_H_ */
