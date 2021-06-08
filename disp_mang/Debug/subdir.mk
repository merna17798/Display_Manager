################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SPI.c \
../TC72.c \
../TC72_cfg.c \
../disp_mang.c \
../keypad.c \
../lcd.c 

OBJS += \
./SPI.o \
./TC72.o \
./TC72_cfg.o \
./disp_mang.o \
./keypad.o \
./lcd.o 

C_DEPS += \
./SPI.d \
./TC72.d \
./TC72_cfg.d \
./disp_mang.d \
./keypad.d \
./lcd.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


