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
	printf("Enter ! for not chaning details \n");

	printf("new name : ");
	gets(temp);
	if (strcmp(temp, "!"))
	{
		strcat(found_book->name, "");
		strcat(found_book->name, temp);
	}

	printf("new genre : ");
	gets(temp);
	if (strcmp(temp, "!"))
	{
		strcat(found_book->genre, "");
		strcat(found_book->genre, temp);
	}
	printf("new author : ");
	gets(temp);
	if (strcmp(temp, "!"))
	{
		strcat(found_book->author, "");
		strcat(found_book->author, temp);
	}

	/*
		printf("new genre : ");
		gets(found_book->genre);

		printf("new author : ");
		gets(found_book->author); */

	int tt;

	printf("new pages : ");
	scanf("%d", &tt);
	if (tt)
		found_book->total_pages = tt;

	printf("new price : ");
	scanf("%d", &tt);
	if (tt)
		found_book->price = tt;

	printf("copies : ");
	scanf("%d", &tt);
	if (tt)
		found_book->copy = tt;

	// here new logic for writing data in-between file
	print_struct(found_book);

	write_struct(found_book);

	printf("Enter any key to continue ...");
	getchar();
	getchar();
	menu();
}

void write_struct(book *sptr)
{

	FILE *fp, *temp;
	fp = fopen(file, "r");

	int n1 = ((sptr->book_no) - 1) * 11 + 2;
	printf("\n\n n1 = %d\n\n", n1);
	int n2 = ((sptr->book_no) - 1) * 11 + 2 + 8;
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

//	printf("copied file to temp \n");
	fclose(fp);
	fclose(temp);

	temp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt", "r");

	int lines = get_lines();

	fp = fopen(file, "w");

	while (current_line <= lines)
	{

		if (current_line < n1)
		{
			fgets(str, sizeof(str), temp);
		//	printf("\n  %d   %s \n", current_line, str);
			fputs(str, fp);
		}

		if (current_line == n1)
		{
			fprintf(fp, " Book no  : %d \n", sptr->book_no);
			fprintf(fp, " Name : %s \n Genre : %s\n Author : %s\n Date IN : %s\n Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n", sptr->name, sptr->genre, sptr->author, sptr->date_IN, sptr->total_pages, 000, sptr->price, sptr->copy);
			current_line += 9;
			for (int i = 0; i < 9; i++)
				fgets(str, sizeof(str), temp);
		}

		if (current_line > n2)
		{
			fgets(str, sizeof(str), temp);
			printf("\n  %d   %s \n", current_line, str);
			fputs(str, fp);
		}

		current_line++;
	}

	fclose(fp);
	fclose(temp);

	printf("Content modified succesfully \n ");
}

int get_lines()
{
	FILE *fp;
	fp = fopen(file, "r");
	if (fp == NULL)
		printf("Error: Could not open\n");
	int count = 0;
	char c;
	while (!(feof(fp)))
	{
		char c = getc(fp);
		//	printf("%c",c);
		if (c == '\n')
			count++;
	}

	fclose(fp);
//	printf("LINES ===== %d \n", count);
	return count;
}