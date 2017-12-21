#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
void action_save();
void action_insert_book(int size);
void action_add_new_copy(int h,struct book* book[]);
void action_delete_book(int h);
void action_remove_member();
int read_books();
int read_members();
int read_members();
void save_changes(int h,int z);
void quit();
#endif // ACTIONS_H_INCLUDED
