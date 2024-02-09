#include"head.h"
#include"struct.h"



void new_copy(){
	
	char temp[256],command[1024];
	int linenum;		
	FILE *fp;
	
	printf("Enter the book name  :  ");	
	char c = getchar();
	gets(temp);

/*
	if (temp[strlen(temp) - 1] == '\n') {
		temp[strlen(temp) - 1] = '\0';
	}
		
	snprintf(command, sizeof(command), "grep -n \"%s\" ./home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt | cut -d: -f1", temp);

	fp = popen(command, "r");
	fgets(temp,sizeof(temp),fp);
	linenum=atoi(temp);
	linenum++;
	printf("%d \n",linenum);
	
	book *ptr=get_structs();
	book *ptr1=ptr;

	printf("%s\n\n",ptr++->name);
	printf("%s\n\n",ptr++->name);
	printf("%s\n\n",ptr++->name);
*/
	
	

	book *temp1=get_structs();
	book *ptr=temp1;
	

	book* found_book = find_book_by_name(temp1 ,temp);


	








//	printf("name   =   %s   \n\n",found_book->name);

//	printf("ptr in main %ld",ptr);

//	printf("found ptr in main  %ld",found_book);

//	print_struct(found_book);
/*
	if(found_book==0){
		printf("BOOK NOT FOUND \n");
	}
	else{
		print_struct(found_book);
	}

*/

}
