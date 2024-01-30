#include<stdio.h>
#include<stdlib.h>
#include"head.h"

void print(n *p){

	if(p->next!=NULL)
	{
		printf("Value of current node  =  %d   \n",p->val);

		if(p->next==NULL)
			printf("Last node number  =  %d \n",p->val);
		print(p->next);
	}
}

