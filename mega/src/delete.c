#include "head.h"
#include "struct.h"

extern char file[];

void delete()
{

	char temp[256];

	printf("Enter the book name  you want  :   ");
	getchar();
	gets(temp);

	book *temp1 = get_structs();

	book *found_book = find_book_by_name(temp1, temp);

	if (found_book == NULL)
	{
		printf("Book not found\n");
		system("sleep 2");
		menu();
	}

	del_struct(found_book);
	printf("Enter any key to continue ...");
	getchar();
	menu();
}

void del_struct(book *sptr)
{

	FILE *fp, *temp;
	fp = fopen(file, "r");

	int n1 = ((sptr->book_no) - 1) * 11 + 1;
	printf("\n n1 = %d\n", n1);
	int n2 = ((sptr->book_no) - 1) * 11 + 2 + 9;
	printf("\nn2 = %d\n", n2);

	if (fp == NULL)
	{
		printf("File not found\n");
		system("sleep 2");
		menu();
	}

	temp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt", "w");
	if (temp == NULL)
	{
		printf("File not found\n");
		system("sleep 2");
		menu();
	}

	int current_line = 1;
	char str[100];

	int lines = get_lines();

	while (current_line <= lines)
	{
		fgets(str, sizeof(str), fp);
		fputs(str, temp);
		current_line++;
	}

	// printf("copied file to temp \n");
	fclose(fp);
	fclose(temp);

	temp = fopen("/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/temp.txt", "r");

	char array[100];

	fp = fopen(file, "w");

	printf("total lines = %d\n", lines);

	current_line = 1;

	while (current_line <= lines)
	{
			if(current_line < n1){

				fgets(array, sizeof(array), temp);
                fputs(array, fp);
			//	printf("current_line = %d\t%s\n", current_line,array);
			}

			else if(current_line >= n1 && current_line <= n2){
				
				
				{
                	fgets(array, sizeof(array), temp);

				//	printf("<< >=n1 && <= n2 else past >>  current_line = %d\t%s  \n <<< don't take it >>> ", current_line,array);

				}

			}
			else if(current_line > n2){

				if(current_line%11 == 2){
					fgets(array, sizeof(array), temp);
				//	fgets(array, sizeof(array), temp);
					
				//	current_line++;
					fprintf(fp, " Book no  : %d \n", sptr->book_no++);

                //   	fprintf(fp, " here add new \n");
                    //fgets(array, sizeof(array), temp);
				}

				else {

					fgets(array, sizeof(array), temp);
					//printf("<<   >n2    >> current_line = %d\t%s\n", current_line,array);

					fputs(array, fp);
				}

            }
			// printf("current_line = %d\n", current_line);
			current_line++;
	}

	printf("current line  = %d \n", current_line);


	fclose(fp);
	fclose(temp);
	int n = get_book_count();
	write_count(n - 1);
	if(n-1 == 0)
		write_count(-1);

	printf("Book is removed from library succesfully \n ");
}
