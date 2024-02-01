#include<stdio.h>
#include"head.h"


char *name="./test_files/test1.txt";
FILE *fp;

int main() {


/*

	//initializing file pointer
	fp = fopen(name,"w");
	
	//calling a function for writing into file using getchar and putc functions
	r_w_putc(name,fp);

	//calling another function to read another file
	read_f();

*/

	//this function will read numbers from user and write into two different files according to that number is odd or even
	odd_even();



	return 0;
}




