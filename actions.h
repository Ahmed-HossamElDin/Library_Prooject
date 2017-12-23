#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
void action_save();
void action_add_book(int n);
void action_add_new_copy(int h,struct book* book[]);
void action_delete_book(int h);
void action_remove_member();
int read_books();
int read_members();
int read_members();
int read_borrows();
void save_changes(int h,int z,int k);
int validate_string(char str[]);
int validate_mail(char x[]);
int validate_phone_number(char y[]);
#endif // ACTIONS_H_INCLUDED
