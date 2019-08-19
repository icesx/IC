################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/process/7.10setuid.c \
../src/process/7.11.c \
../src/process/7.1fork.c \
../src/process/7.2vfork.c \
../src/process/7.3execve.c \
../src/process/7.4execlp.c \
../src/process/7.5cffwait2.c \
../src/process/7.6pgid.c \
../src/process/7.7getpgid.c \
../src/process/7.8getuid.c \
../src/process/7.9getgid.c \
../src/process/new2.c 

OBJS += \
./src/process/7.10setuid.o \
./src/process/7.11.o \
./src/process/7.1fork.o \
./src/process/7.2vfork.o \
./src/process/7.3execve.o \
./src/process/7.4execlp.o \
./src/process/7.5cffwait2.o \
./src/process/7.6pgid.o \
./src/process/7.7getpgid.o \
./src/process/7.8getuid.o \
./src/process/7.9getgid.o \
./src/process/new2.o 

C_DEPS += \
./src/process/7.10setuid.d \
./src/process/7.11.d \
./src/process/7.1fork.d \
./src/process/7.2vfork.d \
./src/process/7.3execve.d \
./src/process/7.4execlp.d \
./src/process/7.5cffwait2.d \
./src/process/7.6pgid.d \
./src/process/7.7getpgid.d \
./src/process/7.8getuid.d \
./src/process/7.9getgid.d \
./src/process/new2.d 


# Each subdirectory must supply rules for building sources it contributes
src/process/%.o: ../src/process/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


