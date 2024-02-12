
struct book
{
	char name[50];
	char genre[50];
	char author[100];
	char date_IN[20];

	int book_no;
	int total_pages;
	int shelf_no;
	int price;
	int copy;
};

typedef struct book book;
