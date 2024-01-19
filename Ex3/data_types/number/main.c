#include<stdio.h>
#include<float.h>
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
    printf("unsigned long int max =%lu \n",ULONG_MAX);
    printf("size of unsigned long int = %ld \n\n",sizeof(unsigned long int));

    
    /** LONG SIGNED INTEGER */
    printf("long long signed int min = %lld\n",LLONG_MIN);
    printf("long long signed int max = %lld\n",LLONG_MAX);
    printf("size of long long signed int = %ld\n\n",sizeof(signed long long int));


    /** UNSIGNED LONG INT */
    printf("unsigned long long int max =%llu \n",ULLONG_MAX);
    printf("size of unsigned long long int = %ld \n\n",sizeof(unsigned long long int));


    
    /** REAL DATA TYPES */
    /**FLOAT*/
    printf("float max  = %f\n",FLT_MAX);
    printf("float min  = %f\n",FLT_MIN);
    printf("size of float = %ld\n\n",sizeof(float));
    
    
    /**DOUBLE */
    printf("double max  = %lf\n",DBL_MAX);
    printf("double min  = %lf\n",DBL_MIN);
    printf("size of double = %ld\n\n",sizeof(double));


    /**LONG DOUBLE */
    printf("long oduble max  = %Lf\n",LDBL_MAX);
    printf("long double min  = %Lf\n",LDBL_MIN);
    printf("size of long double = %ld\n\n",sizeof(long double));
    
}
