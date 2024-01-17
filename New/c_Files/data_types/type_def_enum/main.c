#include<stdio.h>

/** THIS PROGRAM DEMONSTRATE TYPEDEF AND ENUMATATION 
 * DATA TYPE 
 */

void main(){
    //HERE I HAVE DEFINED INT AS MARKS USING TYPEDEF
    typedef int marks;

    marks maths = 10;
    marks hindi = 5;
    printf("Maths marks is = %d\n",maths);
    printf("Hindi marks is = %d\n",hindi);

    //HERE I MADE ENUMARATED DATA TYPE CALLED DAY WHICH STORES A DAY OF WEEK
    enum DAY {MONDAY=10, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

    enum DAY week_st = MONDAY;
    enum DAY week_end = FRIDAY;
    enum DAY c_day = FRIDAY;

    if(c_day == week_st)
        printf("Today is hardwork day bro \n");

    if(c_day == week_end)
        printf("Chill bro aje to vehla nikdi jaisu \n");

    printf("%d\n",c_day);

}
