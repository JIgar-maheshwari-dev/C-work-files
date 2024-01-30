#include<stdio.h>
#include<stdlib.h>
#include"head.h"

void print_n(n *p){
	
	int n;
	printf("\nEnter index : ");
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		p=p->next;			
	}

	printf("\nValue of %dth element is %d \n",n,p->val);

}
