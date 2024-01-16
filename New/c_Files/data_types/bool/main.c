#include<stdio.h>
#include<limits.h>

/**     THIS CODE IS FOR DEMONSTRATION OF 
 *      BOOLEAN DATA TYPE
 */

void main(){
    
    /*UNSIGNED CHAR LIMIT IS 255; 256 OVERFLOWS TO 0 AND IT IS CONSIDERED AS FALSE */
    unsigned char a = 256;

    if(a)
        printf("this is true\n\n");
    else
        printf("this is false\n");


    /** HERE WE HAVE DEFINED A VARIABLE BOOLEAN TYPE*/
    _Bool b=1,c=2;

    if(b==c)
        printf("THIS IS TRUE \n");

}

