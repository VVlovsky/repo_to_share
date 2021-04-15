################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/hal/stm32f4xx_hal.c \
../system/src/hal/stm32f4xx_hal_cortex.c \
../system/src/hal/stm32f4xx_hal_dma.c \
../system/src/hal/stm32f4xx_hal_dma_ex.c \
../system/src/hal/stm32f4xx_hal_exti.c \
../system/src/hal/stm32f4xx_hal_flash.c \
../system/src/hal/stm32f4xx_hal_flash_ex.c \
../system/src/hal/stm32f4xx_hal_flash_ramfunc.c \
../system/src/hal/stm32f4xx_hal_gpio.c \
../system/src/hal/stm32f4xx_hal_pwr.c \
../system/src/hal/stm32f4xx_hal_pwr_ex.c \
../system/src/hal/stm32f4xx_hal_rcc.c \
../system/src/hal/stm32f4xx_hal_rcc_ex.c \
../system/src/hal/stm32f4xx_hal_tim.c \
../system/src/hal/stm32f4xx_hal_tim_ex.c 

OBJS += \
./system/src/hal/stm32f4xx_hal.o \
./system/src/hal/stm32f4xx_hal_cortex.o \
./system/src/hal/stm32f4xx_hal_dma.o \
./system/src/hal/stm32f4xx_hal_dma_ex.o \
./system/src/hal/stm32f4xx_hal_exti.o \
./system/src/hal/stm32f4xx_hal_flash.o \
./system/src/hal/stm32f4xx_hal_flash_ex.o \
./system/src/hal/stm32f4xx_hal_flash_ramfunc.o \
./system/src/hal/stm32f4xx_hal_gpio.o \
./system/src/hal/stm32f4xx_hal_pwr.o \
./system/src/hal/stm32f4xx_hal_pwr_ex.o \
./system/src/hal/stm32f4xx_hal_rcc.o \
./system/src/hal/stm32f4xx_hal_rcc_ex.o \
./system/src/hal/stm32f4xx_hal_tim.o \
./system/src/hal/stm32f4xx_hal_tim_ex.o 

C_DEPS += \
./system/src/hal/stm32f4xx_hal.d \
./system/src/hal/stm32f4xx_hal_cortex.d \
./system/src/hal/stm32f4xx_hal_dma.d \
./system/src/hal/stm32f4xx_hal_dma_ex.d \
./system/src/hal/stm32f4xx_hal_exti.d \
./system/src/hal/stm32f4xx_hal_flash.d \
./system/src/hal/stm32f4xx_hal_flash_ex.d \
./system/src/hal/stm32f4xx_hal_flash_ramfunc.d \
./system/src/hal/stm32f4xx_hal_gpio.d \
./system/src/hal/stm32f4xx_hal_pwr.d \
./system/src/hal/stm32f4xx_hal_pwr_ex.d \
./system/src/hal/stm32f4xx_hal_rcc.d \
./system/src/hal/stm32f4xx_hal_rcc_ex.d \
./system/src/hal/stm32f4xx_hal_tim.d \
./system/src/hal/stm32f4xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/hal/%.o: ../system/src/hal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I../include -I../system/include -I../system/include/cmsis -I../system/include/hal -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


