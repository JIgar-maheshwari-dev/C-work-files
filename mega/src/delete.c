#include "head.h"
#include "struct.h"

extern char file[];

void delete(){

    char temp[256];

	printf("Enter the book name  you want  :   ");
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

	del_struct(found_book);
	printf("Enter any key to continue ...");
	getchar();
	menu();


    
}

void del_struct(book *sptr)
{

	FILE *fp, *temp;
	fp = fopen(file, "r");

	int n1 = ((sptr->book_no) - 1) * 11 + 1;
	printf("\n\n n1 = %d\n\n", n1);
	int n2 = ((sptr->book_no) - 1) * 11 + 2 + 9;
	printf("\n\n n2 = %d\n\n", n2);

	if (fp == NULL)
	{
		printf("File not found\n");
		system("sleep 2");
		menu();
	}

	temp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt", "w");
	if (temp == NULL)
	{
		printf("File not found\n");
		system("sleep 2");
		menu();
	}

	int current_line = 1;
	char str[100];

	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		fputs(str, temp);
	}

	printf("copied file to temp \n");
	fclose(fp);
	fclose(temp);

	temp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt", "r");
	
	char array[100];

	int lines = get_lines();

	fp = fopen(file, "w");

	while (current_line < lines)
	{

		if (current_line < n1)
		{
			fgets(str, sizeof(str), temp);
			//printf("  %d   %s ", current_line, str);
			fputs(str, fp);
		}
		if(current_line == n1){
			current_line += 9;
			for (int i = 0; i < 11; i++)
				fgets(str, sizeof(str), temp);
		}

		if (current_line >= n2)
		{
			fgets(str, sizeof(str), temp);
			printf("  %d   %s ", current_line, str);
			fputs(str, fp);

			fprintf(fp, " Book no  : %d \n", (sptr->book_no)++);

			fgets(str, sizeof(str), temp);
			printf("\n  %d   %s \n", current_line, str);
			fputs(str, fp);
		}

		current_line++;
	}

	fclose(fp);
	fclose(temp);
	int n=get_book_count();
	write_count(n-1);
	printf("Book is removed from library succesfully \n ");
}


