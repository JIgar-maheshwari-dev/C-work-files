#include<stdio.h>
#include<stdlib.h>
#include"head.h"

int main() {
	
	n* head;
	head=(n *)malloc(sizeof(n));
	create(head);
	print(head);
	
	print_n(head);
	
	return 0;
}

