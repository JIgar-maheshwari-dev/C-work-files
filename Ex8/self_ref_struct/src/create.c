#include<stdio.h>
#include<stdlib.h>
#include"head.h"

void create(n *p){
	printf("\nEnter the number (999 for end) : ");
	scanf("%d",&p->val);
	
	if(p->val == 999)
		p->next=NULL;
	
	else
	{
		p->next=(n *)malloc(sizeof(n));
		create(p->next);
	}
}
