/**
  @page COMP_PulseWidthMeasurement COMP Pulse Width measurement example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    COMP/COMP_PulseWidthMeasurement/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the COMP COMP Pulse Width measurement example.
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

How to configure a comparator peripheral to measure pulse width. This method (measuring
signal pulses using a comparator) is useful when an external signal doesn't respect
the VIL and VIH levels.

  - COMP1 is configured as following:
     - Inverting input is internally connected to DAC output, used as a digital 
       threshold for measurement: voltage level can be tuned using
       defined label "COMP_THRESHOLD_MV" (set to 1V by default in this example).
     - Non Inverting input is connected to pin PA.01 (connected to pin 30 in CN7)
     - Output is internally connected to TIM2 Input Capture 4 (IC4)

  - TIM2 counter is used for pulse width measurement.
     - Timer frequency can be tuned using defined label "TIMER_FREQUENCY_HZ" (unit: Hz).
       Frequency the highest (maximum TIM2CLK PCLK1), accuracy pitch the lowest. 
       Maximum pulse length measurable is 65535*pitch
       (if timer set to 100kHz, pulse length measurable is min=10us, max=650ms)
     - TIM2 channel 4 is configured in input capture mode.
       TIM2 counter is captured at each transition detection: rising and falling edges
       (each time COMP1 inverting input crosses non-inverting input connected to DAC output)

  - STM32L073RZ-Nucleo Rev C Set-up
      - With a signal generator, provide the signal on COMP1 non-inverting input (pin PA.01)
      - Generate a square signal at 250Hz with pulses of 2 ms,and check that the LED2 turn on.
      - Generate a square signal at 500Hz with pulses of 1 ms,and check that the LED2 turn off.

STM32L073RZ-Nucleo Rev C board's LED is used to monitor the program execution status:
 - Normal operation: LED2 is turned-on/off in function of ADC conversion
   result.
    - Turn-off if pulse width is out of the expected range 2ms +- 0.5ms
    - Turn-on if pulse width is within the expected range 2ms +- 0.5ms
 - Error: In case of error, LED2 is toggling at a frequency of 1Hz.
 


@note To have a precise value of the pulse, HSI as a source of clock system should be 
calibrated or use an external clock.


@note Care must be taken when using HAL_Delay(), this function provides 
      accurate delay (in milliseconds) based on variable incremented in SysTick ISR. 
      This implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower) than the 
      peripheral interrupt. Otherwise the caller ISR process will be blocked. 
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set 
      to 1 millisecond to have correct HAL operation.

@par Directory contents 

  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - COMP/COMP_PulseWidthMeasurement/Inc/stm32l0xx_it.h          COMP interrupt handlers header file
  - COMP/COMP_PulseWidthMeasurement/Inc/main.h                  Header for main.c module
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_it.c          COMP interrupt handlers
  - COMP/COMP_PulseWidthMeasurement/Src/main.c                  Main program
  - COMP/COMP_PulseWidthMeasurement/Src/stm32l0xx_hal_msp.c     HAL MSP file 
  - COMP/COMP_PulseWidthMeasurement/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment 

  - This example runs on STM32L073xx devices.

  - This example has been tested with STM32L073RZ-Nucleo Rev C board and can be
    easily tailored to any other supported device and development board.
    
  - In this example, the clock is set to 2 MHz.
    
  

   

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 */