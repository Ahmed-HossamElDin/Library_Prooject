#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
typedef struct
{
    char title[60];
    char author[60];
    char isbn[16];
    int current_number_of_copies;
    int available_number_of_copies;
    time_t date_of_publishing;
}book;
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
    struct adress book_adress;
    int phone_number;
    int age;
    char email[50];
};
struct borrowed
{
    int borrowing_ID;
    int borrowed_ISBN;
    time_t date_issued;
    time_t date_due_to_return;
    time_t date_returned;
};

int main()
{
    view_main_menu();
    return 0;
}

