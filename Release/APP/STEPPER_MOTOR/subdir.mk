################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/STEPPER_MOTOR/STEPPER_MOTOR.c 

OBJS += \
./APP/STEPPER_MOTOR/STEPPER_MOTOR.o 

C_DEPS += \
./APP/STEPPER_MOTOR/STEPPER_MOTOR.d 


# Each subdirectory must supply rules for building sources it contributes
APP/STEPPER_MOTOR/%.o: ../APP/STEPPER_MOTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


