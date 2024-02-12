#include"head.h"


void print_book(){

	FILE *fp;

	fp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt","r");
	if(fp == NULL){
		printf("UNABLE TO OPEN THE FILE \n");
		printf("PRESS Enter TO GO TO MAIN MENU \n ");
		getchar();
		getchar();
		menu();
	}
	
	char genr[50];

	while(!(feof(fp))){
		fgets(genr,100,fp);
		printf("%s",genr);
	}
	fclose(fp);
	printf("PRESS Enter TO GO TO MAIN MENU  .......\n");
	getchar();
	getchar();
	menu();
}

