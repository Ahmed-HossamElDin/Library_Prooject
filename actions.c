#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
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
    LABEL:
    {
    printf("\nEnter the total number of copies\n");
    scanf("%d",&book_s[n].no_copies);
    printf("\nEnter current the number of copies\n");
    scanf("%d",&book_s[n].current_no_copies);
    if(book_s[n].current_no_copies>book_s[n].no_copies)
     {
        system("cls");
        printf("Cyrrent number of copies can't be more than total number of copies\nEnter (1) to re-enter\n      (2) to exit\n");
        int choice;
        scanf("%d",&choice);
        if (choice==1)
            goto LABEL;
        else if (choice==2)
            exit(0);
        else
            printf("Enter a valid choice");

     }
    }
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
    NAME_SCAN:
    scanf(" %[^\n]s", m.name);
    int nm;
    nm=validate_string(m.name);
    if (nm==1){}
    else
    {
        printf("wrong !! enter a valid word\n");
        goto NAME_SCAN;
    }

    printf("\nEnter member address \n(building number,street,city)\n");
    scanf(" %d",&m.member_adress.building);
    printf(",");
    STREET_SCAN:
    scanf(" %s",m.member_adress.street);
    int st;
    st=validate_string(m.member_adress.street);
    if (st==1){}
    else
    {
        printf("wrong !! enter a valid word\n");
        goto STREET_SCAN;
    }

    printf(",");
    CITY_SCAN:
    scanf(" %s", m.member_adress.city);
    int ct;
    ct=validate_string(m.member_adress.city);
    if (ct==1){}
    else
    {
        printf("wrong !! enter a valid word\n");
        goto CITY_SCAN;
    }
    printf("\nEnter the member phone number\n");
    PHONE_SCAN:
    scanf("%s",m.phone_number);
    int ph=validate_phone_number(m.phone_number);
    if (ph==1){}
    else
    {
        printf("wrong !! enter a valid phone number\n");
        goto PHONE_SCAN;
    }
    printf("\nEnter the number age\n");
    scanf("%d",&m.age);
    printf("\nEnter the member e-mail\n");
    MAIL_SCAN:
    scanf("%s",m.email);
    int ml;
    ml = validate_mail(m.email);
    if (ml==1){}
    else
    {
        printf("wrong !! enter a valid mail address in the form of example@domain.com\n");
        goto MAIL_SCAN;
    }
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
        fscanf(members,"%[^,],%d,%d/%[^/]/%[^,],%[^,],%d,%s",membera[a].name,&membera[a].ID,&membera[a].member_adress.building,membera[a].member_adress.street,membera[a].member_adress.city,&membera[a].phone_number,&membera[a].age,membera[a].email);
        fscanf(members,"\n");
        a++;
    }
    fclose(members);
    return a;
}

void save_changes(int h,int z)
{
    int c;
    FILE* save_a;
    FILE* save_b;
    FILE* save_m;
    save_b=fopen("books.txt","w");
    save_m=fopen("members.txt","w");
    save_a=fopen("borrow.txt","w");
    for(c=0; c<h; c++)
    {
        if(book_s[c].ISBN==0)
        {
        }
        else
        { if(c==0)
            fprintf(save_b,"%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year);
          else
            fprintf(save_b,"\n%s,%s,%s,%s,%ld,%d,%d,%d/%d/%d",book_s[c].title,book_s[c].author,book_s[c].publisher,book_s[c].category,book_s[c].ISBN,book_s[c].no_copies,book_s[c].current_no_copies,book_s[c].date_of_publishing.day,book_s[c].date_of_publishing.month,book_s[c].date_of_publishing.year);
        }
    }
        for(c=0; c<z; c++)
        {
            if (member_s[c].ID==0)
            {
            }
            else
            {
            if(c==0)
                fprintf(save_m,"%s,%d,%d/%s/%s,%s,%d,%s",member_s[c].name,z+1,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email);
            else
                fprintf(save_m,"\n%s,%d,%d/%s/%s,%s,%d,%s",member_s[c].name,z+1,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email);
            }
        }
        if (borrow_s[c].ID==0)
            {
            }
            else
            {
                fprintf(save_m,"%s,%d,%d/%s/%s,%s,%d,%s",member_s[c].name,z+1,member_s[c].member_adress.building,member_s[c].member_adress.street,member_s[c].member_adress.city,member_s[c].phone_number,member_s[c].age,member_s[c].email);
            }
            fprintf(save_a,"%d,%ld,%d/%d/%d,%d/%d/%d,%d/%d/%d",borrow_s[0].ID,borrow_s[0].ISBN,borrow_s[0].date_issued.day,borrow_s[0].date_issued.month,borrow_s[0].date_issued.year,borrow_s[0].date_due_to_return.day,borrow_s[0].date_due_to_return.month,borrow_s[0].date_due_to_return.year);
        fclose(save_b);
        fclose(save_m);
        fclose(save_a);
    }
int validate_string(char str[])
{
    int x,i;
    x=strlen(str);
    for(i=0; i<x; i++)
    {
        if(((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return 1;
            else return 0;
    }

}
int validate_mail(char x[])
// returns one if mail meets criteria
{
    int length=0;
    char temp=x[0];
    while(temp)
    {
        length++;
        temp=x[length];
    }

    if(x[length-4]!='.')
    {
        return 0;
    }

    int i;
    for(i=0; i<length; i++)
    {
        if(x[i]=='@')
        {
            if(i>0 && i<length-5)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

}
int validate_phone_number(char y[])
{
    int x;
    x=strlen(y);
    if(!((y[0]='0')&&(y[1]='1')&&(x==11)))
    {
           return 1;
    }
    else return 0;
}


