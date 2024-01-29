#include<stdio.h>
#include"head.h"


void fun2(char *a, char *b) {

	 while ((*b = *a) != '\0') {
		 a++;
		 b++;
	 }
}

