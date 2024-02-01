#include<stdio.h>
#include<stdlib.h>
#include"head.h"

/* THIS FILE IS FOR SCANNING DATA FROM A FILE AND PRINTING ON STDOUT */


void read_f() {
	
	char *name="./test_files/test2.txt";
	fp=fopen(name,"r");

	if(fp==NULL){
		printf("Error while opening file for reading \n");
		exit(1);
	}
	
	char a;

	while((a=getc(fp)) != EOF){
		printf("%c",a);
	}

	fclose(fp);

}

