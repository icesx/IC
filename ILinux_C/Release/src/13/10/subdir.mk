################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/13/10/calc.c \
../src/13/10/getdata.c \
../src/13/10/main.c \
../src/13/10/putdata.c 

OBJS += \
./src/13/10/calc.o \
./src/13/10/getdata.o \
./src/13/10/main.o \
./src/13/10/putdata.o 

C_DEPS += \
./src/13/10/calc.d \
./src/13/10/getdata.d \
./src/13/10/main.d \
./src/13/10/putdata.d 


# Each subdirectory must supply rules for building sources it contributes
src/13/10/%.o: ../src/13/10/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

