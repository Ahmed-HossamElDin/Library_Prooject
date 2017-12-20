#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
int size_b;
int size_m;
int main()
{
    char target[20];
    size_b=read_books(book_s);
    size_m=read_members(member_s);
    int a;
LABEL:
    view_main_menu();
    scanf("%d",&a);
    int n_menu,n_borrow,n_admin,n_exit;
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
            action_add_new_copy(size_b,book_s);
            break;

        case 4:
            action_delete_book(size_b);
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
            break;
        case 3:
            system("cls");
                        goto LABEL;
                        break;
        }
        break;
    case 5 :
        save_changes();
        break;
    case 6:
        view_exit_menu();
        scanf("%d",&n_exit);
        switch(n_exit){
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
}}


