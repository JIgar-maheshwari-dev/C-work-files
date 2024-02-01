#include<stdio.h>
#include<stdlib.h>
#include"head.h"

void read(){
	
	fp2=fopen("./files/write.txt","r");
	
	char name[50];
	int age,roll;

	while(!feof(fp2)){
		fscanf(fp2,"%*s %s %*s %d %*s %d",name,&age,&roll);
		printf("%s\t\t%d\t%d\n",name,age,roll);
	}
	
	fclose(fp2);

}

