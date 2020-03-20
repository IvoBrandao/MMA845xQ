################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/MMA845x/Src/drv_mma845x.c \
../BSP/MMA845x/Src/drv_mma845x_prv.c 

OBJS += \
./BSP/MMA845x/Src/drv_mma845x.o \
./BSP/MMA845x/Src/drv_mma845x_prv.o 

C_DEPS += \
./BSP/MMA845x/Src/drv_mma845x.d \
./BSP/MMA845x/Src/drv_mma845x_prv.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/MMA845x/Src/drv_mma845x.o: ../BSP/MMA845x/Src/drv_mma845x.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"BSP/MMA845x/Src/drv_mma845x.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
BSP/MMA845x/Src/drv_mma845x_prv.o: ../BSP/MMA845x/Src/drv_mma845x_prv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"BSP/MMA845x/Src/drv_mma845x_prv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

