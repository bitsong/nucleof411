#include "stm32f4xx_hal.h"
#include "key.h"

extern uint16_t led_delay;

void Key_Init(void)
{
	GPIO_InitTypeDef gpio;
	
	__GPIOC_CLK_ENABLE();
	__GPIOH_CLK_ENABLE();
	
	
	gpio.Pin = GPIO_PIN_13;
	gpio.Mode = GPIO_MODE_IT_FALLING;
	gpio.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOC, &gpio);
	
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	
	
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_13)
	{
		if(led_delay == 100)
			led_delay = 500;
		else
			led_delay = 100;
	}
	
}

