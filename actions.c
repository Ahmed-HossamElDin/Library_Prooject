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
    printf("Enter the book title\n");
    scanf(" %[^\n]s", b.title);
    printf("\nEnter the book author\n");
    scanf(" %[^\n]s", b.author);
    printf("\nEnter the book publisher\n");
    scanf(" %[^\n]s", b.publisher);
    printf("\nEnter the category\n");
    scanf("%s", b.category);
    printf("\nEnter the book ISBN\n");
    scanf(" %ld",&b.ISBN);
    printf("\nEnter the number of copies\n");
    scanf("%d",&b.no_copies);
    printf("\nEnter current the number of copies\n");
    scanf("%d",&b.current_no_copies);
    printf("\nEnter the date in dd mm yy format\n");
    scanf("%d%d%d",&b.date_of_publishing.day,&b.date_of_publishing.month,&b.date_of_publishing.year);

    fprintf(books,"%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d",b.title,b.author,b.publisher,b.category,b.ISBN,b.no_copies,b.current_no_copies,b.date_of_publishing.day,b.date_of_publishing.month,b.date_of_publishing.year);

    fclose(books);

}

void action_add_new_copy(int h,struct book book[])
{
    long a;
    int b,i;
    printf("Enter Book's ISBN: ");
    scanf("%d",&a);
    printf("Enter number of copies:");
    scanf("%d",&b);
    if(b<0)
        printf("Invalid input");

    else
    {
        for(i=0; i<h; i++)
        {

            if(a==book_s[i].ISBN)
            {
                book_s[i].current_no_copies+=b;
                book_s[i].no_copies=book_s[i].current_no_copies;
                printf("%d",book_s[i].current_no_copies);
                break;
            }

        }

    }
}

void action_delete_book(int h)
{
   long a;
int i;
    printf("Enter Book's ISBN: ");
    scanf("%ld",&a);
    for(i=0;i<h;i++)
    {
        if(a==book_s[i].ISBN)
        {
            book_s[i].ISBN=0;
            save_changes(h);
            break;
        }

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
    fprintf(members,"\n%s,%d,%d/%d/%s,%ld,%d,%s",m.name,n+1,m.member_adress.building,m.member_adress.street,m.member_adress.city,m.phone_number,m.age,m.email);
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

void save_changes(int h)
{
int c;
    FILE* save;
    save =fopen("books.txt","w");
    for(c=0;c<h;c++)
    {
      if(book_s[c].ISBN==0){
}else{
        fprintf(save,"%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year);
        fprintf(save,"\n");
    }}
    fclose(save);
}
void quit()
{

}
