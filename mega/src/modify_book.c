#include "head.h"
#include "struct.h"


extern char file[];



void modify()
{

	char temp[256];

	printf("Enter the book name  :  ");
	getchar();
	gets(temp);

	book *temp1 = get_structs();

	book *found_book = find_book_by_name(temp1, temp);

	if (found_book == NULL)
	{
		printf("Book not found\n");
		system("sleep 2");
		menu();
	}

	// ASK USER FOR NEW BOOK DETAILS
	printf("new name : ");
	gets(found_book->name);

	printf("new genre : ");
	gets(found_book->genre);

	printf("new author : ");
	gets(found_book->author);

	printf("new pages : ");
	scanf("%d", &found_book->total_pages);

	printf("new prise : ");
	scanf("%d", &found_book->price);

	printf("new available copies ?  : ");
	scanf("%d", &found_book->copy);

	write_struct(found_book,0);
	printf("Enter any key to continue ...");
	getchar();
	getchar();

	menu();
}






void modify2(){


	char temp[256];

	printf("Enter the book name  :  ");
	getchar();
	gets(temp);

	book *temp1 = get_structs();

	book *found_book = find_book_by_name(temp1, temp);

	if (found_book == NULL)
	{
		printf("Book not found\n");
		system("sleep 2");
		menu();
	}

	// ASK USER FOR NEW BOOK DETAILS
	printf("Enter ! for not chaning details \n");
	
	printf("new name : ");
	gets(temp);
	if(strcmp(temp,"!"))
		strcat(found_book->name,temp);

	printf("new genre : ");
	gets(temp);
	if(strcmp(temp,"!"))
		strcat(found_book->genre,temp);

	printf("new author : ");
	gets(temp);
	if(strcmp(temp,"!"))
		strcat(found_book->author,temp);



/*
	printf("new genre : ");
	gets(found_book->genre);

	printf("new author : ");
	gets(found_book->author); */

	int tt;

	printf("new pages : ");
	scanf("%d", &tt);
	if(tt)
		scanf("%d", &found_book->total_pages);

	printf("new price : ");
	scanf("%d", &tt);
	if(tt)
		scanf("%d", &found_book->price);

	printf("copies : ");
	scanf("%d", &tt);
	if(tt)
		scanf("%d", &found_book->copy);

 //here new logic for writing data in-between file

	wirte_struct_2(found_book);


	printf("Enter any key to continue ...");
	getchar();
	getchar();
	menu();



}


void wirte_struct_2(book *sptr){

    FILE *fp,*temp;
	fp=fopen(file, "r");
	
	int n1 = ((sptr->book_no)-1)*11+2 ;
	
	int n2 = ((sptr->book_no)-1)*11+2+8 ;

	if(fp==NULL)
	{
        printf("File not found\n");
        system("sleep 2");
        menu();
    }

	temp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt","w");
	if(temp==NULL)
	{
        printf("File not found\n");
        system("sleep 2");
        menu();
    }

	int current_line=1;
	char str[100];
	
	while(!feof(fp)){

		fgets(str,sizeof(str),fp);
		fputs(str,temp);
	}
	printf("copied file to temp \n");
	fclose(fp);
	fclose(temp);

	temp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt","r");
	fp=fopen(file,"w");

	while(!feof(temp)){

		fgets(str,sizeof(str),temp);
		if(current_line<n1 || current_line > n2){
			fputs(str,fp);
		}

		if(current_line==n1){
			fprintf(fp," Name : %s \n Genre : %s\n Author : %s\n Date IN : %s Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n",sptr->name,sptr->genre,sptr->author,sptr->date_IN,sptr->total_pages,000,sptr->price,sptr->copy);
			current_line=n2;
			for(int i=0;i<11;i++){
				fgets(str,sizeof(str),temp);
			}
		}
		current_line++;

	}

	fclose(fp);
	fclose(temp);

	printf("Content modified succesfully \n ");


	

}
