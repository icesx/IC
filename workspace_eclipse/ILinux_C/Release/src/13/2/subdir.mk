################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/13/2/calc.c \
../src/13/2/getdata.c \
../src/13/2/main.c \
../src/13/2/putdata.c 

OBJS += \
./src/13/2/calc.o \
./src/13/2/getdata.o \
./src/13/2/main.o \
./src/13/2/putdata.o 

C_DEPS += \
./src/13/2/calc.d \
./src/13/2/getdata.d \
./src/13/2/main.d \
./src/13/2/putdata.d 


# Each subdirectory must supply rules for building sources it contributes
src/13/2/%.o: ../src/13/2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


