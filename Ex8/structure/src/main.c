#include<stdio.h>
#include"head.h"


// use macro normal aray and ptr
#define ptr


int main() {


#ifdef normal
	struct point p1;
	struct point p2;
	struct point p3;
	struct point p4;
#endif




#ifdef aray
	struct point ar[4];
	init_p_array(ar,4);
	pprint(ar,4);
#endif




#ifdef normal

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
#endif


#ifdef ptr

	struct point p1,p2,p3,p4;

	struct point* pr;
	
	pr=&p1;

	init_p_p(pr);
	print_pp(pr);
	
#endif
	


	return 0;
}
