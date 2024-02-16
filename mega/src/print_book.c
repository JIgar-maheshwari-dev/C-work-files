#include"head.h"
#include"struct.h"

void print_book(){

	char name[100];
	book* ptr,*ptr2 ;

	ptr = get_structs();
	ptr2=ptr;
	int n ;
	n=  get_book_count();

	while(n--){
		printf("Book no : %d\t Name : %s\t available copies : %d \n",ptr->book_no,ptr->name,ptr->copy);
		ptr++;
	}

	printf("Enter Book name to see full detalis of book  : ");
	getchar();
	gets(name);

	ptr = find_book_by_name(ptr2,name);
	print_struct(ptr);

	
	//fclose(fp);

	printf("PRESS Enter TO GO TO MAIN MENU  .......\n");
	getchar();
	menu();


}

