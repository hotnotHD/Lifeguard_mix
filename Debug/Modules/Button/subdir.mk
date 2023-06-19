################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/Button/button.c 

OBJS += \
./Modules/Button/button.o 

C_DEPS += \
./Modules/Button/button.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/Button/%.o Modules/Button/%.su: ../Modules/Button/%.c Modules/Button/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-Button

clean-Modules-2f-Button:
	-$(RM) ./Modules/Button/button.d ./Modules/Button/button.o ./Modules/Button/button.su

.PHONY: clean-Modules-2f-Button

