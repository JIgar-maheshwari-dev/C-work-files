#include<stdio.h>
#define MY

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

