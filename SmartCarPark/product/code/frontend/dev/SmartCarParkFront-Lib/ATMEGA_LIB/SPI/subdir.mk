################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SPI/SPI.cpp 

OBJS += \
./SPI/SPI.o 

CPP_DEPS += \
./SPI/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
SPI/%.o: ../SPI/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Ethernet" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SD" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SPI" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -DARDUINO_ARCH_AVR -DF_CPU=16000000L -Os -ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-exceptions -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

