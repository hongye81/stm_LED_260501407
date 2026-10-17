#include "stm32f10x.h"                  // Device header

#include "LED.h"

int main(void)
{	
	LED_Init();
	
	while (1)
	{
		LED_Set(0,1);
		Delay_ms(100);
		LED_Set(1,1);
		Delay_ms(100);
		LED_Set(2,1);
		Delay_ms(100);
		LED_Set(3,1);
		Delay_ms(100);
		LED_Set(7,1);
		Delay_ms(100);
		LED_Set(0,0);
		Delay_ms(100);
		LED_Set(1,0);
		Delay_ms(100);
		LED_Set(2,0);
		Delay_ms(100);
		LED_Set(3,0);
		Delay_ms(100);
		LED_Set(7,0);
		Delay_ms(100);
	}
	
}

