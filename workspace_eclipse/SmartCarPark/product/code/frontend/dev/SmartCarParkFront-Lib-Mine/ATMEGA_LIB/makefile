################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include serialcamera/subdir.mk
-include sdcard/subdir.mk
-include gprs/subdir.mk
-include ethernet/subdir.mk
-include base/subdir.mk
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
libSmartCarParkFront-Lib-Mine.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libSmartCarParkFront-Lib-Mine.a secondary-outputs

# Tool invocations
libSmartCarParkFront-Lib-Mine.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libSmartCarParkFront-Lib-Mine.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libSmartCarParkFront-Lib-Mine.lss: libSmartCarParkFront-Lib-Mine.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libSmartCarParkFront-Lib-Mine.a  >"libSmartCarParkFront-Lib-Mine.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libSmartCarParkFront-Lib-Mine.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 libSmartCarParkFront-Lib-Mine.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(ARCHIVES)$(S_DEPS)$(LSS)$(C_DEPS)$(CC_DEPS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) libSmartCarParkFront-Lib-Mine.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
