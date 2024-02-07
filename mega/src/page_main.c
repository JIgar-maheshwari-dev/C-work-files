#include"head.h"

void menu(){
        pl();
        printf("                                                 WELCOME TO LIBRARY OF JIGAR MAHESHWARI                    \n\n");
        printf("                                            1. Enter new book                          \n");
        printf("                                            2. Print details of book                          \n");
        printf("                                            3. Exit                          \n");
	int a;
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			add_book();
			break;
		
		case 2:
			print_book();
			break;

		case 3:
            exit(0);
	}
}
