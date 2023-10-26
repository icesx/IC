#include "common.h"
void MX_GPIO_Init(GPIO_TypeDef *GPIOx, void (*enable)(void))
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    enable();
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}