#include "structs.h"
#include "actions.h"
void view_main_menu()
{

    printf("\t\t\t\t\t!!!!!!!!!WELCOME>>>>>>>>>>>>>\n");

    printf("(1) Book Management\n(2) Member Management\n(3) Borrow Management\n(4) Administrative actions\n(5) Save Changes\n(6) Exit\n\n");


void view_menu_book_management()
{
    system("cls");

    printf("(1) Insert a new book\n(2) Search for a book\n(3) Add New Copy\n(4) Delete book\n");

    int n_menu;
    scanf("%d",&n_menu);

    switch(n_menu)
    {
    case 1:
        action_add_book();
        break;
    case 2:
        action_search_book();
        break;
    case 3:
        action_add_new_copy();
        break;
    case 4:
        action_delete_book();
        break;
    }

}



void view_menu_member_management()
{
    system("cls");
    printf("(1) Registration\n(2) Remove member\n");
    int n;
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        action_add_member();
        break;
    case 2:
        action_remove_member();
        break;
    }
}
void view_menu_borrow_management()
{
    system("cls");
    printf("(1) Borrow a Book\n(3) Return a Book\n");
}

void view_menu_admin_actions()
{
    system("cls");
    printf("(1) Overdue Books\n(2) Most Popular Books");
}
