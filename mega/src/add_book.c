#include"head.h"
#include"struct.h"


void add_book(){

	printf("this is add book function \n");
	book temp;
	
	printf("Enter the name of book : ");
	scanf(" %[^\n]s ",temp.name);
	printf("%s\n",temp.name);
	
	printf("Enter prise of book : ");
	scanf("%d",&temp.prise);
	printf("%d\n",temp.prise);

        printf("Enter the author of book : ");
        scanf(" %[^\n]s ",temp.author);
	printf("%s\n",temp.author);

}


