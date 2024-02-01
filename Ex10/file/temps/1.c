#include<stdio.h>

int main() {

	FILE *fp;
	fp=fopen("my.txt","w");
	
	int a;
	scanf("%c",&a);
	putc(a,fp);
	fclose(fp);


	return 0;
}

