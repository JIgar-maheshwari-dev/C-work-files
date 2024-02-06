#include"head.h"

void menu(){
        pl();
        printf("                                       WELCOME TO LIBRARY OF JIGAR MAHESHWARI                    \n");
        printf("                                   Enter 1. add book 2. print details of all book              \n");
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
	}
}
