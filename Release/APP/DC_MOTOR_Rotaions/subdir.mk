################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DC_MOTOR_Rotaions/DC_MOTOR_Rotaions.c 

OBJS += \
./APP/DC_MOTOR_Rotaions/DC_MOTOR_Rotaions.o 

C_DEPS += \
./APP/DC_MOTOR_Rotaions/DC_MOTOR_Rotaions.d 


# Each subdirectory must supply rules for building sources it contributes
APP/DC_MOTOR_Rotaions/%.o: ../APP/DC_MOTOR_Rotaions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


