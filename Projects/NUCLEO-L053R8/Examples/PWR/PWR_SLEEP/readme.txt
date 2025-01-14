/**
  @page PWR_SLEEP Power Sleep Mode Example
  
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

In the associated software, the system clock is set to 16 MHz, the SysTick is 
programmed to generate an interrupt each 1 ms.

In the associated software
  - the system clock is set to 16 MHz
  - the EXTI_Line13 is configured to generate an interrupt on falling edge.
  - the SysTick is programmed to generate an interrupt each 1 ms. 

The system enters SLEEP mode after 5s and will wait for the Key push button is pressed
to wake up from SLEEP mode. Current consumption could be monitored through an amperemeter.

This behavior is repeated in an infinite loop.
 - LED2 ON: HAL configuration failed (system will go to an infinite loop)
 
    - SLEEP Mode
    ============ 
          - System Running at HSI (16MHz)
          - Flash 1 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - Wakeup using EXTI Line (Key Button PC.13)


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

  - PWR/PWR_SLEEP/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_SLEEP/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_SLEEP/Inc/main.h               header file for main.c
  - PWR/PWR_SLEEP/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_SLEEP/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_SLEEP/Src/main.c               Main program
  - PWR/PWR_SLEEP/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L051xx, STM32L052xx, STM32L053xx STM32L062xx and 
    STM32L063xx device lines RevZ
    
  - This example has been tested with STM32L053R8-Nucleo RevC  board and can be
    easily tailored to any other supported device and development board.

  - STM32L053R8-Nucleo Set-up
    - Use LED2 connected to PA.05 pin
    - Use the Key push-button connected to pin PC13 (EXTI_Line13)
    - Connect an amperemeter to JP6 to measure the IDD current

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
