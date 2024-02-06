#include<stdio.h>
#include"head.h"

int main() {


int a;
	printf("Enter 1 for send 2 for receive :  ");
	scanf("%d",&a);
	if(a==1)
		send1();
	if(a==2)
		func();

	return 0;
}

