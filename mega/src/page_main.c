#include"head.h"

void menu(){

        printf("                  WELCOME TO LIBRARY JIGAR MAHESHWARI                    \n");
        printf("            Enter 1. add book 2. print details of all book              \n");
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
