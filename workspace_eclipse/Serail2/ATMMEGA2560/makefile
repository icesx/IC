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
Serail2.lss \

FLASH_IMAGE += \
Serail2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Serail2.elf secondary-outputs

# Tool invocations
Serail2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,Serail2.map,--cref -mrelax -Wl,--gc-sections -L"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/ATMEGA_LIB" -mmcu=atmega2560 -o "Serail2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Serail2.lss: Serail2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Serail2.elf  >"Serail2.lss"
	@echo 'Finished building: $@'
	@echo ' '

Serail2.hex: Serail2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Serail2.elf  "Serail2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Serail2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 Serail2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) Serail2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
