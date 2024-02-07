#include"head.h"

void print_book(){
	FILE *fp;
	fp=fopen("../book_files/book_records.txt","r");
	
	char temp[100];
	char test[50],test2[50],test3[50];
	int i=0;
/*	while(!(feof(fp))){
		i++;
		//fgets(temp,100,fp);
		//printf("%d string is = ",i);
		//printf("%s",temp);
		fscanf(fp,"%s",test);
		printf("%s\n",test);
	}
	printf("\n\n\n\n\n");
*/

	fscanf(fp,"%*s %*s %*s %*s %s",test);
	printf("%s",test);


}
