#include "structs.h"
#include "actions.h"
void view_main_menu()
{

    printf("\t\t\t\t\t!!!!!!!!!WELCOME>>>>>>>>>>>>>\n");

    printf("(1) Book Management\n(2) Member Management\n(3) Borrow Management\n(4) Administrative actions\n(5) Save Changes\n(6) Exit\n\n");
}

void view_menu_book_management()
{
    system("cls");

    printf("(1) Insert a new book\n(2) Search for a book\n(3) Add New Copy\n(4) Delete book\n(5) Back\n");


}



void view_menu_member_management()
{
    system("cls");
    printf("(1) Registration\n(2) Remove member\n(3) Back\n");
}
void view_menu_borrow_management()
{
    system("cls");
    printf("(1) Borrow a Book\n(2) Return a Book\n(3) Back\n");
}

void view_menu_admin_actions()
{
    system("cls");
    printf("(1) Overdue Books\n(2) Most Popular Books\n(3) Back\n");
}

void view_search_menu()
{
    system("cls");
    printf("search by : (1) title\n            (2) author\n            (3) ISBN\n            (4) category\n");
}
void view_exit_menu()
{
    system("cls");
        printf("(1) Save and exit\n(2) exit without saving\n(3) Back\n");
}
void view_save_menu(){
 system("cls");
 printf("Are you sure?\n(1) Proceed \n(2) Back\n");
}
