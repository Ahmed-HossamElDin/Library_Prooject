#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
void action_save()
{
    system("cls");

}
void action_add_book()
{

    system("cls");
    struct book b;
    FILE *books;
    books = fopen("books.txt","a");
    printf("enter the book title\n");
    scanf(" %[^\n]s", b.title);
    printf("\nenter the book author\n");
    scanf(" %[^\n]s", b.author);
    printf("\nenter the book publisher\n");
    scanf(" %[^\n]s", b.publisher);
    printf("\nenter the book ISBN\n");
    scanf(" %[^\n]s", b.ISBN);
    printf("\nenter the number of copies\n");
    scanf("%d",&b.no_copies);
    printf("\nenter current the number of copies\n");
    scanf("%d",&b.current_no_copies);
    printf("\nenter the category\n");
    scanf("%s",b.cat);
    printf("\nenter the date in dd mm yy format\n");
    scanf("%d%d%d",&b.date_of_publishing.day,&b.date_of_publishing.month,&b.date_of_publishing.year);

    fprintf(books,"\n%s,%s,%s,%s,%d,%d,%s,%d/%d/%d",b.title,b.author,b.publisher,b.ISBN,b.no_copies,b.current_no_copies,b.cat,b.date_of_publishing.day,b.date_of_publishing.month,b.date_of_publishing.year);

    fclose(books);

}

void action_search_book()
{
    system("cls");

}

void action_add_new_copy()
{
    system("cls");
}

void action_delete_book()
{
    system("cls");

}
void action_add_member()
{
    system("cls");
    struct member m;
    FILE *members;
    members = fopen("members.txt","a");
    printf("enter the member name\n");
    scanf(" %[^\n]s", m.name);
    printf("\nenter the member ID\n");
    scanf("%d",&m.ID);
    printf("\nenter member address\n");
    scanf(" %d",&m.member_adress.building);
    printf(",");
    scanf(" %d",&m.member_adress.street);
    printf(",");
    scanf(" %s", m.member_adress.city);
    printf("\nenter the member phone number\n");
    scanf("%d",&m.phone_number);
    printf("\nenter the number age\n");
    scanf("%d",&m.age);
    printf("\nenter the member e-mail\n");
    scanf("%s",m.email);
    fprintf(members,"\n%s,%d,%d\%d\%s,%d,%d,%s",m.name,m.ID,m.member_adress.building,m.member_adress.street,m.member_adress.city,m.phone_number,m.age,m.email);

    fclose(members);
}
void action_remove_member(){

}
