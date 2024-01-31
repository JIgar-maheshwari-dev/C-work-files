#include<stdio.h>
#include"head.h"

#define ON "\e[1m"
#define OFF "\e[m"
#define BLK "\e[1;5;33m"

int fun1(){
		
	printf("\033[3;30;42m");
	printf(BLK ON"This is fun1 R:int A:void\e[m\n"OFF);
	return 1;
}


int fun2(){
	
	printf("\033[0;30m");
	printf(BLK ON"This is fun2 R:int A:void\n"OFF);
	return 2;

}


int fun11(int a){
	printf("\033[0;32m");
	printf(BLK ON"This is fun11 R:int A:int\n"OFF);
	return 11;
}


int fun12(char a){
	
	printf("\033[0;34m");
	printf(ON"This is fun12 R:int A:char\n"OFF);
	return 12;
}

char fun13(int a){
	printf("\033[0;33m");
	printf(ON"This is fun13 R:char A:int\n"OFF);
	return (char)a;
}
