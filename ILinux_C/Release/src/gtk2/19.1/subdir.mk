################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gtk2/19.1/19.1.c \
../src/gtk2/19.1/复件\ 19.1.c 

OBJS += \
./src/gtk2/19.1/19.1.o \
./src/gtk2/19.1/复件\ 19.1.o 

C_DEPS += \
./src/gtk2/19.1/19.1.d \
./src/gtk2/19.1/复件\ 19.1.d 


# Each subdirectory must supply rules for building sources it contributes
src/gtk2/19.1/%.o: ../src/gtk2/19.1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/gtk2/19.1/复件\ 19.1.o: ../src/gtk2/19.1/复件\ 19.1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/gtk2/19.1/复件 19.1.d" -MT"src/gtk2/19.1/复件\ 19.1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


