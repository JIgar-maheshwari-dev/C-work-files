#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct book book;

extern char file[];

void pl();

void menu();

void print_book();

void add_book();

void make_struct();

void modify();

void issue_book();



void write_count(int n);

int get_book_count();

book *get_structs();

void print_struct(book *);

book *find_book_by_name(book *ptr, char name[]);

char *termi(char *str);

void check_book(char *, int);

void write_struct(book *ptr,int n);

int get_offset(FILE *fp,char pattern[]);
