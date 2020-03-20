################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio.c \
../src/i2c.c \
../src/main.c \
../src/stm32l4xx_hal_msp.c \
../src/stm32l4xx_it.c \
../src/syscalls.c \
../src/system_stm32l4xx.c \
../src/usart.c \
../src/wwdg.c 

OBJS += \
./src/gpio.o \
./src/i2c.o \
./src/main.o \
./src/stm32l4xx_hal_msp.o \
./src/stm32l4xx_it.o \
./src/syscalls.o \
./src/system_stm32l4xx.o \
./src/usart.o \
./src/wwdg.o 

C_DEPS += \
./src/gpio.d \
./src/i2c.d \
./src/main.d \
./src/stm32l4xx_hal_msp.d \
./src/stm32l4xx_it.d \
./src/syscalls.d \
./src/system_stm32l4xx.d \
./src/usart.d \
./src/wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpio.o: ../src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/i2c.o: ../src/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/main.o: ../src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/stm32l4xx_hal_msp.o: ../src/stm32l4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/stm32l4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/stm32l4xx_it.o: ../src/stm32l4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/stm32l4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/syscalls.o: ../src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/system_stm32l4xx.o: ../src/system_stm32l4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/system_stm32l4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/usart.o: ../src/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/wwdg.o: ../src/wwdg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c11 -g3 -DSTM32 -DSTM32L4 -DSTM32L476RGTx -DDEBUG -DSTM32L476xx -DUSE_HAL_DRIVER -c -I"D:/Projects/MMA845xQ/HAL_Driver/Inc/Legacy" -I"D:/Projects/MMA845xQ/BSP/MMA845x/Inc/" -I"D:/Projects/MMA845xQ/inc" -I"D:/Projects/MMA845xQ/CMSIS/device" -I"D:/Projects/MMA845xQ/CMSIS/core" -I"D:/Projects/MMA845xQ/HAL_Driver/Inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/wwdg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

