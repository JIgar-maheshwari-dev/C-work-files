#include<stdio.h>

int main() {
	int a[]={1,4,9,15,23,45,66,79,85,101};
	int p=23;
	int i=bin_search(a,p);
	
	printf(" %d is found in array at index %d\n",p,i);
	printf("-1 means not founf \n\n");


	return 0;
}

