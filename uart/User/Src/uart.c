#include "stm32f4xx_hal.h"
#include "uart.h"

UART_HandleTypeDef uart2;

void UART_Init(void)
{
	GPIO_InitTypeDef gpio;
	
	__GPIOA_CLK_ENABLE();
	__USART2_CLK_ENABLE();
	
	gpio.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	gpio.Alternate = GPIO_AF7_USART2;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pull = GPIO_PULLUP;
	gpio.Speed = GPIO_SPEED_LOW;
	
	HAL_GPIO_Init(GPIOA, &gpio);
	
	uart2.Instance = USART2;
	
	uart2.Init.BaudRate = 115200;
	uart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart2.Init.Mode = UART_MODE_TX_RX;
	uart2.Init.OverSampling = UART_OVERSAMPLING_16;
	uart2.Init.Parity = UART_PARITY_NONE;
	uart2.Init.StopBits = UART_STOPBITS_1;
	uart2.Init.WordLength = UART_WORDLENGTH_8B;
	
	HAL_UART_Init(&uart2);
	
	
	
	
}




