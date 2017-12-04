#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
struct book book_s[100];
int read_books()
{

FILE * books;
books =fopen("books.txt","r");
int c=0;
while (!feof(books))
{
    fscanf(books,"%[^\n]%*c,%[^\n]%*c,%[^\n]%*c,%[^\n]%*c,%d,%d,%[^\n]%*c",book_s[c].title,book_s[c].title,book_s[c].publisher,book_s[c].ISBN,&book_s[c].no_copies,&book_s[c].current_no_copies,book_s[c].cat);
    fscanf(books,"\n");
     c++;
}
fclose(books);
return c;
}
int main()
{
    view_main_menu();
    return 0;
}

