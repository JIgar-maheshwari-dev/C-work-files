#include<stdio.h>
#include"head.h"


int main() {
	
	struct point p1;
	struct point p2;
	struct point p3;
	struct point p4;
	
	p1=makept(10,20);
	print_p(p1);
	
	p2=makept(20,30);
	print_p(p2);
	
	p3=makept(30,40);
	print_p(p3);
	
	p4=makept(40,50);
	print_p(p4);

	struct rect screen;
	screen=make_rect(p1,p2,p3,p4);

	print_rect(screen);
	return 0;
}
