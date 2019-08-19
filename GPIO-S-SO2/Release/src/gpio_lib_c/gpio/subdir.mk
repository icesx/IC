################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio_lib_c/gpio/gpio.c \
../src/gpio_lib_c/gpio/pins.c \
../src/gpio_lib_c/gpio/readall.c 

OBJS += \
./src/gpio_lib_c/gpio/gpio.o \
./src/gpio_lib_c/gpio/pins.o \
./src/gpio_lib_c/gpio/readall.o 

C_DEPS += \
./src/gpio_lib_c/gpio/gpio.d \
./src/gpio_lib_c/gpio/pins.d \
./src/gpio_lib_c/gpio/readall.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpio_lib_c/gpio/%.o: ../src/gpio_lib_c/gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DTINKER_BOARD -I/TOOLS/software/Raspberry/raspberry-toolchain/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/arm-bcm2708hardfp-linux-gnueabi/sysroot/usr/include -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/wiringPi" -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/devLib" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


