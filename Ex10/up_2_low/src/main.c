#include<stdio.h>
#include<ctype.h>

int main(int argc,char* argv[]) {



/*
	printf("\nTotal command line argument = %d \n\n",argc);
	for(int i=0;i<argc;i++){
		printf("%dth argument = %s\n",i+1,argv[i]);
	}
*/

	if(islower(*argv[1]))
		putchar(toupper(*argv[1]));
	if(isupper(*argv[1]))
		putchar(tolower(*argv[1]));

}

