#include "blink.h"
#include "common.h"

#define _GPIO_X GPIOB
void _enable(){
    __HAL_RCC_GPIOB_CLK_ENABLE();
}
void blink_init()
{
    MX_GPIO_Init(_GPIO_X, _enable);
}
void blink(uint32_t dalay, short pin_state)
{
    HAL_GPIO_WritePin(_GPIO_X, GPIO_PIN_5, pin_state);
    HAL_Delay(dalay);
}