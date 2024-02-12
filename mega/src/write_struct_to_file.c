#include "head.h"
#include "struct.h"

char file[] = "/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt";

void write_struct(book *ptr)
{
    FILE *fp;
    //  fp=fopen(file,"a");
    //  printf("book name = %s\n", ptr->name);
    //  printf("book no. = %d\n", ptr->book_no);

    char pattern[20] = " Book no  : ";
    char n[50];

    sprintf(n, "%s%d", pattern, ptr->book_no);

    int offset = get_offset(n);
    // printf("offset = %d\n",offset);
    fp = fopen(file, "rw+");
    fseek(fp, offset, 0);

    fprintf(fp, " Name : %s \n Genre : %s\n Author : %s\n Issue date : %s Total pages : %d\n Shelf No. : %d\n Price : %d\n Copies available : %d \n", ptr->name, ptr->genre, ptr->author, "ABCD\n", ptr->total_pages, 000, ptr->price, ptr->copy);

    fclose(fp);

    printf("Written to file successfully \n ");
}

// Book no  : 4
// Book no  : 4
