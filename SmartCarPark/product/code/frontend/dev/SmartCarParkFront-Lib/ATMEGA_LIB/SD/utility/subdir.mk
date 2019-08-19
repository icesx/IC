################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SD/utility/Sd2Card.cpp \
../SD/utility/SdFile.cpp \
../SD/utility/SdVolume.cpp 

OBJS += \
./SD/utility/Sd2Card.o \
./SD/utility/SdFile.o \
./SD/utility/SdVolume.o 

CPP_DEPS += \
./SD/utility/Sd2Card.d \
./SD/utility/SdFile.d \
./SD/utility/SdVolume.d 


# Each subdirectory must supply rules for building sources it contributes
SD/utility/%.o: ../SD/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Ethernet" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SD" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SPI" -I"/ICESX/workSpaceC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -DARDUINO_ARCH_AVR -DF_CPU=16000000L -Os -ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-exceptions -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


