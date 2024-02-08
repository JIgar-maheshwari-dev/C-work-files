#include"head.h"

int get_book_count(){
	
	int c;
	FILE *fp;
  
	fp=fopen("../book_files/count.txt","r");
	c=getw(fp);
	fclose(fp);

	return c;

}
