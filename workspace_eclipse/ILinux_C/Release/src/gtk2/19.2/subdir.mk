################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gtk2/19.2/login.c 

OBJS += \
./src/gtk2/19.2/login.o 

C_DEPS += \
./src/gtk2/19.2/login.d 


# Each subdirectory must supply rules for building sources it contributes
src/gtk2/19.2/%.o: ../src/gtk2/19.2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


