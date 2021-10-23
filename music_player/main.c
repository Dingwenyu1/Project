#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "device.h"

// 全局变量按键的fd
int g_bottonfd;
// led的fd
int g_ledfd;
// 音量fd
int g_mixerfd;
// 客户端使用的网络全局变量fd
int g_sockfd;

int main(int argc, char const *argv[])
{
	int ret;
	ret = InitDriver();
	// 打开设备文件

	if(ret == FAILURE){
		printf("init fail");
		exit(1);
	}

	// 初始化网络
	// ret = InitSocket();

	// 按键的设备文件
	return 0;
}