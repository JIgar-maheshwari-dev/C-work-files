#include"head.h"


void write_count(int n){
	
	FILE *c;

	c=fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/count.txt","w");
	putw(n,c);
	fclose(c);
}
