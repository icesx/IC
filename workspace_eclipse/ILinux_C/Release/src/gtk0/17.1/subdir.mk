################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gtk0/17.1/17.1.c 

OBJS += \
./src/gtk0/17.1/17.1.o 

C_DEPS += \
./src/gtk0/17.1/17.1.d 


# Each subdirectory must supply rules for building sources it contributes
src/gtk0/17.1/%.o: ../src/gtk0/17.1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


