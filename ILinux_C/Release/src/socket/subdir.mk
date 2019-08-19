################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/client.c \
../src/socket/serv.c 

OBJS += \
./src/socket/client.o \
./src/socket/serv.o 

C_DEPS += \
./src/socket/client.d \
./src/socket/serv.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/%.o: ../src/socket/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


