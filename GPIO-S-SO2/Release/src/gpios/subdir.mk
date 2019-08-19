################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpios/gpio_mapping.c 

OBJS += \
./src/gpios/gpio_mapping.o 

C_DEPS += \
./src/gpios/gpio_mapping.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpios/%.o: ../src/gpios/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -DTINKER_BOARD -I/TOOLS/software/Raspberry/raspberry-toolchain/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/arm-bcm2708hardfp-linux-gnueabi/sysroot/usr/include -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/wiringPi" -I"/ICESX/workSpaceC/GPIO-S-SO2/src/gpio_lib_c/devLib" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


