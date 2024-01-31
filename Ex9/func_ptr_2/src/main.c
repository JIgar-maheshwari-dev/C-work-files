#include<stdio.h>
#include"head.h"

int main() {

	int (*fptr)();

	fptr=fun1;
	
	int a= fptr();

	fptr=fun2;
	a=fptr();

	fptr=fun11;
	a=fptr(1);

	fptr=fun12;
	char b=fptr('c');
	
	char (*ptr2)();
	
	ptr2=fun13;
	
	b=fun13(12);


	return 0;
}

