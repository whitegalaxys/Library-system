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
            case '0':Massage_Save();break;
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
            case '0':break;
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
            case '0':break;
            default:printf("\t\tInput errors, please re-enter\n");Sleep(1500);break;
        }
    }
}

void admin_system(Manager *t)
{
    char ml='1';
    while(ml!='0')
    {
        admin_system_display();
        printf("\t\t：");
        scanf("%c",&ml);
        while(getchar()!='\n');
        switch(ml)
        {
            case '1':add_book();break;
            case '2':remove_book();break;
            case '3':Lookofnum();break;
            case '4':Manager_Manager_Stu();break;
            case '5':Manager_Change_Password(t);break;
            case '0':admin_system_land();break;
            default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
        }
    }
}

void user_system(Student *enter_stu)
{
    char sl='1';
    while(sl!='0')
    {
        user_system_display();
        printf("\t\t：");
        scanf("%c", &sl);
        while (getchar() != '\n');
        switch (sl) {
            case '1':
                Stu_Borrow(enter_stu);
                break;
            case '2':
                Stu_Back(enter_stu);
                break;
            case '3':
                Find_Book();
                break;
            case '4':
                Find_Theborrow(enter_stu);
                break;
            case '5':
                Change_Stupassword(enter_stu);
                break;
            case '0':
                user_system_land();
                break;
            default:
                printf("\t\t输入错误，请重新输入\n");
                Sleep(3000);
                break;
        }
    }
}

void Manager_Manager_Stu(void)
{

    char mms='1';

    while(mms!='0')
    {
       Manager_Manager_Stu_display();
        scanf("%c",&mms);
        while(getchar()!='\n');
        switch(mms)
        {
            case '1':Manager_Look_Stu();break;
            case '2':deluser();break;
            case '0':break;
            default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
        }
    }
}

void loadmenu_display()//显示登录菜单
{
    system("CLS");
    printf("\n\n\t    Welcome to use book information management system\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.Student system\n\n");
    printf("\n\n\t\t2.Manager System\n\n");
    printf("\n\n\t\t0.Exit system\n\n");
    printf("\n\n\t    Please press the number keys to select, press Enter to confirm\n");
    printf("**********************************************\n");
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
    printf("\n 2.Delete book\n\n");
    printf("\n 3.View books\n\n");
    printf("\n 4.Manage student accounts\n\n");
    printf("\n 5.Manager changes password\n\n");
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
    printf("**************************************************");
    printf("\n\n 1.Sign in\n\n");
    printf("\n\n 2.Register an account\n\n");
    printf("\n\n 3.Retrieve password\n\n");
    printf("\n\n 0.Exit system\n\n");
    printf("*************************************************\n");
}

void Manager_Manager_Stu_display()
{
    system("CLS");
    printf("\n\n\n\n\t\t\t请选择\n\n");
    printf("\t\t\t1)查看学生名单\n");
    printf("\t\t\t2)删除学生号码并归还所有书籍\n");
    printf("\t\t\t0)退出\n");
    printf("\n\t\t：");
}