#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
void search_book_by_author(int n,struct book books[]);
void search_book_by_category(int n,struct book books[]);
void search_book_by_title(int n,struct book books[]);
void search_book_by_ISBN(int n,struct book books[]);
int size_b;
int size_m;
int main()

{
    char target[20];
    size_b=read_books(book_s);
    size_m=read_members(member_s);
    int a;
LABEL:
    system("cls");
    view_main_menu();
    scanf("%d",&a);
    int n_menu,n_borrow,n_admin,n_exit,n_save,s,delete_option;
    switch(a)
    {


    case 1 :
        view_menu_book_management();
        scanf("%d",&n_menu);
        switch(n_menu)
        {
        case 1:
            action_add_book(size_m);
            break;
        case 2:
            view_search_menu();
            int a1;
            scanf("%d",&a1);
            if (a1==1)
            {
                system("cls");
                search_book_by_title(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to top menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    exit(0);
                else printf("Enter a valid choice");
            }
            else if (a1==2)
            {
                system("cls");
                search_book_by_author(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to top menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    exit(0);
                else printf("Enter a valid choice");
            }
            else if (a1==3)
            {
                system("cls");
                search_book_by_ISBN(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to top menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    exit(0);
                else printf("Enter a valid choice");
            }
            else if (a1==4)
            {

                system("cls");
                search_book_by_category(size_b,book_s);
                int check;
                printf ("\n\nEnter (1) to go to top menu\nor    (2) to exit\n");
                scanf("%d",&check);
                if (check==1)
                    goto LABEL;
                else if (check==2)
                    exit(0);
                else printf("Enter a valid choice");
            }
            else
            {

                system("cls");
                printf("--------------------------------------------------Enter a valid number--------------------------------------------------");
            }
            break;

        case 3:
            system("cls");
            long a;
            int b,i,j;
            printf("Enter Book's ISBN: ");
            scanf("%d",&a);
            printf("Enter number of copies:");
            scanf("%d",&b);
            if(b<0)
                printf("Invalid input");

            else
            {
                for(i=0; i<size_b; i++)
                {

                    if(a==book_s[i].ISBN)
                    {
                        book_s[i].current_no_copies+=b;
                        printf("Total number of copies is :%d",book_s[i].current_no_copies);
                        break;
                    }

                }
            }
            printf("\n(1) Main Menu\n(2) Save Changes and exit\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:
                goto LABEL;
                break;
            case 2:
                save_changes(size_b);
                break;

            }
            break;
        case 4:
            system("cls");
            action_delete_book(size_b);
            printf("\n(1) Main Menu\n(2) Save Changes and exit\n");
            scanf("%d",delete_option);

            switch(delete_option)
            {
            case 1:
                goto LABEL;
                break;
            case 2:
                save_changes(size_b);
                break;

            }
            break;
        case 5:
            system("cls");
            goto LABEL;
            break;

        }
        break;
    case 2:
        view_menu_member_management();
        scanf("%d",&n_menu);
        switch(n_menu)
        {
        case 1:
            action_add_member(size_m);
            break;
        case 2:
            action_remove_member();
            break;
        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 3:
        view_menu_borrow_management();
        scanf("%d",&n_borrow);
        switch(n_borrow)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 4:
        view_menu_admin_actions();
        scanf("%d",&n_admin);
        switch(n_admin)
        {
        case 1:
            break;
        case 2:

        {
            system("cls");
            int diff[size_b];
            int i,temp,swapped;
            int j=0;
            for(i=0; i<size_b; i++)
            {
                diff[j]=book_s[i].no_copies-book_s[i].current_no_copies;
                j++;
            }
            while(1)
            {
                swapped=0;
                for(i=0; i<size_b-1; i++)
                {
                    if (diff[i]<diff[i+1])
                    {
                        temp=diff[i];
                        diff[i]=diff[i+1];
                        diff[i+1]=temp;
                        swapped=1;
                    }
                }
                if (swapped==0)
                {
                    break;
                }
            }
            printf("our most popular books : \n\n\n");

            for(i=0; i<size_b; i++)
            {
                if (diff[0]==book_s[i].no_copies-book_s[i].current_no_copies)
                {
                    printf("%s\n\n",book_s[i].title);
                }
            }
            for(i=0; i<size_b; i++)
            {
                if (diff[1]==book_s[i].no_copies-book_s[i].current_no_copies)
                {
                    printf("%s\n\n",book_s[i].title);
                }
            }

            for(i=0; i<size_b; i++)
            {
                if (diff[2]==book_s[i].no_copies-book_s[i].current_no_copies)
                {
                    printf("%s\n\n",book_s[i].title);
                }
            }



        }
        int bk;
        printf("(0)Return to main menu\n");
        scanf("%d",&bk);
        if(bk==0)
        {
            system("cls");
            goto LABEL;
        }

        break;

        case 3:
            system("cls");
            goto LABEL;
            break;
        }
        break;
    case 5 :
        view_save_menu();
        scanf("%d",&n_save);
        switch(n_save)
        {

        case 1:
            save_changes(size_b);
            break;
        case 2:
            system("cls");
            goto LABEL;
            break;
        }
        save_changes();
        break;
    case 6:
        view_exit_menu();
        scanf("%d",&n_exit);
        switch(n_exit)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            system("cls");
            goto LABEL;
            break;
            break;
        default :
            printf("Error : choose a valid number.");
        }
        return 0;
    }
}
void search_book_by_category(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book category: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].category),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_author(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book author: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].author),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_ISBN(int n,struct book books[])
{
    int i,flag;
    long target;
    printf("please enter the book ISBN: \n");
    scanf("%ld",&target);
    for(i=0; i<n; i++)
    {
        if(book_s[i].ISBN==target)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag=0;
        }
    }
    if (flag != 0)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}
void search_book_by_title(int n,struct book books[])
{
    int z,flag,i;
    char target[100];
    printf("Searching for Book...\n");
    printf("please enter the book title: \n");
    scanf("%s",target);
    for(i=0; i<n; i++)
    {
        z = strstr(strlwr(book_s[i].title),strlwr(target));
        if (z != NULL)
        {
            printf("\nBook found\n\n");
            printf("Title: %s\nAuthor:%s\nPublisher:%s\nISBN:%ld\nNumber of copies:%d\nCurrent number of copies:%d\nCategory:%s\nDate of publication:%d/%d/%d\n", book_s[i].title,
                   book_s[i].author,
                   book_s[i].publisher,
                   book_s[i].ISBN,
                   book_s[i].no_copies,
                   book_s[i].current_no_copies,
                   book_s[i].category,
                   book_s[i].date_of_publishing.day,
                   book_s[i].date_of_publishing.month,
                   book_s[i].date_of_publishing.year);
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n\nThe book is not found... \n\n");
    }
}


