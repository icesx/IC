################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/9/9.2.c \
../src/9/9.3getcwd1.c \
../src/9/9.4mkdir1.c \
../src/9/9.5rmdir.c \
../src/9/9.6readdir.c \
../src/9/9.7link1.c \
../src/9/9.8.c \
../src/9/9.9.c 

OBJS += \
./src/9/9.2.o \
./src/9/9.3getcwd1.o \
./src/9/9.4mkdir1.o \
./src/9/9.5rmdir.o \
./src/9/9.6readdir.o \
./src/9/9.7link1.o \
./src/9/9.8.o \
./src/9/9.9.o 

C_DEPS += \
./src/9/9.2.d \
./src/9/9.3getcwd1.d \
./src/9/9.4mkdir1.d \
./src/9/9.5rmdir.d \
./src/9/9.6readdir.d \
./src/9/9.7link1.d \
./src/9/9.8.d \
./src/9/9.9.d 


# Each subdirectory must supply rules for building sources it contributes
src/9/%.o: ../src/9/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


