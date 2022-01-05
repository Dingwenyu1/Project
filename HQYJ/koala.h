#ifndef _KOALA_H_
#define _KOALA_H_

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
#define STAR "**********"
// 定义价格 单位是$/s
#define RATE_A 20
#define RATE_B 15
#define RATE_C 10
#define RATE_D 5

typedef struct Car{
	// 定义名称
	char name[MAXSIZE];
	// 车牌号
	char plate[MAXSIZE];
	// 套餐类型
	char type;
	// 消耗时间
	int time;
	// 消耗的金钱
	int money;
}Car;


int GetService();
void PrintInformation(Car user);
char *s_gets(char *st, int n);
int GetMoney(char type, int time);
int GetTime();
bool GetChoice(Car *user);
void InputInformation(char *name, char *plate);

#endif
