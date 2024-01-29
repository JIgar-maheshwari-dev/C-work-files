#include<stdio.h>
#include"array.h"

void myfun() {
	
	printline("insdie pointer.c file");
	int a;
	int *p;
	
	//value assigend through variable itself
	a=10;
	printf("a = %d \n",a);
	printf("access through normal variable \n");

	//accessing variable through pointer
	p = &a;
	*p = 15;
	printf("a = %d \n",a);
	printf("access through pointer variable \n");

}

