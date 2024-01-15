#include<stdio.h>
#include<limits.h>
/** PROGRAM ILLUSTRATING SIZE AND LIMITS OF VARIOUS DATATYPE
 *
 */


void main(){

    /**CHAR LIMITS*/
    printf("min char = %d \n",CHAR_MIN);
    printf("max char = %d \n",CHAR_MAX);
    printf("size of char = %ld \n\n",sizeof(char));

    
    /** SIGNED CHAR LIMIT */
    printf("signed char min = %d\n",SCHAR_MIN);
    printf("signed char max = %d\n",SCHAR_MAX);
    printf("size of signed char = %ld \n\n",sizeof(signed char));
    

    /**UNAIGNED CHAR LIMIT */
    printf("min signed char = %d \n",UCHAR_MAX);
    printf("size of unsigned char = %ld \n\n",sizeof(unsigned char));


    /** SIGNED SHORT INT  LIMIT */
    printf("signed short int min = %d\n",SHRT_MIN);
    printf("signed short int max = %d\n",SHRT_MAX);
    printf("size of signed short int  = %ld \n\n",sizeof(signed short int ));


    /** UNSIGNED SHORT INT  LIMIT */
    printf("unsigned short int max = %u\n",SHRT_MAX);
    printf("size of unsigned short int  = %ld \n\n",sizeof(unsigned short int));

    /** INT LIMITS */
    printf("int min = %d\n",INT_MIN);
    printf("int max = %d\n",INT_MAX);
    printf("size of int  = %ld \n\n",sizeof( int ));

    /** UNSIGNED INT LIMIT */
    printf("unsigned int max = %u\n",UINT_MAX);
    printf("size of unsigned int  = %ld \n\n",sizeof(unsigned int));

    /** LONG SIGNED INTEGER */
    printf("long signed int min = %ld\n",LONG_MIN);
    printf("long signed int max = %ld\n",LONG_MAX);
    printf("size of signed long int  = %ld \n\n",sizeof(signed long int));

    /** UNSIGNED LONG INT */
    printf("unsigned long int max =%lu \n",LONG_MAX);
    printf("size of unsigned long int = %ld \n\n",sizeof(unsigned long int));
}
