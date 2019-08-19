################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mp3/Mp3.c 

OBJS += \
./src/mp3/Mp3.o 

C_DEPS += \
./src/mp3/Mp3.d 


# Each subdirectory must supply rules for building sources it contributes
src/mp3/%.o: ../src/mp3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


