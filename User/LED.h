#ifndef _LED_H_
#define _LED_H_

void LED_Init(void);
void LED_Set(uint8_t LED_Num, uint8_t LED_State);
void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
void Delay_s(uint32_t s);

#endif
