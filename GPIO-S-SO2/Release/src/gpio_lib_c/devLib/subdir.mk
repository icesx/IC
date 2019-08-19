################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio_lib_c/devLib/ds1302.c \
../src/gpio_lib_c/devLib/gertboard.c \
../src/gpio_lib_c/devLib/lcd.c \
../src/gpio_lib_c/devLib/lcd128x64.c \
../src/gpio_lib_c/devLib/maxdetect.c \
../src/gpio_lib_c/devLib/piFace.c \
../src/gpio_lib_c/devLib/piGlow.c \
../src/gpio_lib_c/devLib/piNes.c 

OBJS += \
./src/gpio_lib_c/devLib/ds1302.o \
./src/gpio_lib_c/devLib/gertboard.o \
./src/gpio_lib_c/devLib/lcd.o \
./src/gpio_lib_c/devLib/lcd128x64.o \
./src/gpio_lib_c/devLib/maxdetect.o \
./src/gpio_lib_c/devLib/piFace.o \
./src/gpio_lib_c/devLib/piGlow.o \
./src/gpio_lib_c/devLib/piNes.o 

C_DEPS += \
./src/gpio_lib_c/devLib/ds1302.d \
./src/gpio_lib_c/devLib/gertboard.d \
./src/gpio_lib_c/devLib/lcd.d \
./src/gpio_lib_c/devLib/lcd128x64.d \
./src/gpio_lib_c/devLib/maxdetect.d \
./src/gpio_lib_c/devLib/piFace.d \
./src/gpio_lib_c/devLib/piGlow.d \
./src/gpio_lib_c/devLib/piNes.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpio_lib_c/devLib/%.o: ../src/gpio_lib_c/devLib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DTINKER_BOARD -I/TOOLS/software/Raspberry/raspberry-toolchain/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/arm-bcm2708hardfp-linux-gnueabi/sysroot/usr/include -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/wiringPi" -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/devLib" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


