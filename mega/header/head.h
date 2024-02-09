#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book book;

void pl();
void menu();
void print_book();
void add_book();
void make_struct();
void new_copy();

int get_book_count();

book* get_structs();

void print_struct(book *);

book* find_book_by_name(book *ptr, char name[]);
