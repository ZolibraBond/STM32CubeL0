/**
  @page TIM_OCToggle TIM_OCToggle example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCToggle/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four different 
  *          signals with four different frequencies.
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

Configuration of the TIM peripheral to generate four different 
signals at four different frequencies.

  The TIM2CLK frequency is set to SystemCoreClock, and the objective is
  to get TIM2 counter clock at 16 MHz so the Prescaler is computed as following:
     - Prescaler = (TIM2CLK / TIM2 counter clock) - 1
   
  SystemCoreClock is set to 32 MHz.

 The TIM2 CCR1 register value is equal to 40961: 
 CC1 update rate = TIM2 counter clock / CCR1_Val = 390.615 Hz,
 so the TIM2 Channel 1 generates a periodic signal with a frequency equal to 195.307 Hz.

The TIM2 CCR2 register is equal to 20480:
CC2 update rate = TIM2 counter clock / CCR2_Val = 781.25 Hz
so the TIM2 channel 2 generates a periodic signal with a frequency equal to 390.615 Hz.

The TIM2 CCR3 register is equal to 10240:
CC3 update rate = TIM2 counter clock / CCR3_Val = 1562.5 Hz
so the TIM2 channel 3 generates a periodic signal with a frequency equal to 781.25.9 Hz.

The TIM2 CCR4 register is equal to 5120:
CC4 update rate = TIM2 counter clock / CCR4_Val =  3125 Hz
so the TIM2 channel 4 generates a periodic signal with a frequency equal to 1562.5 Hz.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents  

  - TIM/TIM_OCToggle/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCToggle/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCToggle/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCToggle/Src/stm32l0xx_it.c          Interrupt handlers
  - TIM/TIM_OCToggle/Src/main.c                  Main program
  - TIM/TIM_OCToggle/Src/stm32l0xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCToggle/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO RevB  board and can be
    easily tailored to any other supported device and development board.
   
  - STM32L0538-DISCO RevB Set-up 
    - Connect the following pins to an oscilloscope to monitor the different 
      waveforms:
      - PA.00: (TIM2_CH1) 
      - PB.03: (TIM2_CH2) 
      - PB.10: (TIM2_CH3) 
      - PB.11: (TIM2_CH4) 



@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 



 */
