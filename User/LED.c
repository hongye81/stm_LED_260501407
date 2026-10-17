#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_7;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Initstructure);
	GPIO_SetBits( GPIOA, GPIO_Pin_0);
	GPIO_SetBits( GPIOA, GPIO_Pin_1);
	GPIO_SetBits( GPIOA, GPIO_Pin_2);
	GPIO_SetBits( GPIOA, GPIO_Pin_3);
	GPIO_SetBits( GPIOA, GPIO_Pin_7);
}

void LED_Set( uint8_t LED_Num, uint8_t LED_State)
{
	switch (LED_Num)
	{
		case 0:
			if (LED_State)
			{GPIO_ResetBits( GPIOA, GPIO_Pin_0);}
			else
			{GPIO_SetBits( GPIOA, GPIO_Pin_0);}
		break;
		
		case 1:
		if (LED_State)
		{GPIO_ResetBits( GPIOA, GPIO_Pin_1);}
		else
		{GPIO_SetBits( GPIOA, GPIO_Pin_1);}
		break;
		
		case 2:
		if (LED_State)
		{GPIO_ResetBits( GPIOA, GPIO_Pin_2);}
		else
		{GPIO_SetBits( GPIOA, GPIO_Pin_2);}
		break;
		
		case 3:
		if (LED_State)
		{GPIO_ResetBits( GPIOA, GPIO_Pin_3);}
		else
		{GPIO_SetBits( GPIOA, GPIO_Pin_3);}
		break;
		
		case 7:
		if (LED_State)
		{GPIO_ResetBits( GPIOA, GPIO_Pin_7);}
		else
		{GPIO_SetBits( GPIOA, GPIO_Pin_7);}
		break;
	}
}

void Delay_us(uint32_t us)
{
	SysTick->LOAD = 72 * us;
	SysTick->VAL = 0x00;
	SysTick->CTRL = 0x00000005;
	while(!(SysTick->CTRL & 0x00010000));
	SysTick->CTRL = 0x00000004;
}

void Delay_ms(uint32_t ms)
{
	while(ms--)
	{Delay_us(1000);}
}

void Delay_s(uint32_t s)
{
	while(s--)
	{Delay_ms(1000);}
}
