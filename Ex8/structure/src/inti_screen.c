#include<stdio.h>
#include"head.h"

struct rect make_rect(struct point p1, struct point p2,struct point p3,struct point p4){

	struct rect temp;
	temp.pt1=p1;
	temp.pt2=p2;
	temp.pt3=p3;
	temp.pt4=p4;


	return temp;
}

