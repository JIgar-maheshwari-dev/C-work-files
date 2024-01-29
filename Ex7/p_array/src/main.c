#include<stdio.h>
#define p2p

int main() {

#ifdef MY
	int a=10;
	int b=20;
	int c=30;

	int* my[3]={
		&a,&b,&c
	};

	printf("%d is at  %p (hex),\t%ld (decimal) \n\n",*my[0],my[0],my[0]);
	printf("%d is at  %p (hex),\t%ld (decimal) \n\n",*my[1],my[1],my[1]);
	printf("%d is at  %p (hex),\t%ld (decimal) \n\n",*my[2],my[2],my[2]);



#endif


#ifdef p2p

	int a=10;
	int *p=&a;
	int **p22=&p;
	
	printf("\n");
	printf("a   =  %d\n",a);
	printf("p   =  %ld\n",p);
	printf("p22  =  %ld\n",p22);
	printf("\n");

	printf("\n");
	printf("using first pointer : %d \n",*p);
	printf("*p22 = %ld\n",*p22);
	printf("using pointer pointer to pointer : %d \n",**p22);
	printf("\n");


	int ********p8;
	int *******p7;
	int ******p6;
	int *****p5;
	int ****p4;
	int ***p3;
	int **p2;
	int *p1;
	int z=10;

	p1=&z;
	p2=&p1;
	p3=&p2;
	p4=&p3;
	p5=&p4;
	p6=&p5;
	p7=&p6;
	p8=&p7;

	printf("\n");
	printf("value of z     = %d\n",z);
	printf("value of &z    = %ld\n",&z);
	printf("value of p1    = %ld\n",p1);
	printf("value of p2    = %ld\n",p2);
	printf("value of p3    = %ld\n",p3);
	printf("value of p4    = %ld\n",p4);
	printf("value of p5    = %ld\n",p5);
	printf("value of p6    = %ld\n",p6);
	printf("value of p7    = %ld\n",p7);
	printf("value of p8    = %ld\n",p8);
	printf("\n");


	printf("\n");
	printf("********p8    : %ld\n",********p8);
	printf("********p7    : %ld\n",*******p7);
	printf("******p6      : %ld\n",******p6);
	printf("*****p5       : %ld\n",*****p5);
	printf("****p4        : %ld\n",****p4);
	printf("***p3         : %ld\n",***p3);
	printf("**p2          : %ld\n",**p2);
	printf("*p1           : %ld\n",*p1);
	printf("z             : %d \n",z);
	printf("\n");


	printf("\n");
	printf("*******p8    : %ld\n",*******p8);
	printf("*******p7    : %ld\n",******p7);
	printf("*****p6      : %ld\n",*****p6);
	printf("****p5       : %ld\n",****p5);
	printf("***p4        : %ld\n",***p4);
	printf("**p3         : %ld\n",**p3);
	printf("*p2          : %ld\n",*p2);
	printf("p1           : %ld\n",p1);
	printf("\n");


#endif




#ifdef oth

	// declaring some temp variables
    int var1 = 10;
    int var2 = 20;
    int var3 = 30;
 
    // array of pointers to integers
    int* ptr_arr[3] = { &var1, &var2, &var3 };
 
    // traversing using loop
    for (int i = 0; i < 3; i++) {
        printf("Value of var%d: %d\tAddress: %p\n", i + 1, *ptr_arr[i], ptr_arr[i]);
    }
 
    return 0;

#endif

}

