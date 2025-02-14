/**
  @page PWR_SLEEP Power sleep Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_SLEEP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Power Sleep Mode example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description 
 
How to enter the Sleep mode and wake up from this mode by using an interrupt.

This example shows also how to configure the STM32L0xx system to measure 
SLEEP mode current consumption.

In the associated software, the system clock is set to 2 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.

In the associated software
  - the system clock is set to 2 MHz.
  - External lines 4 to 15 is configured to generate an interrupt on falling edge.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

The system enters SLEEP mode after 5 seconds and will wait for the User push-button is pressed
to wake up from SLEEP mode. Current consumption could be monitored through an amperemeter.

This behavior is repeated in an infinite loop.

    - SLEEP Mode
    =======================
          - System Running at 2 MHz
          - Code running from Internal FLASH
          - All peripherals OFF
          - Wakeup using EXTI Line (User push-button PC.13)

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@par Directory contents 

  - PWR/PWR_SLEEP/Inc/stm32l0xx_conf.h         HAL Configuration file
  - PWR/PWR_SLEEP/Inc/stm32l0xx_it.h           Header for stm32l0xx_it.c
  - PWR/PWR_SLEEP/Inc/main.h                   Header file for main.c
  - PWR/PWR_SLEEP/Src/system_stm32l0xx.c       STM32L0xx system clock configuration file
  - PWR/PWR_SLEEP/Src/stm32l0xx_it.c           Interrupt handlers
  - PWR/PWR_SLEEP/Src/main.c                   Main program

@par Hardware and Software environment

  - This example runs on STM32L07xx and STM32L08xx devices
      
  - This example has been tested with STMicroelectronics STM32L073RZ-Nucleo Rev C
    evaluation board and can be easily tailored to any other supported device 
    and development board.

  - STM32L073RZ-Nucleo Rev C Set-up
    - Use the User push-button connected to pin PC.13 (External lines 4 to 15)
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
