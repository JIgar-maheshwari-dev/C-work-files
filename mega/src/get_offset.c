#include "head.h"
#include "struct.h"

int get_offset(char pattern[])
{

	FILE *f = fopen(file, "r");
	if (f == NULL)
	{
		printf("file open error\n");
		return -1;
	}

	int offset = 0;

	while (!feof(f))
	{
		char buf[100];
		fgets(buf, 100, f);
		char *buf2 = termi(buf);
		// printf("%s\n",buf2);
		if (strcmp(buf2, pattern) == 0)
		{
			offset = ftell(f);
			break;
		}
	}

	return offset;
}