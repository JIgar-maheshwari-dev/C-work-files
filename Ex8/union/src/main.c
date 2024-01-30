#include<stdio.h>
#include"head.h"

int main() {

	union myu i={1};
	printf("%d \n",i.a);

	union myu j={1.121212};
	printf("%lf \n",j.b);
	
	union myu l={'J'};
	printf("%c \n",l.d);
	
	return 0;
}

