################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/8/8.1single.c \
../src/8/8.2a.c \
../src/8/8.3share5.c \
../src/8/8.5msg1.c \
../src/8/8.6.c \
../src/8/8.7.c 

OBJS += \
./src/8/8.1single.o \
./src/8/8.2a.o \
./src/8/8.3share5.o \
./src/8/8.5msg1.o \
./src/8/8.6.o \
./src/8/8.7.o 

C_DEPS += \
./src/8/8.1single.d \
./src/8/8.2a.d \
./src/8/8.3share5.d \
./src/8/8.5msg1.d \
./src/8/8.6.d \
./src/8/8.7.d 


# Each subdirectory must supply rules for building sources it contributes
src/8/%.o: ../src/8/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


