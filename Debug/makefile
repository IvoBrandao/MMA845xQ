################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include HAL_Driver/Src/subdir.mk
-include BSP/MMA845x/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MMA845xQ.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MMA845xQ.list \

OBJCOPY_BIN += \
MMA845xQ.bin \


# All Target
all: MMA845xQ.elf secondary-outputs

# Tool invocations
MMA845xQ.elf: $(OBJS) $(USER_OBJS) D:\Projects\MMA845xQ\LinkerScript.ld
	arm-none-eabi-gcc -o "MMA845xQ.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Projects\MMA845xQ\LinkerScript.ld" --specs=nosys.specs -Wl,-Map="MMA845xQ.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MMA845xQ.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MMA845xQ.list"
	@echo 'Finished building: $@'
	@echo ' '

MMA845xQ.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "MMA845xQ.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
