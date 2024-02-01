#include<stdio.h>
#include<stdlib.h>
#include"head.h"


void odd_even() {

	FILE *fp1,*fp2;

	fp1=fopen("./test_files/odd.txt","w");
	fp2=fopen("./test_files/even.txt","w");

	int a;
	printf("\nEnter numbers \n");
	scanf("%c",&a);

	while((scanf("%c",&a))!=EOF){
		
		if(((int)a%2)==0){
			putc(a,fp2);
		}

		if(((int)a%2)!=0){
			putc(a,fp1);
		}

	}
}

