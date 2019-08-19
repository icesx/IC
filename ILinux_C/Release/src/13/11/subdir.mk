################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/13/11/main.c 

OBJS += \
./src/13/11/main.o 

C_DEPS += \
./src/13/11/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/13/11/%.o: ../src/13/11/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


