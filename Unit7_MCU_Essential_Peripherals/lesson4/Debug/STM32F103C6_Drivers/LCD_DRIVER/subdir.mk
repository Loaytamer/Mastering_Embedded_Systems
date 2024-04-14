################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/LCD_DRIVER/LCD.c 

OBJS += \
./STM32F103C6_Drivers/LCD_DRIVER/LCD.o 

C_DEPS += \
./STM32F103C6_Drivers/LCD_DRIVER/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/LCD_DRIVER/LCD.o: ../STM32F103C6_Drivers/LCD_DRIVER/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"F:/Faculty of Engineering/Embeded Systems Diploma/Drivers/Drivers/STM32F103C6_Drivers/KEYPAD_DRIVER" -I"F:/Faculty of Engineering/Embeded Systems Diploma/Drivers/Drivers/HAL/includes" -I"F:/Faculty of Engineering/Embeded Systems Diploma/Drivers/Drivers/STM32F103C6_Drivers/LCD_DRIVER" -I"F:/Faculty of Engineering/Embeded Systems Diploma/Drivers/Drivers/HAL/includes" -I"F:/Faculty of Engineering/Embeded Systems Diploma/Drivers/Drivers/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/LCD_DRIVER/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

