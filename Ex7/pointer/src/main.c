#include<stdio.h>
#include"array.h"

int main() {
	
	printline("inside main.c function");
	int a[10]={
		1,2,3,4,5,6,7,8,9,10
	};

	for(int i=0;i<10;i++)	
		printf("a[%d] = %d \n",i,a[i]);
	
	printf("\n");

	int *p;
	p=a;

	for(int i=0;i<10;i++)	
		printf("*(p+%d) = %d \n",i,*(p+i));
	
	printf("\n");

	myfun();
	return 0;
}

