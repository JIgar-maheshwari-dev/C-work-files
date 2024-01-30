#include<stdio.h>
#define R 2
#define C 3

#define P

int main() {

	int a[2][3]={};
#ifdef ary
	//scanning using normal array 
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			scanf("%d",&a[i][j]);
		}
	}

	//printing using normal array
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
#endif

#ifdef P

	int (*p)[C];
	p=a;

	//scanning using pointer to 2d array
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			scanf("%d",(*(p+i)+j));
		}
	}
	
	//printing using pointer
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			printf(" %d ",*(*(p+i)+j));
		}
		printf("\n");
	}
#endif

	return 0;
}

