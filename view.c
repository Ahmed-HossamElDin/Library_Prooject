#include "structs.h"
#include "actions.h"
void view_current_time()
{
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime (&rawtime);
            current_time.day=timeinfo->tm_mday;
            current_time.month=timeinfo->tm_mon + 1;
            current_time.year=timeinfo->tm_year + 1900;
            printf("                                        Today's date is : %d/%d/%d\n",current_time.day,current_time.month,current_time.year);

}
void view_main_menu()
{

    printf("\t\t\t\t\t!!!!!!!!!WELCOME>>>>>>>>>>>>>\n");

printf("(1) Book Management\n(2) Member Management\n(3) Borrow Management\n(4) Administrative actions\n(5) Save Changes\n(6) View all books\n(7) View all members\n(8) Exit\n");}

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
 printf("Are you sure?\n(1) Proceed and exit \n(2) Proceed and return to main menu \n(3) Back\n");
}


