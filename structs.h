#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <time.h>
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
    char category[60];
    long ISBN;
    int no_copies;
    int current_no_copies;
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
    int ID;
    struct adress member_adress;
    long phone_number;
    int age;
    char email[50];
}member_s[100];
struct borrowed
{
    int borrowing_ID;
    int borrowed_ISBN;
    struct date date_issued;
    struct date date_due_to_return;
    struct date date_returned;
};
#endif // STRUCTS_H_INCLUDED
