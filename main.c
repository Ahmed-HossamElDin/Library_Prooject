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
    int n_menu,n_borrow,n_admin,n_exit,n_save;
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
                action_search_book_by_title(size_b,book_s);
            }
            else if (a1==2)
            {
                system("cls");
                action_search_book_by_author(size_b,book_s);
            }
            else if (a1==3)
            {
                system("cls");
                action_search_book_by_ISBN(size_b,book_s);
            }
            else if (a1==4)
            {

                system("cls");
                action_search_book_by_category(size_b,book_s);
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
            save_changes();
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


