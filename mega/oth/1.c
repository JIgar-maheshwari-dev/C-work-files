#include<stdio.h>

int add(int a,int b){
	return a+b;
}


float add2(int a,float b){
	return a+b;
}


int main() {

	void* arr[5];

	int a=10;
	float b=10.59;
	char c='J';
	char ar[]="jigar";
	

	arr[0]=&a;
	arr[1]=&b;
	arr[2]=&c;
	arr[3]=&ar;

	arr[4]=add;

//	printf("%d %f %c %s \n",*(int *)arr[0],*(float *)arr[1],*(char *)arr[2],(char *)arr[3]);
	
	printf("answer   = %d \n",                   (   (int (*)(int, int))   (arr[4])   )        (10, 20)                           );
	arr[4]=add2;
	printf("answer 2 = %f \n",               (  (float (*)(int, float)) (arr[4]) )          (10,10.5)                           );

	return 0;
}

