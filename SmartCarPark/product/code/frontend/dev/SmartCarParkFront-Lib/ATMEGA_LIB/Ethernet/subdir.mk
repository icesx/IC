################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ethernet/Dhcp.cpp \
../Ethernet/Dns.cpp \
../Ethernet/Ethernet.cpp \
../Ethernet/EthernetClient.cpp \
../Ethernet/EthernetServer.cpp \
../Ethernet/EthernetUdp.cpp 

OBJS += \
./Ethernet/Dhcp.o \
./Ethernet/Dns.o \
./Ethernet/Ethernet.o \
./Ethernet/EthernetClient.o \
./Ethernet/EthernetServer.o \
./Ethernet/EthernetUdp.o 

CPP_DEPS += \
./Ethernet/Dhcp.d \
./Ethernet/Dns.d \
./Ethernet/Ethernet.d \
./Ethernet/EthernetClient.d \
./Ethernet/EthernetServer.d \
./Ethernet/EthernetUdp.d 


# Each subdirectory must supply rules for building sources it contributes
Ethernet/%.o: ../Ethernet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/variants/mega" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/Ethernet" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SD" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SoftwareSerial" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/SPI" -I"/ICESX/workSpaceC/IC/SmartCarPark/product/code/frontend/dev/SmartCarParkFront-Lib/arduino" -DARDUINO_ARCH_AVR -DF_CPU=16000000L -Os -ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-exceptions -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


