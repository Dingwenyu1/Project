/*操作硬件设备*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcnt1.h>
// open的头文件
#include "main.h"

extern int g_buttonfd;
extern int g_ledfd;
extern int g_mixerfd;

int InitDriver()
{
	// 打开按键设备文件
	g_buttonfd = open("/dev/buttons", O_RDONLY);
	if(-1 == g_buttonfd){
		return FAILURE;
	}

	// 打开led设备文件
	g_ledfd = ("/dev/leds", O_WRONLY);
	if(-1 == g_ledfd){
		return FAILURE;
	}

	// 打开mixer设备文件
	g_mixerfd = open("/dev/mixer",O_WRONLY);
	if(-1 == g_mixerfd){
		return FAILURE;
	}

	return SUCCESS;
}