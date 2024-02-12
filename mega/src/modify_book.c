#include "head.h"
#include "struct.h"

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
	menu();
}