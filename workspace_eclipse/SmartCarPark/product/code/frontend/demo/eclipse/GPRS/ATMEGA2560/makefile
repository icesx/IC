################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
GPRS.lss \

FLASH_IMAGE += \
GPRS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: GPRS.elf secondary-outputs

# Tool invocations
GPRS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-gcc -Wl,-Map,GPRS.map,--cref -mrelax -L"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/ATMEGA_LIB" -L"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib-Mine/ATMEGA_LIB" -mmcu=atmega2560 -o "GPRS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GPRS.lss: GPRS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GPRS.elf  >"GPRS.lss"
	@echo 'Finished building: $@'
	@echo ' '

GPRS.hex: GPRS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex GPRS.elf  "GPRS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GPRS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 GPRS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) GPRS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
