################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IDReader/IDReader.cpp 

OBJS += \
./IDReader/IDReader.o 

CPP_DEPS += \
./IDReader/IDReader.d 


# Each subdirectory must supply rules for building sources it contributes
IDReader/%.o: ../IDReader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Ethernet" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SD" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SPI" -I"/ICESX/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib-Mine" -DARDUINO_ARCH_AVR -DF_CPU=16000000L -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


