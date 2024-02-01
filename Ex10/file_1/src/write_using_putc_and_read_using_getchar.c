#include<stdio.h>
#include<stdlib.h>
#include"head.h"

void r_w_putc(char *n,FILE *f) {
	

	f=fopen(n,"w");
  
	if(fp==NULL){
		printf("Error while opening file\n");
		exit(1);
        }
 
        char a;
        while((a=getchar())!=EOF)
		putc(a,fp);
 
	printf("\nENDING OF DATA PRINTING\n");
	fclose(fp);

}

