################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c 

OBJS += \
./stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.o 

C_DEPS += \
./stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -O0 -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

