################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/robot.cpp 

OBJS += \
./src/robot.o 

CPP_DEPS += \
./src/robot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -DF_CPU=16000000L -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


