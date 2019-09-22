################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP.c \
../APP_Project.c \
../DIO_prg.c \
../EXT0_prg.c \
../GIE_prg.c \
../RTO_porg.c \
../TIMER0_prog.c \
../TIMER_prog.c \
../main.c 

OBJS += \
./APP.o \
./APP_Project.o \
./DIO_prg.o \
./EXT0_prg.o \
./GIE_prg.o \
./RTO_porg.o \
./TIMER0_prog.o \
./TIMER_prog.o \
./main.o 

C_DEPS += \
./APP.d \
./APP_Project.d \
./DIO_prg.d \
./EXT0_prg.d \
./GIE_prg.d \
./RTO_porg.d \
./TIMER0_prog.d \
./TIMER_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


