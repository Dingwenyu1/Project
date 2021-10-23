/* 
与网络相关代码
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "main.h"
#include <pthread.h>

extern int g_sockfd;

// 线程函数
void *connect_cb(void *arg)
{
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = 8000;
	server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	int ret = connect(g_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
}


int InitSocket()
{
	// 创建socket，网络
	g_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(socket == -1){
		return FAILURE;
	}

	// 线程号
	pthread_t tid;
	// 启动线程向服务器发起连接
	int ret = pthread_creat(&tid, NULL, connect_cb, NULL);
	if(ret != 0){
		return FAILURE;
	}

}