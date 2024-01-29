#include<stdio.h>
#include"head.h"

int main() {

	char a1[]="this is first string";
	char b1[]="";
	
	printf("\nbefore call \n");
	printf("%s \n",a1);
	printf("%s \n",b1);
	
	fun1(a1,b1);
	
	printf("\nafter call \n");
	printf("%s \n",a1);
	printf("%s \n",b1);

	char a2[]="this is second string";
	char b2[]="";
	
	printf("\nbefore call \n");
	printf("%s \n",a2);
	printf("%s \n",b2);
	
	fun2(a2,b2);

	printf("\nafter call \n");
	printf("%s \n",a2);
	printf("%s \n",b2);
	
	char a3[]="this is third string";
	char b3[]="";

	printf("\nbefore call \n");
	printf("%s \n",a3);
	printf("%s \n",b3);
	
	fun3(a3,b3);

	printf("\nafter call \n");
	printf("%s \n",a3);
	printf("%s \n",b3);
	
	char a4[]="this is fourth string";
	char b4[]="";

	printf("\nbefore call \n");
	printf("%s \n",a4);
	printf("%s \n",b4);

	fun4(a4,b4);
	
	printf("\nafter call \n");
	printf("%s \n",a4);
	printf("%s \n",b4);



	return 0;
}

