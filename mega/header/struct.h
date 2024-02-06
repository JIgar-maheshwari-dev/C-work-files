
struct book{
	char name[100];
	int prise;
	char author[100];
	int copy;
};

typedef struct book book;
typedef struct book* b_ptr;
