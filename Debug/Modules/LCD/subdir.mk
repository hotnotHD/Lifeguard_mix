################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/LCD/ili9488.c \
../Modules/LCD/lcd_io_spi.c \
../Modules/LCD/stm32_adafruit_lcd.c 

OBJS += \
./Modules/LCD/ili9488.o \
./Modules/LCD/lcd_io_spi.o \
./Modules/LCD/stm32_adafruit_lcd.o 

C_DEPS += \
./Modules/LCD/ili9488.d \
./Modules/LCD/lcd_io_spi.d \
./Modules/LCD/stm32_adafruit_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/LCD/%.o Modules/LCD/%.su: ../Modules/LCD/%.c Modules/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-LCD

clean-Modules-2f-LCD:
	-$(RM) ./Modules/LCD/ili9488.d ./Modules/LCD/ili9488.o ./Modules/LCD/ili9488.su ./Modules/LCD/lcd_io_spi.d ./Modules/LCD/lcd_io_spi.o ./Modules/LCD/lcd_io_spi.su ./Modules/LCD/stm32_adafruit_lcd.d ./Modules/LCD/stm32_adafruit_lcd.o ./Modules/LCD/stm32_adafruit_lcd.su

.PHONY: clean-Modules-2f-LCD

