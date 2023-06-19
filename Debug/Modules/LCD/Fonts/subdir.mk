################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/LCD/Fonts/font12.c \
../Modules/LCD/Fonts/font16.c \
../Modules/LCD/Fonts/font20.c \
../Modules/LCD/Fonts/font20_rus.c \
../Modules/LCD/Fonts/font24.c \
../Modules/LCD/Fonts/font8.c \
../Modules/LCD/Fonts/font_arial_20.c 

OBJS += \
./Modules/LCD/Fonts/font12.o \
./Modules/LCD/Fonts/font16.o \
./Modules/LCD/Fonts/font20.o \
./Modules/LCD/Fonts/font20_rus.o \
./Modules/LCD/Fonts/font24.o \
./Modules/LCD/Fonts/font8.o \
./Modules/LCD/Fonts/font_arial_20.o 

C_DEPS += \
./Modules/LCD/Fonts/font12.d \
./Modules/LCD/Fonts/font16.d \
./Modules/LCD/Fonts/font20.d \
./Modules/LCD/Fonts/font20_rus.d \
./Modules/LCD/Fonts/font24.d \
./Modules/LCD/Fonts/font8.d \
./Modules/LCD/Fonts/font_arial_20.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/LCD/Fonts/%.o Modules/LCD/Fonts/%.su: ../Modules/LCD/Fonts/%.c Modules/LCD/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modules-2f-LCD-2f-Fonts

clean-Modules-2f-LCD-2f-Fonts:
	-$(RM) ./Modules/LCD/Fonts/font12.d ./Modules/LCD/Fonts/font12.o ./Modules/LCD/Fonts/font12.su ./Modules/LCD/Fonts/font16.d ./Modules/LCD/Fonts/font16.o ./Modules/LCD/Fonts/font16.su ./Modules/LCD/Fonts/font20.d ./Modules/LCD/Fonts/font20.o ./Modules/LCD/Fonts/font20.su ./Modules/LCD/Fonts/font20_rus.d ./Modules/LCD/Fonts/font20_rus.o ./Modules/LCD/Fonts/font20_rus.su ./Modules/LCD/Fonts/font24.d ./Modules/LCD/Fonts/font24.o ./Modules/LCD/Fonts/font24.su ./Modules/LCD/Fonts/font8.d ./Modules/LCD/Fonts/font8.o ./Modules/LCD/Fonts/font8.su ./Modules/LCD/Fonts/font_arial_20.d ./Modules/LCD/Fonts/font_arial_20.o ./Modules/LCD/Fonts/font_arial_20.su

.PHONY: clean-Modules-2f-LCD-2f-Fonts

