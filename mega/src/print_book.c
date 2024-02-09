#include"head.h"


void print_book(){

	FILE *fp;
	fp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt","r");
	if(fp == NULL){
		printf("UNABLE TO OPEN THE FILE \n");
		exit(0);
	}
	
	int bn;
	char namee[50],genr[50],auth[50],idate[20];
	int i=0,page,sn,pricee,avail;

	while(!(feof(fp))){
		fgets(genr,100,fp);
		printf("%s",genr);
	}
	fclose(fp);
	printf("going to main menu .......\n");
	system("sleep 4");
	menu();
}

