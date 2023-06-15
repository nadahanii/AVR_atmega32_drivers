################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Simple_Calculator/Simple_Calculator.c 

OBJS += \
./APP/Simple_Calculator/Simple_Calculator.o 

C_DEPS += \
./APP/Simple_Calculator/Simple_Calculator.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Simple_Calculator/%.o: ../APP/Simple_Calculator/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


