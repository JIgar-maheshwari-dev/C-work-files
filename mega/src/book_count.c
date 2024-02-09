#include"head.h"


int get_book_count(){
	
	int c;
	FILE *fp;
  
	fp=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/count.txt","r");
	c=getw(fp);
	fclose(fp);

	if(c==0)
	    return 1;
	else
		return c;

}
