################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/14/14.1/14.1.c 

OBJS += \
./src/14/14.1/14.1.o 

C_DEPS += \
./src/14/14.1/14.1.d 


# Each subdirectory must supply rules for building sources it contributes
src/14/14.1/%.o: ../src/14/14.1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


