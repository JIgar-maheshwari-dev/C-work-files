#include<stdio.h>

struct my{
	float a[10];
	int b;
};

typedef struct my my;

int main() {

	my my1;
	printf("size of structure is = %d \n",sizeof(my1));

	return 0;
}

