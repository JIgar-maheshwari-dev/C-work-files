#include<stdio.h>
#include<head.h>

void main(){
	printf("We are inside main file \n");
	
	printf("below this HEADER functin output \n");
	printf("%d \n",h1f(1,2));
	printf("%d \n",h2f(2,3));


	printf("below this LIBRARY functin output \n");
	printf("%d \n",lib1fun(1,2));
	printf("%d \n",lib2fun(2,3));

	first();
	second();
	third();
	four();


	}
