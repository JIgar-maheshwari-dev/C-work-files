#include<stdio.h>
#include"head.h"

void pprint(struct point a[],int n){
	printf("Printing the array of structure in print_array_point.c \n\n");
	for(int i=0;i<n;i++){
		printf("x= %d  y= %d  \n",a[i].x,a[i].y);
	}

}
