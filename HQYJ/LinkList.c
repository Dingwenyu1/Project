#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if(!*L){
		return false;
	}
	(*L)->next = NULL;
	return true;
}

bool DestoryList(LinkList L)
{
	LinkList temp;
	if(L == NULL){
		return false;
	}
	while(L){
		temp = L->next;
		free(L);
		L = temp;
	}
	return true;
}

// 尾插法创建链表
LinkList InsertList_Tail(LNode *p, Car user)
{
	LNode *temp;
	temp = (LNode *)malloc(sizeof(LNode));
	temp->data = user;
	temp->next = p->next;
	p->next = temp;

	return temp;	
}

// 获取节点信息
void GetNode(LinkList L)
{
	printf("Please enter your ");
	// 输入你的车牌号
	char *car_number;
	s_gets(car_number, MAXSIZE);


	LNode *p = L->next;
	while(p != NULL){
		if(!strcmp(car_number, p->data.plate)){
			PrintInformation(p->data);
		}else{
			p = p->next;
		}
	}
}