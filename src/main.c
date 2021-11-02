#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

void SysTick_Handler(void)//funcion tiempo de espera
{
    HAL_IncTick();
}


void Iniciacion_GPIO_LEDS(void){
    GPIO_InitTypeDef GPIO_InitStruct;
        __HAL_RCC_GPIOD_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_12 |  GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
}
void Iniciacion_GPIO_Pulsador(void){
    GPIO_InitTypeDef GPIO_InitStruct;
        __HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;

        HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}
int main(void)
{
	SysTick_Handler ();
	HAL_Init(); //Inicializo sistema
	Iniciacion_GPIO_LEDS ();//Llamo funcion para configurar leds
	Iniciacion_GPIO_Pulsador ();//Llamo funcion para configurar pulsador

  while (1)
    {
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,RESET);
	  HAL_Delay(100);
	  if ( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,SET);

	  }else{
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,RESET);

	  }

    }
}




