################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gtk0/17.2/17.2.c 

OBJS += \
./src/gtk0/17.2/17.2.o 

C_DEPS += \
./src/gtk0/17.2/17.2.d 


# Each subdirectory must supply rules for building sources it contributes
src/gtk0/17.2/%.o: ../src/gtk0/17.2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


