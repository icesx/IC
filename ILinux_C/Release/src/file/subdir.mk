################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/file/10.1.c \
../src/file/10.2.c \
../src/file/10.3.c \
../src/file/10.4.c \
../src/file/10.5eq1.c \
../src/file/10.6eq2.c \
../src/file/file.c \
../src/file/test.c 

OBJS += \
./src/file/10.1.o \
./src/file/10.2.o \
./src/file/10.3.o \
./src/file/10.4.o \
./src/file/10.5eq1.o \
./src/file/10.6eq2.o \
./src/file/file.o \
./src/file/test.o 

C_DEPS += \
./src/file/10.1.d \
./src/file/10.2.d \
./src/file/10.3.d \
./src/file/10.4.d \
./src/file/10.5eq1.d \
./src/file/10.6eq2.d \
./src/file/file.d \
./src/file/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/file/%.o: ../src/file/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


