#include<stdio.h>

void main(){
    //DECLARING THE VARIABLES FOR ARITHMETIC
    int a=8,b=2;
    int ans;

    ans = a+b;   //ARITHMETIC OPERATOR +
    printf("a+b = %d \n\n",ans);

    ans = a-b;   //ARITHMETIC OPERATOR -
    printf("a-b = %d \n\n",ans);

    //SAME FOR * AND /

    ans = a%b;   //ARITHMETIC OPERATOR % MODULUS
    printf("a%%b = %d \n\n",ans);

    //RELATIONAL OPERATORS

    if(a<b)     // LESS THAN
        printf("a < b \n\n");

    if(a>b)     // GREATER THAN
        printf("a > b \n\n");
    // SAME FOR <=, >=, ==, !=

    //LOGICAL OPERATORS
    if(a>b && b<a)      // && MEANS BOTH THE CONDITION HAS TO BE TRUE
        printf("a>b and b<a\n\n");

    if(a>b || b<a)      // || MEANS ANY ONE CONDITON HAS TO BE TRUE
        printf("a>b OR b<a\n\n");

    if(!b)      // NEGATION OPERATOR
        printf("not b \n\n");

    // BITWISE OPERATORS
    ans=a&b;     //BITWISE AND
    printf("a & b = %d\n\n",ans);


    ans=a|b ;    //BITWISE OR
    printf("a | b = %d\n\n",ans);

    ans= a<<1;
    printf("a shifted left by 1 = %d\n\n",ans);    //SAME FOR RIGHT SHIFT

    //OTHER BITWISE OPERATORS ARE ~ NEGATOIN AND ^ XOR

    //TERNARY OPERATOR ?:
    printf(" (a>b)?a:b === %d\n\n",(a>b)?a:b);


    for(int i=0;i<10;i++){
        printf("hello world \n\n");
    }

    for(int i=0;i<10;i++){
        printf("hello world \n\n");
    }

}
