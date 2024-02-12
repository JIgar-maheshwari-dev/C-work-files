#include "head.h"
#include "struct.h"

char *termi(char *str)
{
	char *new_str = strdup(str);
	char *ptr = new_str + strlen(new_str) - 1;

	while (ptr >= new_str && isspace(*ptr))
	{
		*ptr = '\0';
		ptr--;
	}

	return new_str;
}

book *find_book_by_name(book *ptr, char name2[])
{

	int c = get_book_count();
	book *temp = ptr, *tt = NULL;

	for (int i = 0; i <= c; i++)
	{

		char *temp2 = termi(temp->name);

		if (!(strcmp(temp2, name2)))
		{
			printf("match found \n");
			return temp;
		}

		temp++;
	}

	return tt;
}
