#include<stdio.h>
#include"head.h"

void write() {

	char name[50];
	int age,roll,n=0;
	
	fp1=fopen("./files/write.txt","w");
	printf("Enter name age roll \n ");
	while(n<5){
		scanf("%s %d %d",name,&age,&roll);
		fprintf(fp1,"Name: %s Age: %d Roll: %d\n",name,age,roll);	
		n++;
	}

	fclose(fp1);
	

}

