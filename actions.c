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
void action_add_book(int n)
{

    system("cls");
    struct book b;
    printf("Enter the book title\n");
    scanf(" %[^\n]s", book_s[n].title);
    printf("\nEnter the book author\n");
    scanf(" %[^\n]s", book_s[n].author);
    printf("\nEnter the book publisher\n");
    scanf(" %[^\n]s", book_s[n].publisher);
    printf("\nEnter the category\n");
    scanf("%s", book_s[n].category);
    printf("\nEnter the book ISBN\n");
    scanf(" %ld",&book_s[n].ISBN);
    printf("\nEnter the number of copies\n");
    scanf("%d",&book_s[n].no_copies);
    printf("\nEnter current the number of copies\n");
    scanf("%d",&book_s[n].current_no_copies);
    printf("\nEnter the date in dd mm yy format\n");
    scanf("%d%d%d",&book_s[n].date_of_publishing.day,&book_s[n].date_of_publishing.month,&book_s[n].date_of_publishing.year);

}

void action_add_new_copy(int h,struct book book[])
{
    system("cls");
    long a;
    int b,i,flag=0;
    printf("Enter Book's ISBN: ");
    scanf("%ld",&a);
    printf("Enter number of copies:");
    scanf("%d",&b);
    if(b<0)
        printf("Invalid input");

    else
    {
        for(i=0; i<h; i++)
        {

            if(a==book_s[i].ISBN)
            {   flag=1;
                book_s[i].current_no_copies+=b;
                book_s[i].no_copies+=b;
                printf("Total copies of the book : %d\nCurrent copies of the book : %d",book_s[i].no_copies,book_s[i].current_no_copies);
                break;
            }

        }

    }
    if(!flag){
        printf("Book not found!!!!!!!!!!!!!!!!!!!");
    }
}

void action_delete_book(int h)
{
    long a;
    int i,flag=0;
    printf("Enter Book's ISBN: ");
    scanf("%ld",&a);
    for(i=0; i<h; i++)
    {
        if(a==book_s[i].ISBN)
        {   flag=1;
            book_s[i].ISBN=0;
            save_changes(h);
            break;
        }

    }

    if(!flag){
            system("cls");
        printf("Book not found!!!!!!!!!!!!!!!!!!!");
    }
}
void action_add_member(int n)
{
    system("cls");
    struct member m;
    FILE *members;
    members = fopen("members.txt","a");
    printf("Enter the member name\n");
    scanf(" %[^\n]s", m.name);
    printf("\nEnter member address\n");
    scanf(" %d",&m.member_adress.building);
    printf(",");
    scanf(" %d",&m.member_adress.street);
    printf(",");
    scanf(" %s", m.member_adress.city);
    printf("\nEnter the member phone number\n");
    scanf("%d",&m.phone_number);
    printf("\nEnter the number age\n");
    scanf("%d",&m.age);
    printf("\nEnter the member e-mail\n");
    scanf("%s",m.email);
    fclose(members);
}
void action_remove_member()
{

}
int read_books()
{
    int c=0;
    FILE* books;
    books =fopen("books.txt","r");
    while (!feof(books))
    {
        fscanf(books,"%[^,],%[^,],%[^,],%[^,],%ld,%d,%d,%d/%d/%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,&book_s[c].ISBN,&book_s[c].no_copies,&book_s[c].current_no_copies,&book_s[c].date_of_publishing.day,&book_s[c].date_of_publishing.month,&book_s[c].date_of_publishing.year);
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
        fscanf(members,"%[^,],%d,%d/%d/%[^,],%ld,%d,%s",membera[a].name,&membera[a].ID,&membera[a].member_adress.building,&membera[a].member_adress.street,membera[a].member_adress.city,&membera[a].phone_number,&membera[a].age,membera[a].email);
        fscanf(members,"\n");
        a++;
    }
    fclose(members);
    return a;
}

void save_changes(int h,int z)
{
    int c;
    FILE* save_b;
    FILE* save_m;
    save_b =fopen("books.txt","w");
    save_m=fopen("members.txt","w");
    for(c=0; c<h; c++)
    {
        if(book_s[c].ISBN==0)
        {
        }
        else
        {
            fprintf(save_b,"%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d\n",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year);
        }
    }
        for(c=0; c<z; c++)
        {
            if (member_s[c].ID==0)
            {
            }
            else
            {
                fprintf(save_m,"\n%s,%d,%d/%d/%s,%ld,%d,%s",member_s[c].name,z+1,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email);
            }
        }
        fclose(save_b);
        fclose(save_m);
    }
    void quit()
    {

    }
