#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>

FILE * books;

struct date
{
    int day;
    int month;
    int year;
};
struct book
{
    char title[60];
    char author[60];
    char publisher[60];
    char ISBN[16];
    int no_copies;
    int current_no_copies;
    char cat[20];
    struct date date_of_publishing;
} book_s[100];
struct adress
{
    int  building;
    int  street;
    char  city[20];
};
struct member
{
    char name[50];
    int ID[10];
    struct adress member_adress;
    long phone_number;
    int age;
    char email[50];
};
struct borrowed
{
    int borrowing_ID;
    int borrowed_ISBN;
    struct date date_issued;
    struct date date_due_to_return;
    struct date date_returned;
};
int c;
    void read_books()
    {

c=0;
        FILE* books;
        books =fopen("books.txt","r");
        while (!feof(books))
        {
            fscanf(books,"%[,^] %s %s %s %d %d %s\n",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].ISBN,&book_s[c].no_copies,&book_s[c].current_no_copies,book_s[c].cat);
            fscanf(books,"\n");
            c++;
        }
        fclose(books);
}
int main()
{
read_books();

    printf("%s",book_s[0].title);

    return 0;
}


