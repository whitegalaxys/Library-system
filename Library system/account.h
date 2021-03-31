//
// Created by Administrator on 2021/3/21.
//

#ifndef CLIONPROJECTS_ACCOUNT_H
#define CLIONPROJECTS_ACCOUNT_H


typedef struct user{
    char user_passw[15];				//user password
    char user_find_question[30];		//Security Question
    char user_find_passw[15];		    //Secret question password
    char user_num[10];				    //User ID(account number)
    char user_name[20];			 	    //User's name
    char user_tel[15];			  	    //User's phone
    char user_bor_book[10][20];		    //ID of the book borrowed by the user
    struct user *next;				    //Next user
}User;

typedef struct Admin{
    char admin_name[15];				//Administrator's name
    char admin_acc[10];				    //Administrator's account
    char admin_passw[15];				//Administrator password
    struct Admin *next;			        //Next manager
}Admin;

User *User_head;//The head node of the user information linked list
Admin *Admin_head;//The head node of the administrator information linked list

//Register a new user account
void adduser();
//Delete user account
void deluser();
//Administrator login function
void admin_land();
//User login function
void user_land();
//The user retrieves the password through the secret security question
void password_find();
//Control the number of password digits entered by the user
void password_length_control(char *Password);
//Control the number of times that the password can be entered after a wrong input
int password_input_times(char *Password);
//Find the user by its account and return the node information of the book
User *find_user_by_id(char *User_num);
//Load user information from file to linked list
User *load_user(void);
//Load administrator information from file to linked list
Admin *load_admin(void);
//Find the administrator by its account and return the node information of the book
Admin *find_admin_by_id(char *Admin_num);
//Save user information from linked list to file
void user_save();
//Save administrator information from linked list to file
void admin_save();
//Administrator view all user information
void view_users(void);
//User borrowing function
void user_book_borrow(User *User_num);
//Check whether the book has been lent by the user
int whether_lent(User *User_num,char *Book_num);
//User return book function
void user_book_return(User *User_num);
//Print the information of the borrowed book when returning the book
void print_borrow_booklist(User *User_num);
//Handling of book information when returning books
void user_return_book_case(User *User_num,char *Book_num);
//Print user's borrowing record
void user_borrow_record(User *User_num);
//Admin change password
void admin_change_password(Admin *Admin_num);
//User change password
void user_change_password(User *User_num);
//User system menu
void user_system(User *enter_user);
//Administrator system menu
void admin_system(Admin *t);

#endif //CLIONPROJECTS_ACCOUNT_H


