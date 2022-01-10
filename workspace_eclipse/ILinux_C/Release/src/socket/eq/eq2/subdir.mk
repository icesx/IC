################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/eq/eq2/host1.c 

OBJS += \
./src/socket/eq/eq2/host1.o 

C_DEPS += \
./src/socket/eq/eq2/host1.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/eq/eq2/%.o: ../src/socket/eq/eq2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


