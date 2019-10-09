################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../stepcounter/stepcounter.cpp 

OBJS += \
./stepcounter/stepcounter.o 

CPP_DEPS += \
./stepcounter/stepcounter.d 


# Each subdirectory must supply rules for building sources it contributes
stepcounter/%.o: ../stepcounter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-gcc -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Servo" -I"/ICESX/workSpaceC/IC/INewrainRobot/code/demo/NewRain-Smart-Car/AFMotor" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -DARDUINO_AVR_MEGA2560 -DF_CPU=16000000L -DARDUINO_ARCH_AVR -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


