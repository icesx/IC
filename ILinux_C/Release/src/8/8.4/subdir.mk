################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/8/8.4/sl1.c \
../src/8/8.4/sl2.c 

OBJS += \
./src/8/8.4/sl1.o \
./src/8/8.4/sl2.o 

C_DEPS += \
./src/8/8.4/sl1.d \
./src/8/8.4/sl2.d 


# Each subdirectory must supply rules for building sources it contributes
src/8/8.4/%.o: ../src/8/8.4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

