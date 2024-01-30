#include<stdio.h>
#include"head.h"

int main() {
	
	struct my my1={14,15,16};
	
	printf("a= %d, b= %d  c= %d \n",my1.a,my1.b,my1.c);

	printf("size of structure is = %d \n",sizeof(struct my));
	

	return 0;
}

