################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/LED_Animations/LED_Animations.c 

OBJS += \
./APP/LED_Animations/LED_Animations.o 

C_DEPS += \
./APP/LED_Animations/LED_Animations.d 


# Each subdirectory must supply rules for building sources it contributes
APP/LED_Animations/%.o: ../APP/LED_Animations/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


