//
// Created by Administrator on 2021/3/20.
//

#include "menu.h"
#include "account.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>


void loadmenu()
{
    char ma='1';

    while(ma!='0')
    {
        loadmenu_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&ma);
        while(getchar()!='\n');
        switch(ma)
        {
            case '1':user_system_land();break;
            case '2':admin_system_land();break;
            case '0':all_save();exit(0);
            default:printf("\t\tInput errors, please re-enter\n");Sleep(3000);break;
        }
    }
}

void admin_system_land()
{
    char mp='1';

    while(mp!='0')
    {
        admin_system_land_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&mp);
        while(getchar()!='\n');
        switch(mp)
        {
            case '1':admin_land();break;
            case '0':loadmenu();break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(3000);break;
        }
    }
}

void user_system_land()
{
    char sp='1';

    while(sp!='0')
    {
        user_system_land_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&sp);
        while(getchar()!='\n');
        switch(sp)
        {
            case '1':user_land();break;
            case '2':adduser();break;
            case '3':password_find();break;
            case '0':loadmenu();break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(1500);break;
        }
    }
}

void admin_system(Admin *t)
{
    char ml='1';
    while(ml!='0')
    {
        admin_system_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&ml);
        while(getchar()!='\n');
        switch(ml)
        {
            case '1':add_book();break;
            case '2':admin_add_copies();break;
            case '3':remove_book();break;
            case '4':look_of_num();break;
            case '5':admin_manage_User();break;
            case '6':admin_change_password(t);break;
            case '0':admin_system_land();break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(3000);break;
        }
    }
}

void user_system(User *enter_user)
{
    char sl='1';
    while(sl!='0')
    {
        user_system_display();
        printf("\t\tEnter your choice:");
        scanf("%c", &sl);
        while (getchar() != '\n');
        switch (sl) {
            case '1':
                user_book_borrow(enter_user);
                break;
            case '2':
                user_book_return(enter_user);
                break;
            case '3':
                find_book();
                break;
            case '4':
                user_borrow_record(enter_user);
                break;
            case '5':
                user_change_password(enter_user);
                break;
            case '0':
                user_system_land();
                break;
            default:
                printf("\t\tInput errors, please re-enter\n");
                Sleep(3000);
                break;
        }
    }
}


void admin_manage_User(void)
{

    char mms='1';

    while(mms!='0')
    {
       admin_manage_User_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&mms);
        while(getchar()!='\n');
        switch(mms)
        {
            case '1':view_users();break;
            case '2':deluser();break;
            case '0':break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(3000);break;
        }
    }
}

void find_book(void)
{
    Book *t=Book_head->next;

    if(t==NULL){
        printf("\t\tSorry, no books\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("Please select the search method you need\n");
    char mms='1';
    while(mms!='0')
    {
        find_book_display();
        printf("\t\tEnter your choice:");
        scanf("%c",&mms);
        while(getchar()!='\n');
        switch(mms)
        {
            case '1':find_book_by_title_display();break;
            case '2':find_book_by_author_display();break;
            case '3':find_book_by_year_display();break;
            case '0':break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(3000);break;
        }
    }
}

void find_book_by_title_display()
{
    char book_n[20];
    printf("\t\tPlease enter the title of the book you need to find:");
    gets(book_n);
    find_book_by_title(book_n);
}

void find_book_by_author_display()
{
    char book_n[20];
    printf("\t\tPlease enter the author of the book you need to find:");
    gets(book_n);
    find_book_by_author(book_n);
}

void find_book_by_year_display()
{
    unsigned int year;
    printf("\t\tPlease enter the year of the book you need to find:");
    scanf("%d", &year);
    find_book_by_year(year);
}

void loadmenu_display()//显示登录菜单
{
    system("CLS");
    printf("\n\n\t    Welcome to use book information management system\n\n");
    printf("*****************************************************************************");
    printf("\n\n\t\t1.User system\n\n");
    printf("\n\n\t\t2.Admin System\n\n");
    printf("\n\n\t\t0.Exit the system and save the data\n\n");
    printf("\n\n\t    Please press the number keys to select, press Enter to confirm\n");
    printf("*****************************************************************************\n");
}

void admin_system_land_display()
{
    system ("cls");
    printf("**************************************************");
    printf("\n\n 1.Sign in\n\n");
    printf("\n\n 0.Return to the previous level\n\n");
    printf("*************************************************\n");
}

void admin_system_display()
{
    system("cls");
    printf("**************************************************");
    printf("\n 1.Add book\n\n");
    printf("\n 2.Add copies\n\n");
    printf("\n 3.Delete book\n\n");
    printf("\n 4.View books\n\n");
    printf("\n 5.Manage User accounts\n\n");
    printf("\n 6.Admin changes password\n\n");
    printf("\n 0.Return to the previous level\n\n");
    printf("*************************************************\n");
}

void user_system_display()
{
    system("cls");
    printf("**************************************************");
    printf("\n 1.Borrow books\n\n");
    printf("\n 2.Return book\n\n");
    printf("\n 3.Find books\n\n");
    printf("\n 4.Borrowing records\n\n");
    printf("\n 5.User change password\n\n");
    printf("\n 0.Return to the previous level\n\n");
    printf("*************************************************\n");
}

void user_system_land_display()//主菜单
{
    system("cls");
    printf("******************************************************");
    printf("\n\n 1.Sign in\n\n");
    printf("\n\n 2.Register an account\n\n");
    printf("\n\n 3.Retrieve password\n\n");
    printf("\n\n 0.Return to the previous level\n\n");
    printf("*****************************************************\n");
}

void admin_manage_User_display()
{
    system("CLS");
    printf("******************************************************");
    printf("\n\n 1.View the list of Users\n\n");
    printf("\n\n 2.Delete User number and return all books\n\n");
    printf("\n\n 0.drop out\n\n");
    printf("******************************************************\n");
}

void find_book_display()
{
    system("CLS");
    printf("**************************************************");
    printf("\n\n 1.Find books by title\n\n");
    printf("\n\n 2.Find books by author\n\n");
    printf("\n\n 3.Find books by year\n\n");
    printf("\n\n 0.Return to the previous level\n\n");
    printf("**************************************************\n");
}