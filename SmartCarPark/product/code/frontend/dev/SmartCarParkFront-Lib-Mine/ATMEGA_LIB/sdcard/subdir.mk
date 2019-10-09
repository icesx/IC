################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sdcard/SdCard.cpp 

OBJS += \
./sdcard/SdCard.o 

CPP_DEPS += \
./sdcard/SdCard.d 


# Each subdirectory must supply rules for building sources it contributes
sdcard/%.o: ../sdcard/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-gcc -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib-Mine" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Ethernet" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SD" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SPI" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -DF_CPU=16000000L -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


