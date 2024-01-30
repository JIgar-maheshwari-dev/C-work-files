#include<stdio.h>
#include"head.h"

int main() {
	
	int (*fptr)();
	
	//using simple int add function using pointer
	fptr=add;
	printf("addition = %d \n",(*fptr)(2,3));

	//using  float add function using pointer
	fptr=f_add;
	printf("addition = %d \n",(*fptr)(2,3));
	
	//using char add function pointer
	fptr=c_add;
	printf("addition = %d \n",(*fptr)(10,20));

	return 0;
}

