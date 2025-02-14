/**
  @page CRYP_DMA  Encrypt and Decrypt data using AES Algo in ECB chaining
   mode using DMA
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    CRYP/CRYP_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CRYP AES Algorithm in ECB mode with DMA Example
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

How to use the CRYP peripheral to encrypt and decrypt data using the AES-128 
algorithm with ECB chaining mode in DMA mode.

DMA is used to transfer data from memory to the AES processor
input as well as to transfer data from AES processor output to memory.

64-byte buffers are ciphered and deciphered (4 AES blocks)
Ciphering/Deciphering with a 128-bit long key is used with data type set to 8-bit (byte swapping).

This example unrolls as follows: 
- AES Encryption (Plain Data --> Encrypted Data)
- AES Decryption with key derivation (Encrypted Data --> Decrypted Data)

LED2 is used to notify if the Encryption/Decryption failed

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

The Plain data, encrypted data and decrypted data can be displayed on a PC
HyperTerminal using the UART.

Other option terminal IO mode is only available for EWARM IAR tool chain 
(not available on ARM KEIL or SW4STM32 tool chain): Then the Plain data,
encrypted data and decrypted data can be displayed on debugger terminal IO
by uncomment following line in main file: 
/*#define TERMINAL_IO_OUT*/ 

@par Directory contents 

  - CRYP/CRYP_DMA/Inc/stm32l0xx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_DMA/Inc/stm32l0xx_it.h          Interrupt handlers header file
  - CRYP/CRYP_DMA/Inc/main.h                  Header for main.c module  
  - CRYP/CRYP_DMA/Src/stm32l0xx_it.c          Interrupt handlers
  - CRYP/CRYP_DMA/Src/main.c                  Main program
  - CRYP/CRYP_DMA/Src/stm32l0xx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_DMA/Src/system_stm32l0xx.c      STM32L0xx system source file


@par Hardware and Software environment

  - This example runs on STM32L083xx devices.

  - This example has been tested with STM32L073RZ-Nucleo Rev C board with socket using STM32L083xx plugged-in  
    and can be easily tailored to any other supported device and development board.
  
  - Hyperterminal configuration:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
@note: USUART1(COM1) is mapped on GPIO PA9(TX) and PA10(RX) 

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example



 */
