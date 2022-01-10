################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/12.3/cli.c \
../src/socket/12.3/server.c 

OBJS += \
./src/socket/12.3/cli.o \
./src/socket/12.3/server.o 

C_DEPS += \
./src/socket/12.3/cli.d \
./src/socket/12.3/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/12.3/%.o: ../src/socket/12.3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


