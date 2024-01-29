#include<stdio.h>
#include"head.h"

void fun3(char *a, char *b) {
	while ((*b++ = *a++) != '\0')
		;
}

