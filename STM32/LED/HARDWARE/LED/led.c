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
	// 设置PB5默认情况下不点亮
	/* setBits函数的本质就是将GPIOx.BSSR位设置为pin， 而GPIO.BSSR位
	是一个32位寄存器， 将低16位设置位pin5， 也就代表第五位输出高电平 */
	GPIO_SetBits(GPIOB, GPIO_Pin_5);	
	
	// 初始化GPIOE
	GPIO_Init(GPIOE, &GPIO_InitStructur);
	// 设置PE5默认情况下不点亮
	GPIO_SetBits(GPIOE, GPIO_Pin_5);	

}


