################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/12.1/client.c \
../src/socket/12.1/serv.c 

OBJS += \
./src/socket/12.1/client.o \
./src/socket/12.1/serv.o 

C_DEPS += \
./src/socket/12.1/client.d \
./src/socket/12.1/serv.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/12.1/%.o: ../src/socket/12.1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


