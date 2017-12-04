#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>


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
int size;
int main()
{
view_main_menu();

int flag=0,i;
size=read_books();


    return 0;
}


