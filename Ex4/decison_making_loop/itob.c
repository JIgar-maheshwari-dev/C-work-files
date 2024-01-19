#include <stdio.h>
#include<string.h>

void itob(int n,char c[],int b);
void rev(char c[]);

void main() {
	unsigned long long int a;
	printf("Enter the number :     ");
	scanf("%lld",&a);
	char n_base[]="000";
	printf("Enter the base :     ");
	int base;
	scanf("%d",&base);
	itob(a,n_base,base);
	printf("base 10 number : %lld\n\n",a);
	printf("changed base to %d  : %s\n\n",base,n_base);

}

void itob(int n, char c[],int b){
	int i=0;
	while(n != 0){
		if(b==16 && (n%b)>9 ){
			int t=(n%b);
				c[i]='A'+t-10;
		}
		else
			c[i]=(n%b)+'0';

		c[i+1]='\0';
		printf("%d ",(n%b));
		n=(int)(n/b);
		i++;
	}
	rev(c);
	printf("\n\n");

}

void rev(char name[]){
	char temp;
	for(int i=0,l=strlen(name);i<(l/2);i++){
		temp=name[i];
		name[i]=name[l-1-i];
		name[l-i-1]=temp;
	}
}


