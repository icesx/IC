################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/13/12/debug/input/getdata.c 

OBJS += \
./src/13/12/debug/input/getdata.o 

C_DEPS += \
./src/13/12/debug/input/getdata.d 


# Each subdirectory must supply rules for building sources it contributes
src/13/12/debug/input/%.o: ../src/13/12/debug/input/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


