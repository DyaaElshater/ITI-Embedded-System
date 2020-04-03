################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prg.c \
../EXT0_prog.c \
../EXT1_prog.c \
../EXT2_prog.c \
../GIE_prog.c \
../INTmain.c 

OBJS += \
./DIO_prg.o \
./EXT0_prog.o \
./EXT1_prog.o \
./EXT2_prog.o \
./GIE_prog.o \
./INTmain.o 

C_DEPS += \
./DIO_prg.d \
./EXT0_prog.d \
./EXT1_prog.d \
./EXT2_prog.d \
./GIE_prog.d \
./INTmain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


