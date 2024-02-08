#include"head.h"
#include"struct.h"

book* find_book_by_name(book *ptr, char name2[]){
	
	int c = get_book_count();
	book* temp=ptr,*tt=NULL;
	printf("temp ==  %p \n",temp);
	printf("\n\n searching  for  %s123",name2);


	for(int i=0;i<=c;i++){
		char temp2[100];
		strcpy(temp2,temp->name);
		if(!(strcmp(temp2,name2)))
			return temp;
		temp++;
	}
	return tt;
	
}
