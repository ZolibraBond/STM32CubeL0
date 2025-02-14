/**
  ******************************************************************************
  * @file    COMP/COMP_PWMSignalControl/Src/main.c 
  * @author  MCD Application Team
  * @brief   This example provides a short description of how to use the COMP 
  *          to control a PWM signal.
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
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/** @addtogroup STM32L0xx_HAL_Examples
  * @{
  */

/** @addtogroup COMP_PWMSignalControl
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
COMP_HandleTypeDef  hcomp1;
LPTIM_HandleTypeDef hlptim;
 
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void ErrorHandler(void);
static void COMP_Config(void);
static void TIM_Config(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /* STM32L0xx HAL library initialization:
       - Configure the Flash prefetch, Flash preread and Buffer caches
       - Systick timer is configured by default as source of time base, but user 
             can eventually implement his proper time base source (a general purpose 
             timer for example or other time source), keeping in mind that Time base 
             duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
             handled in milliseconds basis.
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure LED2 */
  BSP_LED_Init(LED2);

  /* Configure the system clock to 32 Mhz */
  SystemClock_Config();
  
  /* LPTIM Configuration */
  TIM_Config();
  
  /* Configure COMP */
  COMP_Config(); 
  
  /* Infinite loop */
  while (1)
  {}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = MSI
  *            SYSCLK(Hz)                     = 32000000
  *            HCLK(Hz)                       = 32000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            Flash Latency(WS)              = 0
  *            Main regulator output voltage  = Scale3 mode
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSI Oscillator and activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLL_DIV2;
  RCC_OscInitStruct.HSICalibrationValue = 0x10;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);  
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);
}

/**
  * @brief  Configures LP TIM
  * @param  None
  * @retval None
  */
static void TIM_Config(void)
{
  /*##-1- Configure the LPTIM peripheral #####################################*/ 
  hlptim.Instance = LPTIM1;
  
  hlptim.Init.Clock.Source    = LPTIM_CLOCKSOURCE_ULPTIM;
  hlptim.Init.Clock.Prescaler = LPTIM_PRESCALER_DIV1;  
  hlptim.Init.Trigger.Source  = LPTIM_TRIGSOURCE_SOFTWARE; 
  hlptim.Init.OutputPolarity  = LPTIM_OUTPUTPOLARITY_HIGH;
  hlptim.Init.UpdateMode      = LPTIM_UPDATE_IMMEDIATE;
  
  /* Initialize LPTIM peripheral according to the passed parameters */
  if (HAL_LPTIM_Init(&hlptim) != HAL_OK)
  {
    ErrorHandler();
  }
  /* ### - 2 - Start generating the PWM signal ############################## */
  /*
   *  Period = 99
   *  Pulse  = 49
   *  According to this configuration, the duty cycle will be equal to 50% and
   *  the output frequency will be equal to the input frequency divided by 100 
   *  since the LPTIM have to count 100 external clock edges each period.
   */
  if (HAL_LPTIM_PWM_Start(&hlptim, 99, 49) != HAL_OK)
  {
    ErrorHandler();
  }
}

/**
  * @brief  Configures Comparator
  * @param  None
  * @retval None
  */
static void COMP_Config(void)
{
  /*##-1- Configure the COMP peripheral ######################################*/  
 /* COMP1 configuration to be connected to LPTIM IN1 */

  /* Configure the COMP peripheral */  
  hcomp1.Instance = COMP1;
  hcomp1.Init.InvertingInput     = COMP_INPUT_MINUS_VREFINT;
  hcomp1.Init.NonInvertingInput  = COMP_INPUT_PLUS_IO1;
  hcomp1.Init.OutputPol          = COMP_OUTPUTPOL_NONINVERTED;
  hcomp1.Init.LPTIMConnection    = COMP_LPTIMCONNECTION_IN1_ENABLED;
  hcomp1.Init.Mode               = COMP_POWERMODE_ULTRALOWPOWER;
  hcomp1.Init.TriggerMode        = COMP_TRIGGERMODE_IT_RISING_FALLING;

  if(HAL_COMP_Init(&hcomp1) != HAL_OK)
  {
    /* Error */
    ErrorHandler();
  }

  /* Enable the Vrefint */
   HAL_COMPEx_EnableVREFINT();

  /* Start the COMP1 */  
  if(HAL_COMP_Start(&hcomp1) != HAL_OK)
  {
    /* Error */
    ErrorHandler();
  }
}

/**
  * @brief SYSTICK callback
  * @param None
  * @retval None
  */
void HAL_SYSTICK_Callback(void)
{
  HAL_IncTick();
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void ErrorHandler(void)
{
  while(1)
  {
    /* Toggle LED2 */
    BSP_LED_Toggle(LED2);
      
    /* Add a delay */
    HAL_Delay(100);
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */
