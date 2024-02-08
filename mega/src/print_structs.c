#include"head.h"
#include"struct.h"

void print_struct(book *ptr){
	
	printf("\n  NAME       =   %s\n",ptr->name);
	printf("  GENRE      =   %s\n",ptr->genre);
	printf("  AUTHHOR    =   %s\n",ptr->author);
	printf("  DOI        =   %s\n",ptr->issue_date);
	printf("  PAGES      =   %d\n",ptr->total_pages);
	printf("  SHELF      =   %d\n",ptr->shelf_no);
	printf("  PRICE      =   %d\n",ptr->price);   
	printf("  COPY       =   %d\n\n",ptr->copy);

}
