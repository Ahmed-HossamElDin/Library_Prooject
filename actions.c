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

void action_add_new_copy()
{
    system("cls");
}

void action_delete_book()
{
    system("cls");

}
void action_add_member(int n)
{
    system("cls");
    struct member m;
    FILE *members;
    members = fopen("members.txt","a");
    printf("enter the member name\n");
    scanf(" %[^\n]s", m.name);
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
    fprintf(members,"\n%s,%d,%d\%d\%s,%d,%d,%s",m.name,(n+1)/2,m.member_adress.building,m.member_adress.street,m.member_adress.city,m.phone_number,m.age,m.email);

    fclose(members);
}
void action_remove_member()
{

}
int read_books(struct book booka[])
{
    int c=0;
    FILE* books;
    books =fopen("books.txt","r");
    while (!feof(books))
    {
        fscanf(books,"%[^,],%[^,],%[^,],%d,%d,%d,%[^,],%d/%d/%d\n",booka[c].title,booka[c].author,booka[c].publisher,&booka[c].ISBN,&booka[c].no_copies,&booka[c].current_no_copies,booka[c].cat,&booka[c].date_of_publishing.day,&booka[c].date_of_publishing.month,&booka[c].date_of_publishing.year);
        fscanf(books,"\n");
        c++;
    }
    fclose(books);
    return c;
}
int read_members(struct member membera[])
{
    int a=0;
    FILE* members;
    members =fopen("members.txt","r");
    while (!feof(members))
    {
        fscanf(members,"%[^,],%d,%d,%d,%[^,],%d,%d,%s",membera[a].name,&membera[a].ID,&membera[a].member_adress.building,&membera[a].member_adress.street,membera[a].member_adress.city,&membera[a].phone_number,&membera[a].age,&membera[a].email);
        fscanf(members,"\n");
        a++;
    }
    fclose(members);
    return a;
}

void action_search_book_by_title(int n,char target[],struct book books[])
{
    int i,x,j=0,y,counter=0,z,flag=0;
    x=strlen(target);
    for(i=0; i<n; i++)
    {
        y=strlen(books[i].title);
        for(j=0; j<y; j++)
            z=0;
        {
            if (books[i].title[j]==target[z])
            {

                while(books[i].title[j]==target[z])
                {
                    counter++;
                    z++;
                    j++;
                }
                if (z==x)
                {
                    flag++;
                    printf("\n%s,%s,%s,%d,%d,%s,%d/%d/%d",books[i].title,books[i].author,books[i].publisher,books[i].ISBN,books[i].no_copies,books[i].current_no_copies,books[i].cat,books[i].date_of_publishing.day,books[i].date_of_publishing.month,books[i].date_of_publishing.year);
                }
            }
        }

    }
    if (flag==0)
        printf("No books found");
}
void save_changes()
{

}
void quit()
{

}
