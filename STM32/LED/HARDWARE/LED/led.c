#include "led.h"
#include "stm32f10x.h"


void LED_Init(void)
{
	// 定义一个GPIO type结构体类型
	GPIO_InitTypeDef GPIO_InitStructur;
	
	
	// 使能时钟
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOB, ENABLE);
	
	// 初始化GPIO type结构体(B 和E 通用)
	GPIO_InitStructur.GPIO_Mode = GPIO_Mode_Out_PP;	// 设置为推挽输出
	GPIO_InitStructur.GPIO_Pin = GPIO_Pin_5;	// 输出端口
	GPIO_InitStructur.GPIO_Speed = GPIO_Speed_50MHz;	// 设置输出速度
	
	
	// 初始化GPIOB
	GPIO_Init(GPIOB, &GPIO_InitStructur);
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	
	// 初始化GPIOE
	GPIO_Init(GPIOE, &GPIO_InitStructur);

}


