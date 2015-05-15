#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
 
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);

}

