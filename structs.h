#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <time.h>
struct book
{
    char title[60];
    char author[60];
    char publisher[60];
    char ISBN[16];
    char cat[20];
    int no_copies;
    int current_no_copies;
    time_t date_of_publishing;
};
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
    long phone_number;
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



#endif // STRUCTS_H_INCLUDED
