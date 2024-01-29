#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"my.h"
#define MAX 50

int strindex(char pat,char a[]);

int main() {
	
	char a[MAX];
	printf("Enter the string without space  ::   ");
	scanf("%s",a);
	fflush(stdin);
	printf("Enter the pattern(one char) that you want to find in string ::  ");
	char pat;
	scanf("%c",&pat);
	fflush(stdin);

	int index=strindex(pat,a);
	
	printf("Matched at : %d \n\n",index);
	printf("from hello function : %d",hello());
	return 0;

}



int strindex(char pat,char a[]){
	int n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]==pat)
			return (i+1);
	}
	return -1;
}





