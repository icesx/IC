################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/memory/3.1realoc.c \
../src/memory/3.2memset.c \
../src/memory/3.3.c 

OBJS += \
./src/memory/3.1realoc.o \
./src/memory/3.2memset.o \
./src/memory/3.3.o 

C_DEPS += \
./src/memory/3.1realoc.d \
./src/memory/3.2memset.d \
./src/memory/3.3.d 


# Each subdirectory must supply rules for building sources it contributes
src/memory/%.o: ../src/memory/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


