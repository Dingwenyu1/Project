#include "koala.h"






/**args: 输入信息函数
 * para:	1. name: 名称
 * 		 	2. plate： 车牌号
 */
void InputInformation(char *name, char *plate)
{
	getchar();
	printf("Please enter your name\n");
	s_gets(name, MAXSIZE);
	printf("Please enter your plate\n");
	s_gets(plate, MAXSIZE);
}


char *s_gets(char *st, int n)
{
	char *result;
	int i = 0;

	result = fgets(st, n, stdin);
	if(result){
		while(st[i] != '\n' && st[i] != '\0')
			i ++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return result;
}

/**args: 判断停车价格类型
 * para：type： 停车价格类型
 * retval: bool值， 判断程序是执行
 */
bool GetChoice(Car *user)
{
FLAG:
	printf("Please enter your choice\n");
	scanf("%c", &user->type);
	if(user->type == 'a' || user->type == 'b' || user->type == 'c' || user->type == 'd'){
		return TRUE; 
	}else{
		printf("Your choice is wrong\n");
		goto FLAG;
	}
}

/**args：计算停车时长
 * retval: 停车时长
 */
int GetTime()
{
	// 获取停车前的时间
	// time_t类型是一个long类型的变量， 用该变量可以获取系统时间
	time_t preview_time;
	// 定义一个tm类型的指针变量p， 用来保存转换后的计时前的时间
	struct tm *p = NULL;
	// 调用time函数， 获取计时前的时间
	preview_time = time(NULL);
	// 转换函数， 将计时之前的转换成为结构体类型
	p = localtime(&preview_time);
	printf("Time counting is started\n");
	// 定义一个temp变量， 用来暂时保存计时之前的时间
	struct tm temp;
	temp.tm_sec = p->tm_sec;

	getchar();
	while(1){
		if(getchar()){
			break;
		}
	}

	time_t last_time;
	// tm类型变量q， 用来保存即使之后的时间
	struct tm *q = NULL;
	last_time = time(NULL);
	q = localtime(&last_time);

	

	int difference;
	// 将计时之前的时间和计时之后的时间相减
	difference= q->tm_sec - temp.tm_sec;


	return difference;
}

/**
 * para:	1. type: 表示当前的停车价格
 * 			2. time: 表示当前的停车时间
 * retval: 所需要的金钱
 */
int GetMoney(char type, int time)
{
	int money = 0;
	if(type == 'a'){
		money = time * RATE_A;
	}else if(type == 'b'){
		money = time * RATE_B;
	}else if(type == 'c'){
		money = time * RATE_C;
	}else if(type == 'd'){
		money = time * RATE_D;
	}

	return money;
}

// 打印输出函数
void PrintInformation(Car user)
{
	printf("%s\n", STAR);
	printf("Your name is %s\n", user.name);
	printf("Your plate number is %s\n", user.plate);
	printf("Your type choice is Type.%c\n", user.type);
	printf("The time you costed is %d\n", user.time);
	printf("The money you costed is %d\n", user.money);

}

int GetService()
{
	int service;
	printf("Do you want to park\n");
	printf("1 --> Vehicle approach\n");
	printf("0 --> Vehicle exit\n");

FLAGS1:
	scanf("%d", &service);
	if(service != 1 && service != 0){
		printf("Your input is wrong\n");
		goto FLAGS1;
	}
	if(service == 1){
		return 1;
	}else if(service == 0){
		return 0;
	}

	return 1;
}

void GetIn(LNode *p)
{
	// 获取停车前的时间
	// time_t类型是一个long类型的变量， 用该变量可以获取系统时间
	time_t preview_time;
	// 定义一个tm类型的指针变量p， 用来保存转换后的计时前的时间
	struct tm *q = NULL;
	// 调用time函数， 获取计时前的时间
	preview_time = time(NULL);
	// 转换函数， 将计时之前的转换成为结构体类型
	q = localtime(&preview_time);
	printf("Time counting is started\n");
	// 定义一个temp变量， 用来暂时保存计时之前的时间
	struct tm temp;
	temp.tm_sec = q->tm_sec;

	p->data.time = temp.tm_sec;
}

void GetOut(LNode *p)
{
	// 获取当前前的时间
	// time_t类型是一个long类型的变量， 用该变量可以获取系统时间
	time_t preview_time;
	// 定义一个tm类型的指针变量p， 用来保存转换后的计时前的时间
	struct tm *q = NULL;
	// 调用time函数， 获取计时前的时间
	preview_time = time(NULL);
	// 转换函数， 将计时之前的转换成为结构体类型
	q = localtime(&preview_time);
	printf("Time counting is started\n");
	// 定义一个temp变量， 用来暂时保存计时之前的时间
	struct tm temp;
	temp.tm_sec = q->tm_sec;


	p->data.time = temp.tm_sec - p->data.time;
	p->data.money = GetMoney(p->data.type, p->data.time);
}