################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/socket/12.2/cli2.c \
../src/socket/12.2/serv.c 

OBJS += \
./src/socket/12.2/cli2.o \
./src/socket/12.2/serv.o 

C_DEPS += \
./src/socket/12.2/cli2.d \
./src/socket/12.2/serv.d 


# Each subdirectory must supply rules for building sources it contributes
src/socket/12.2/%.o: ../src/socket/12.2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


