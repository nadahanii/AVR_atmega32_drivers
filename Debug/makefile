################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS/subdir.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/TIMER2/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TEMP_SENSOR/subdir.mk
-include HAL/SWITCH/subdir.mk
-include HAL/STEPPER_MOTOR/subdir.mk
-include HAL/SEV_SEG/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include FreeRTOS/subdir.mk
-include APP/Simple_Calculator/subdir.mk
-include APP/Name_Wave/subdir.mk
-include APP/LED_Animations/subdir.mk
-include APP/DC_MOTOR_Rotaions/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Layered_Arch.lss \

FLASH_IMAGE += \
Layered_Arch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Layered_Arch.elf secondary-outputs

# Tool invocations
Layered_Arch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Layered_Arch.map -mmcu=atmega32 -o "Layered_Arch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Layered_Arch.lss: Layered_Arch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Layered_Arch.elf  >"Layered_Arch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Layered_Arch.hex: Layered_Arch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Layered_Arch.elf  "Layered_Arch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Layered_Arch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Layered_Arch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Layered_Arch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
