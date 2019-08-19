################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/13/3/calc.c \
../src/13/3/getdata.c \
../src/13/3/main.c \
../src/13/3/putdata.c 

OBJS += \
./src/13/3/calc.o \
./src/13/3/getdata.o \
./src/13/3/main.o \
./src/13/3/putdata.o 

C_DEPS += \
./src/13/3/calc.d \
./src/13/3/getdata.d \
./src/13/3/main.d \
./src/13/3/putdata.d 


# Each subdirectory must supply rules for building sources it contributes
src/13/3/%.o: ../src/13/3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


