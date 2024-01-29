#include<stdio.h>
#include"head.h"

void fun1(char *a,char *b) {

	int i;
	i = 0;
	while ((b[i] = a[i]) != '\0')
		i++;
}

