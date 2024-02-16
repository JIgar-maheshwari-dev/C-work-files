#include"head.h"


void* func_ptr[7]= { add_book,modify,print_book,issue_book,deposit,delete,exiit};


void menu(){
        pl();
        printf("                                                 WELCOME TO LIBRARY OF JIGAR MAHESHWARI                    \n\n");
        printf("                                            1. Enter new book                          \n");
        printf("                                            2. Modify book details                         \n");
        printf("                                            3. Print details of book                          \n");
        printf("                                            4. Issue a book                          \n");
        printf("                                            5. Deposit a book                          \n");
        printf("                                            6. Remove a book                          \n");
	    printf("                                            7. Exit                          \n");

		int a;
		scanf("%d",&a);
	
	if(a>0 && a<8){
		((void (*)(void)) (func_ptr[a-1]))();
	}
	else{
		printf("Enter proper option \n");
		system("sleep 2");
		getchar();
		menu();
	}

	// switch(a)
	// {
	// 	case 1:
	// 		add_book();
	// 		break;
		
	// 	case 2:
	// 		modify();
	// 		break;

	// 	case 3:
	// 		print_book();
	// 		break;
		
	// 	case 4:
	// 		issue_book();
	// 		break;
	// 	case 5:
	// 		delete();
		
	// 	case 6:
	// 		exit(0);
	// }
}


void exiit(){
	printf("Program is ending ... ... \n");
	system("sleep 2");
	exit(0);
}
