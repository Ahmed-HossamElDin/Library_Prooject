#include "structs.h"
#include "actions.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void view_current_time()
{
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime (&rawtime);
            current_time.day=timeinfo->tm_mday;
            current_time.month=timeinfo->tm_mon + 1;
            current_time.year=timeinfo->tm_year + 1900;
            printf(ANSI_COLOR_CYAN"                                        Today's date is : %d/%d/%d\n"  ANSI_COLOR_RESET,current_time.day,current_time.month,current_time.year);

}
void view_main_menu()
{ /*views main menu options*/

    printf(ANSI_COLOR_RED  "\t\t\t\t\t!!!!!!!!!WELCOME>>>>>>>>>>>>>\n"   ANSI_COLOR_RESET "\n");

printf(ANSI_COLOR_GREEN"(1) Book Management\n(2) Member Management\n(3) Borrow Management\n(4) Administrative actions\n(5) Save Changes\n(6) View all books\n(7) View all members\n(8) Exit\n"ANSI_COLOR_RESET);}

void view_menu_book_management()
{/*views view menu options*/
    system("cls");

    printf(ANSI_COLOR_YELLOW"(1) Insert a new book\n(2) Search for a book\n(3) Add New Copy\n(4) Delete book\n(5) Back\n"ANSI_COLOR_RESET);


}



void view_menu_member_management()
{/*views member menu options*/
    system("cls");
    printf("(1) Registration\n(2) Remove member\n(3) Back\n");
}
void view_menu_borrow_management()
{/*views borrow menu options*/
    system("cls");
    printf("(1) Borrow a Book\n(2) Return a Book\n(3) Back\n");
}

void view_menu_admin_actions()
{/*views borrow menu options*/
    system("cls");
    printf("(1) Overdue Books\n(2) Most Popular Books\n(3) Back\n");
}

void view_search_menu()
{/*views search menu options*/
    system("cls");
    printf("search by : (1) title\n            (2) author\n            (3) ISBN\n            (4) category\n");
}
void view_exit_menu()
{/*views exit menu options*/
    system("cls");
        printf("(1) Save and exit\n(2) exit without saving\n(3) Back\n");
}
void view_save_menu(){/*views save menu options*/
 system("cls");
 printf("Are you sure?\n(1) Proceed and exit \n(2) Proceed and return to main menu \n(3) Back\n");
}
