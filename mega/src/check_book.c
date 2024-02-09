#include"head.h"
#include"struct.h"


void check_book(char *name,int n){

    book *ptr;
    ptr=get_structs();

  //  printf("inside check book function \n\n\n");

    for(int i=0;i<=n;i++){

        char *name2=termi(ptr->name);

    //    printf("%s\n",name2);
    //   printf("%s\n",ptr->name);

        if(strcmp(name2,name)==0){
            printf("Book already exists\n");
            system("sleep 2");
            menu();
        }
    }   
}
       
