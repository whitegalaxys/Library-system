//
// Created by Administrator on 2021/3/20.
//

#include "menu.h"
#include "account.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>


void loadmenu()//登录页面函数
{
    char option;
    loadmenu_display();
    printf("\n");
    scanf("%c",&option);
    switch(option)//功能函数
    {
        case'1':
            admin_land();
            break;
        case'2':
            user_land();
            break;
        case'3':
            system("cls");
            exit(0);
            break;
    }
}

void admin_system()
{
    char option;
    admin_system_display();
    scanf(" %c",&option);
    switch(option)//功能函数
    {
        case'1':
            users_info_management();
            break;
        case'2':
            admin_book();
            break;
        case'3':
            system("cls");
            getchar();
            loadmenu();
            break;
    }
}

void user_system()
{
    char option;
    user_system_display();
    scanf(" %c",&option);
    switch(option)//功能函数
    {
        case'1':
        //    password_change();
            break;
        case'2':
            user_book();
            break;
        case'3':
            system("cls");
            getchar();
            loadmenu();
            break;
    }
}

void users_info_management()
{
    char option;
    users_info_management_display();
    getchar();
    scanf(" %c",&option);
    switch(option)//功能函数
    {
        case'1':
            adduser();
            break;
        case'2':
            deluser();
            break;
        case'3':
            admin_system();
            break;
    }
}

void admin_book()
{
    char option;
    admin_book_display();
    getchar();
    scanf(" %c",&option);
    switch(option)//功能函数
    {
        case'1':
            add_book();
            break;
        case'2':
            Delete();
            break;
        case'3':
            cksj();
            break;
        case'4':
            change();
            break;
        case'5':
            find();
            break;
        case'6':
            dzjy();
            break;
        case'7':
            admin_system();
            break;
    }
}

void user_book()
{
    char option;
    user_book_display();
    getchar();
    scanf("%c",&option);
    switch(option)//功能函数
    {
        case'1':
            cksj1();
            break;
        case'2':
            borrow1();
            break;
        case'3':
            Return1();
            break;
        case'4':
            find1();
            break;
        case'5':
            user_system();
    }
}

void loadmenu_display()//显示登录菜单
{
    printf("\n\n\t    Welcome to use book information management system\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.Librarian Processing System\n\n");
    printf("\n\n\t\t2.Reader system\n\n");
    printf("\n\n\t\t3.Exit system\n\n");
    printf("\n\n\t    Please press the number keys to select, press Enter to confirm\n");
    printf("**********************************************");
    return ;
}

void admin_system_display()
{
    system ("cls");
    printf("**************************************************");
    printf("\n\n 1.User information management\n\n");
    printf("\n\n 2.Book information management\n\n");
    printf("\n\n 3.Return to the previous level\n\n");
    printf("*************************************************\n");
    return ;
}

void users_info_management_display()
{
    system("cls");
    printf("**************************************************");
    printf("\n\n 1.Create a general reader account\n\n");
    printf("\n\n 2.Delete general reader account\n\n");
    printf("\n\n 3.Return to the previous level\n\n");
    printf("*************************************************\n");
    return ;
}

void admin_book_display()
{
    system("cls");
    printf("**************************************************");
    printf("\n 1.Add book\n\n");
    printf("\n 2.Delete book\n\n");
    printf("\n 3.Browse books\n\n");
    printf("\n 4.Edit book\n\n");
    printf("\n 5.Query books\n\n");
    printf("\n 6.Browse Reader Borrowing\n\n");
    printf("\n 7.Return to the previous level\n\n");
    printf("*************************************************\n");
    return ;
}

void user_book_display()
{
    system("cls");
    printf("**************************************************");
    printf("\n 1.Browse books\n\n");
    printf("\n 2.Borrow books\n\n");
    printf("\n 3.Return the book\n\n");
    printf("\n 4.Query books\n\n");
    printf("\n 5.Return to the previous level\n\n");
    printf("*************************************************\n");
    return ;
}

void user_system_display()//主菜单
{
    system ("cls");

    printf("**************************************************");
    printf("\n\n 1.User modify password\n\n");
    printf("\n\n 2.Borrowing system management\n\n");
    printf("\n\n 3.Return to the previous level\n\n");
    printf("*************************************************\n");
}