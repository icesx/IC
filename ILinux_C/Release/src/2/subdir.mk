################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2/2.1ssys.c \
../src/2/2.2gxys.c \
../src/2/2.3fib.c \
../src/2/2.4max.c \
../src/2/2.5.c \
../src/2/2.6.c 

OBJS += \
./src/2/2.1ssys.o \
./src/2/2.2gxys.o \
./src/2/2.3fib.o \
./src/2/2.4max.o \
./src/2/2.5.o \
./src/2/2.6.o 

C_DEPS += \
./src/2/2.1ssys.d \
./src/2/2.2gxys.d \
./src/2/2.3fib.d \
./src/2/2.4max.d \
./src/2/2.5.d \
./src/2/2.6.d 


# Each subdirectory must supply rules for building sources it contributes
src/2/%.o: ../src/2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


