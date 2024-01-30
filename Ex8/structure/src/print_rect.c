#include<stdio.h>
#include"head.h"

void print_rect(struct rect r) {
	
	printf("First  point x= %d  y= %d  \n",r.pt1.x,r.pt1.y);
	printf("Second point x= %d  y= %d  \n",r.pt2.x,r.pt2.y);
	printf("Third  point x= %d  y= %d  \n",r.pt4.x,r.pt3.y);
	printf("Fourth point x= %d  y= %d  \n",r.pt4.x,r.pt4.y);
}

