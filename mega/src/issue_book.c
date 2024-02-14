#include "head.h"
#include "struct.h"

void issue_book(){

	FILE *sys;
	char temp[30];
	printf("Enter book name :  ");
	getchar();
	gets(temp);
	book *ptr1;
	book *ptr = get_structs();
	ptr1=find_book_by_name(ptr,temp);

	if(ptr1==NULL){
		printf("Not able to find a book named %s \n",temp);
		system("sleep 2");
		menu();
	}


	FILE *fp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/issued_books.txt","a");
	if(fp==NULL){	
		printf("Error in opening file\n");
        system("sleep 2");
		menu();
	}
	fprintf(fp,"------------------------------------\n");
	fprintf(fp,"Name of Book : %s\n",ptr->name);
	
	sys=popen("date +%d-%m-%Y-%l-%M","r");
	fgets( temp, sizeof(temp), sys);

	fprintf(fp,"Date of Issue : %s",temp);
	
	fprintf(fp,"------------------------------------\n");

	fclose(fp);

	write_struct_2(ptr1,1);

	system("sleep 2");
	menu();
}
