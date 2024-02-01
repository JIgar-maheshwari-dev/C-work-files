#include<stdio.h>
#include<stdlib.h>
#include"head.h"


/* THIS FILE IS FOR PRINTING DATA TO A FILE */

void r_w_putc() {
	
	if(fp==NULL){
		printf("Error while opening file\n");
		exit(1);
        }
 
        char a;
        while((a=getchar())!=EOF)
		putc(a,fp);
 
	printf("\n *** ** * ENDING OF DATA PRINTING * ** *** \n\n");
	fclose(fp);

}

