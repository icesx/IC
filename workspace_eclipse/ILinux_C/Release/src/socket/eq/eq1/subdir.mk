################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/eq/eq1/cli.c \
../src/socket/eq/eq1/server.c 

OBJS += \
./src/socket/eq/eq1/cli.o \
./src/socket/eq/eq1/server.o 

C_DEPS += \
./src/socket/eq/eq1/cli.d \
./src/socket/eq/eq1/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/eq/eq1/%.o: ../src/socket/eq/eq1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


