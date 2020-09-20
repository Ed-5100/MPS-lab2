################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c \
C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c 

OBJS += \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.o \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.o 

C_DEPS += \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.d \
./stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.o: C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -c -I"C:/Users/xieyu/Documents/Microprocessor/lab2/inc" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/xieyu/Documents/Microprocessor/stm32lib/STM32F7xx_HAL_Driver/Inc" -Og -ffunction-sections -Wall -Wdouble-promotion -fstack-usage -MMD -MP -MF"stm32lib/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

