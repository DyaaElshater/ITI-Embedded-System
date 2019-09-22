################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prg.c \
../EEPROM_prog.c \
../I2C_prog.c \
../LCD_cfg.c \
../LCD_prog.c \
../main_write.c 

OBJS += \
./DIO_prg.o \
./EEPROM_prog.o \
./I2C_prog.o \
./LCD_cfg.o \
./LCD_prog.o \
./main_write.o 

C_DEPS += \
./DIO_prg.d \
./EEPROM_prog.d \
./I2C_prog.d \
./LCD_cfg.d \
./LCD_prog.d \
./main_write.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


