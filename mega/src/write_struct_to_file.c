#include "head.h"
#include "struct.h"

char file[] = "/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt";

void write_struct(book *ptr,int n)
{
    FILE *fp;
    //  fp=fopen(file,"a");
    //  printf("book name = %s\n", ptr->name);
    //  printf("book no. = %d\n", ptr->book_no);

    char pattern[20] = " Book no  : ";
    char str[50];

    sprintf(str, "%s%d", pattern, ptr->book_no);

    fp = fopen(file, "rw+");
    int offset = get_offset(fp,str);

    fseek(fp, offset, 0);
    if(n==0)
        fprintf(fp, " Name : %s \n Genre : %s\n Author : %s\n Date IN : %s\n Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n", ptr->name, ptr->genre, ptr->author, ptr->date_IN, ptr->total_pages, 000, ptr->price, ptr->copy);

    if(n==1)
        fprintf(fp, " Name : %s \n Genre : %s\n Author : %s\n Date IN : %s\n Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n", ptr->name, ptr->genre, ptr->author, ptr->date_IN, ptr->total_pages, 000, ptr->price, --(ptr->copy));

    fclose(fp);

    printf("Written to file successfully \n ");
}

// Book no  : 4
// Book no  : 4
