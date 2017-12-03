#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "structs.h"
void action_save(){
            system("cls");

}
void action_add_book(){

    system("cls");
    struct book b;
    FILE *books;
    books = fopen("books.txt","a");
      printf("enter the book title\n");
      scanf("%[^\n]%*c", b.title);
      printf("\nenter the book author\n");
      scanf("%[^\n]%*c", b.author);
      printf("\nenter the book publisher\n");
      scanf("%[^\n]%*c", b.publisher);
      printf("\nenter the book ISBN\n");
      scanf("%[^\n]%*c", b.ISBN);
      printf("\nenter the number of copies\n");
      scanf("%d",&b.no_copies);
      printf("\nenter the category\n");
      scanf("%s",b.cat);

      fprintf(books,"\n%s,%s,%s,%s,%d,%d,%s",b.title,b.author,b.publisher,b.ISBN,b.no_copies,b.current_no_copies,b.cat);

    fclose(books);

}

void action_search_book(){
            system("cls");

}

void action_add_new_copy(){
            system("cls");
}

void action_delete_book(){
            system("cls");

}
