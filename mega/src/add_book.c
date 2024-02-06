#include"head.h"
#include"struct.h"



void add_book(){

	FILE* fp;
	static int count;
	fp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt","a");

	book temp;
	fprintf(fp,"------------------------------------------------\n\n");
	fprintf(fp," Book No. %d\n",count++);

	printf("Enter the name of book : ");
	scanf(" %[^\n]s ",temp.name);
	printf("%s\n",temp.name);
	
	printf("Enter prise of book : ");
	scanf("%d",&temp.prise);
	printf("%d\n",temp.prise);

        printf("Enter the author of book : ");
        scanf(" %[^\n]s ",temp.author);
	printf("%s\n",temp.author);

        printf("How many copie you have ?  : ");
        scanf("%d",&temp.copy);
	printf("%d\n",temp.copy);
	
	fprintf(fp," Name : %s \n prise : %d \n Author : %s\n Copies available : %d \n",temp.name,temp.prise,temp.author,temp.copy);
	fprintf(fp,"\n\n------------------------------------------------\n\n");

	fclose(fp);
}


