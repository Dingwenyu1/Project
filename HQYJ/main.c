#include "koala.h"
#include "LinkList.h"

int main(int argc, char const *argv[])
{
	// 初始化链表
	LinkList L;
	InitList(&L);
	LNode *p = L->next;

	while(1){
		if(GetService() == 1){
			Car user;
			InputInformation(p->data.name, p->data.plate);
			GetChoice(&p->data);
			GetIn(p);
		}else{
			GetOut(p);
			GetNode(L);
		}

	}


	// Car user;
	// InputInformation(user.name, user.plate);
	// GetChoice(&user);
	// user.time = GetTime();
	// user.money = GetMoney(user.type, user.time);
}