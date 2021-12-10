#include "led.h"
#include "stm32f10x.h"


void LED_Init(void)
{
	// ����һ��GPIO type�ṹ������
	GPIO_InitTypeDef GPIO_InitStructur;
	
	
	// ʹ��ʱ��
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOB, ENABLE);
	
	// ��ʼ��GPIO type�ṹ��(B ��E ͨ��)
	GPIO_InitStructur.GPIO_Mode = GPIO_Mode_Out_PP;	// ����Ϊ�������
	GPIO_InitStructur.GPIO_Pin = GPIO_Pin_5;	// ����˿�
	GPIO_InitStructur.GPIO_Speed = GPIO_Speed_50MHz;	// ��������ٶ�
	
	
	// ��ʼ��GPIOB
	GPIO_Init(GPIOB, &GPIO_InitStructur);
	// ����PB5Ĭ������²�����
	/* setBits�����ı��ʾ��ǽ�GPIOx.BSSRλ����Ϊpin�� ��GPIO.BSSRλ
	��һ��32λ�Ĵ����� ����16λ����λpin5�� Ҳ�ʹ������λ����ߵ�ƽ */
	GPIO_SetBits(GPIOB, GPIO_Pin_5);	
	
	// ��ʼ��GPIOE
	GPIO_Init(GPIOE, &GPIO_InitStructur);
	// ����PE5Ĭ������²�����
	GPIO_SetBits(GPIOE, GPIO_Pin_5);	

}


