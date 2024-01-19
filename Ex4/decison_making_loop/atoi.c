#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
	 int i, n, sign;
	 for (i = 0; isspace(s[i]); i++); /* skip white space */

	 sign = (s[i] == '-') ? -1 : 1;
	 if (s[i] == '+' || s[i] == '-') /* skip sign */
	 i++;

	 for (n = 0; isdigit(s[i]); i++)
	 	n = 10 * n + (s[i] - '0');
	 return sign * n;
}

int main() {

	char a[]="2";
	int ans=atoi(a);
	printf("%d \n\n",ans);

	if(isalpha(a[0]))
		printf("type of a is character array \n\n");

	if(isdigit(a[0]))
		printf("type of a is integer digit \n\n");

	if(isdigit(ans))
		printf("ans is digit\n\n");

	if(isalpha(ans))
		printf("ans ia aphabate\n\n");


    	return 0;
}

