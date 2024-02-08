#include"head.h"
#include"struct.h"


void add_book(){

	
	FILE *fp, *c,*sys;
	static int count;

	fp=fopen("../book_files/book_records.txt","a");


	c=fopen("../book_files/count.txt","r");
	count=getw(c);
	fclose(c);

	book temp;
	
	fprintf(fp,"------------------------------------------------\n");
	fprintf(fp," Book no  : %d \n",++count);

	c=fopen("../book_files/count.txt","w");
	putw(count,c);
	fclose(c);

	printf("Enter the name of book : ");
	scanf(" %[^\n]s ",temp.name);
	
	printf("Enter the genre of book : ");
	scanf(" %[^\n]s ",temp.genre);

        printf("Enter the author of book : ");
        scanf(" %[^\n]s ",temp.author);

	printf("Enter total pages of book : ");
	scanf("%d",&temp.total_pages);
	
	printf("Enter price of book : ");
	scanf("%d",&temp.price);

        printf("How many copie you have ?  : ");
        scanf("%d",&temp.copy);
	

	sys=popen("date +%d-%m-%Y-%l-%M","r");
	fgets( temp.issue_date, sizeof(temp.issue_date), sys);

	fprintf(fp," Name : %s \n Genre : %s\n Author : %s\n Issue date : %s Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n",temp.name,temp.genre,temp.author,temp.issue_date,temp.total_pages,000,temp.price,temp.copy);
	fprintf(fp,"------------------------------------------------\n");

	fclose(fp);	

	menu();
}


