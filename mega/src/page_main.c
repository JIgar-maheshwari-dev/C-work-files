#include"head.h"

void menu(){
        pl();
        printf("                                                 WELCOME TO LIBRARY OF JIGAR MAHESHWARI                    \n\n");
        printf("                                            1. Enter new book                          \n");
        printf("                                            2. Modify book details                         \n");
        printf("                                            3. Print details of book                          \n");
        printf("                                            4. Issue a book                          \n");
        printf("                                            5. Remove a book                          \n");
	    printf("                                            6. Exit                          \n");

		int a;
		scanf("%d",&a);
	
	
	switch(a)
	{
		case 1:
			add_book();
			break;
		
		case 2:
			modify();
			break;

		case 3:
			print_book();
			break;
		
		case 4:
			issue_book();
			break;
		case 5:
			delete();
		
		case 6:
			exit(0);
	}
}
