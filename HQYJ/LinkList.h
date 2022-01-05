#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include "koala.h"



typedef struct node_t{
	Car data;
	struct node_t *next;
}LNode, *LinkList;


bool InitList(LinkList *L);
bool DestoryList(LinkList L);
LinkList InsertList_Tail(LNode *p, Car user);
void GetNode(LinkList L);

#endif