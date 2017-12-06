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
}member_s[100];
struct borrowed
{
    int borrowing_ID;
    int borrowed_ISBN;
    struct date date_issued;
    struct date date_due_to_return;
    struct date date_returned;
};
int size_b;
int size_m;
int main()
{
    char target[20];
    size_b=read_books(book_s);
    size_m=read_members(member_s);
    int a;
    view_main_menu();
    scanf("%d",&a);
    int n_menu;
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
                printf("Enter title : ");
                scanf("%s",target);
                action_search_book_by_title(size_b,target,book_s);
            }
            else if (a1==2)
            {
                system("cls");
                printf("Enter author : ");
            }
            else if (a1==3)
            {
                system("cls");
                printf("Enter ISBN : ");
            }
            else if (a1==4)
            {

                system("cls");
                printf("Enter category : \n");
            }
            else
            {

                system("cls");
                printf("--------------------------------------------------Enter a valid number--------------------------------------------------");
            }
            break;

        case 3:
            action_add_new_copy();
            break;

        case 4:
            action_delete_book();
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
    }
        break;
    case 3:
        view_menu_borrow_management();
        break;
    case 4:
        view_menu_admin_actions();
        break;
    case 5 :
        save_changes();
        break;
    case 6:
        quit();
        break;
    case 7:
        printf("%d\n",size_m);
        printf("%d\n",size_b);
        break;
    default :
        printf("Error : choose a valid number.");
    }
    return 0;
}


