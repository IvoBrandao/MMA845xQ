################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

