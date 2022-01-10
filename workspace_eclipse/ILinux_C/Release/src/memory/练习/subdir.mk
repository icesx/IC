################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/memory/练习/3.4.c \
../src/memory/练习/3.5.c 

OBJS += \
./src/memory/练习/3.4.o \
./src/memory/练习/3.5.o 

C_DEPS += \
./src/memory/练习/3.4.d \
./src/memory/练习/3.5.d 


# Each subdirectory must supply rules for building sources it contributes
src/memory/练习/%.o: ../src/memory/练习/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


