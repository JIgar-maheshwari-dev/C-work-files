
struct book{
	char name[100];
	char genre[50];
	char author[100];
	char issue_date[20];

	int total_pages;
	int shelf_no;
	int price;
	int copy;
};

typedef struct book book;
typedef struct book* b_ptr;
