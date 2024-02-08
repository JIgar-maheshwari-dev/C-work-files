#include <stdio.h>
int main()
{
	FILE *fp;
	fp = popen("date +%d-%m-%Y%l-%M","r");
	char out[100];
	fgets(out,sizeof(out),fp);
	printf("%s",out);
}

