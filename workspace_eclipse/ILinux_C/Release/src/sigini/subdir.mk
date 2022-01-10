################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sigini/11.1.c \
../src/sigini/11.2.c \
../src/sigini/11.3.c \
../src/sigini/11.4练习mysleep.c 

OBJS += \
./src/sigini/11.1.o \
./src/sigini/11.2.o \
./src/sigini/11.3.o \
./src/sigini/11.4练习mysleep.o 

C_DEPS += \
./src/sigini/11.1.d \
./src/sigini/11.2.d \
./src/sigini/11.3.d \
./src/sigini/11.4练习mysleep.d 


# Each subdirectory must supply rules for building sources it contributes
src/sigini/%.o: ../src/sigini/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


