################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ethernet/http.cpp 

OBJS += \
./ethernet/http.o 

CPP_DEPS += \
./ethernet/http.d 


# Each subdirectory must supply rules for building sources it contributes
ethernet/%.o: ../ethernet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


