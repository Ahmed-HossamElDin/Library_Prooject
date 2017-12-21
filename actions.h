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
void save_changes(int h,int z);
void validate_string(char str[]);
int validate_mail(char x[]);
void validate_phone_number(char y[]);
void borrow_book();
#endif // ACTIONS_H_INCLUDED
