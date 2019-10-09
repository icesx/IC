################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ultrasonic/subdir.mk
-include stepcounter/subdir.mk
-include src/subdir.mk
-include AFMotor/subdir.mk
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
NewRain-Smart-Car.lss \

FLASH_IMAGE += \
NewRain-Smart-Car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NewRain-Smart-Car.elf secondary-outputs

# Tool invocations
NewRain-Smart-Car.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-gcc -Wl,-Map,NewRain-Smart-Car.map,--cref -mrelax -Wl,--gc-sections -L"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/ATMEGA_LIB" -mmcu=atmega2560 -o "NewRain-Smart-Car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NewRain-Smart-Car.lss: NewRain-Smart-Car.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NewRain-Smart-Car.elf  >"NewRain-Smart-Car.lss"
	@echo 'Finished building: $@'
	@echo ' '

NewRain-Smart-Car.hex: NewRain-Smart-Car.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NewRain-Smart-Car.elf  "NewRain-Smart-Car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NewRain-Smart-Car.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 NewRain-Smart-Car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) NewRain-Smart-Car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
