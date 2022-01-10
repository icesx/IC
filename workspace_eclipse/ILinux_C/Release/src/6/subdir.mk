################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/6/6.1test.c \
../src/6/6.2year.c 

OBJS += \
./src/6/6.1test.o \
./src/6/6.2year.o 

C_DEPS += \
./src/6/6.1test.d \
./src/6/6.2year.d 


# Each subdirectory must supply rules for building sources it contributes
src/6/%.o: ../src/6/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


