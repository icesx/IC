################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio_lib_c/wiringPi/drcSerial.c \
../src/gpio_lib_c/wiringPi/max31855.c \
../src/gpio_lib_c/wiringPi/max5322.c \
../src/gpio_lib_c/wiringPi/mcp23008.c \
../src/gpio_lib_c/wiringPi/mcp23016.c \
../src/gpio_lib_c/wiringPi/mcp23017.c \
../src/gpio_lib_c/wiringPi/mcp23s08.c \
../src/gpio_lib_c/wiringPi/mcp23s17.c \
../src/gpio_lib_c/wiringPi/mcp3002.c \
../src/gpio_lib_c/wiringPi/mcp3004.c \
../src/gpio_lib_c/wiringPi/mcp3422.c \
../src/gpio_lib_c/wiringPi/mcp4802.c \
../src/gpio_lib_c/wiringPi/pcf8574.c \
../src/gpio_lib_c/wiringPi/pcf8591.c \
../src/gpio_lib_c/wiringPi/piHiPri.c \
../src/gpio_lib_c/wiringPi/piThread.c \
../src/gpio_lib_c/wiringPi/sn3218.c \
../src/gpio_lib_c/wiringPi/softPwm.c \
../src/gpio_lib_c/wiringPi/softServo.c \
../src/gpio_lib_c/wiringPi/softTone.c \
../src/gpio_lib_c/wiringPi/sr595.c \
../src/gpio_lib_c/wiringPi/wiringPi.c \
../src/gpio_lib_c/wiringPi/wiringPiI2C.c \
../src/gpio_lib_c/wiringPi/wiringPiSPI.c \
../src/gpio_lib_c/wiringPi/wiringSerial.c \
../src/gpio_lib_c/wiringPi/wiringShift.c \
../src/gpio_lib_c/wiringPi/wiringTB.c \
../src/gpio_lib_c/wiringPi/wpiExtensions.c 

OBJS += \
./src/gpio_lib_c/wiringPi/drcSerial.o \
./src/gpio_lib_c/wiringPi/max31855.o \
./src/gpio_lib_c/wiringPi/max5322.o \
./src/gpio_lib_c/wiringPi/mcp23008.o \
./src/gpio_lib_c/wiringPi/mcp23016.o \
./src/gpio_lib_c/wiringPi/mcp23017.o \
./src/gpio_lib_c/wiringPi/mcp23s08.o \
./src/gpio_lib_c/wiringPi/mcp23s17.o \
./src/gpio_lib_c/wiringPi/mcp3002.o \
./src/gpio_lib_c/wiringPi/mcp3004.o \
./src/gpio_lib_c/wiringPi/mcp3422.o \
./src/gpio_lib_c/wiringPi/mcp4802.o \
./src/gpio_lib_c/wiringPi/pcf8574.o \
./src/gpio_lib_c/wiringPi/pcf8591.o \
./src/gpio_lib_c/wiringPi/piHiPri.o \
./src/gpio_lib_c/wiringPi/piThread.o \
./src/gpio_lib_c/wiringPi/sn3218.o \
./src/gpio_lib_c/wiringPi/softPwm.o \
./src/gpio_lib_c/wiringPi/softServo.o \
./src/gpio_lib_c/wiringPi/softTone.o \
./src/gpio_lib_c/wiringPi/sr595.o \
./src/gpio_lib_c/wiringPi/wiringPi.o \
./src/gpio_lib_c/wiringPi/wiringPiI2C.o \
./src/gpio_lib_c/wiringPi/wiringPiSPI.o \
./src/gpio_lib_c/wiringPi/wiringSerial.o \
./src/gpio_lib_c/wiringPi/wiringShift.o \
./src/gpio_lib_c/wiringPi/wiringTB.o \
./src/gpio_lib_c/wiringPi/wpiExtensions.o 

C_DEPS += \
./src/gpio_lib_c/wiringPi/drcSerial.d \
./src/gpio_lib_c/wiringPi/max31855.d \
./src/gpio_lib_c/wiringPi/max5322.d \
./src/gpio_lib_c/wiringPi/mcp23008.d \
./src/gpio_lib_c/wiringPi/mcp23016.d \
./src/gpio_lib_c/wiringPi/mcp23017.d \
./src/gpio_lib_c/wiringPi/mcp23s08.d \
./src/gpio_lib_c/wiringPi/mcp23s17.d \
./src/gpio_lib_c/wiringPi/mcp3002.d \
./src/gpio_lib_c/wiringPi/mcp3004.d \
./src/gpio_lib_c/wiringPi/mcp3422.d \
./src/gpio_lib_c/wiringPi/mcp4802.d \
./src/gpio_lib_c/wiringPi/pcf8574.d \
./src/gpio_lib_c/wiringPi/pcf8591.d \
./src/gpio_lib_c/wiringPi/piHiPri.d \
./src/gpio_lib_c/wiringPi/piThread.d \
./src/gpio_lib_c/wiringPi/sn3218.d \
./src/gpio_lib_c/wiringPi/softPwm.d \
./src/gpio_lib_c/wiringPi/softServo.d \
./src/gpio_lib_c/wiringPi/softTone.d \
./src/gpio_lib_c/wiringPi/sr595.d \
./src/gpio_lib_c/wiringPi/wiringPi.d \
./src/gpio_lib_c/wiringPi/wiringPiI2C.d \
./src/gpio_lib_c/wiringPi/wiringPiSPI.d \
./src/gpio_lib_c/wiringPi/wiringSerial.d \
./src/gpio_lib_c/wiringPi/wiringShift.d \
./src/gpio_lib_c/wiringPi/wiringTB.d \
./src/gpio_lib_c/wiringPi/wpiExtensions.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpio_lib_c/wiringPi/%.o: ../src/gpio_lib_c/wiringPi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DTINKER_BOARD -I/TOOLS/software/Raspberry/raspberry-toolchain/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/arm-bcm2708hardfp-linux-gnueabi/sysroot/usr/include -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/wiringPi" -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/devLib" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


