#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
void action_save();
void action_insert_book(int size);
void action_search_book_by_title(int n,char target[],struct book books[]);
void action_add_new_copy();
void action_delete_book();
void action_remove_member();
int read_books();
int read_members();
int read_members();
void save_changes();
void quit();
#endif // ACTIONS_H_INCLUDED
