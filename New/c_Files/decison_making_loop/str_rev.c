#include <stdio.h>
#include<string.h>

int main() {
	char name[]="jigar is writing here a string 123 123 123 123";
	char temp;
	printf("original %s\n\n",name);

	for(int i=0,l=strlen(name);i<(l/2);i++){
		temp=name[i];
		name[i]=name[l-1-i];
		name[l-i-1]=temp;
	}
	printf("reversed %s\n\n",name);

    	return 0;
}

