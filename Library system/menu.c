//
// Created by Administrator on 2021/3/20.
//

#include "menu.h"
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

void loadmenu_display()//显示登录菜单
{
    printf("\n\n\t    欢迎使用图书信息管理系统\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.图书管理员处理系统\n\n");
    printf("\n\n\t\t2.普通读者管理系统\n\n");
    printf("\n\n\t\t3.退出系统\n\n");
    printf("\n\n\t    请按键选择，回车确定\n");
    printf("**********************************************");
    return ;
}

void admin_land()
{
    system("cls");
    FILE*fp;
    struct admin_land_info s[S];
    int i,N=0,j;
    int username,flag=0;
    char password[20];
    int K=0;
    if((fp = fopen("administrator.txt","r"))==NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    K = admin_account_num();
    for(; !feof(fp);)
    {
        fscanf(fp,"%d %s",&s[N].username,s[N].password);
        N++;
    }
    fclose(fp);
    printf("请输入管理员账号:\n");
    scanf("%d",&username);
    printf("请输入密码:\n");
    scanf("%s",&password);
    getchar();
    for(i=0; i<K; i++)
    {
        if(username==s[i].username)
        {
            if(strcmp(s[i].password,password)==0)
            {
                printf("登录成功\n");
                system("cls");
                admin_system();
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("账号或密码错误\n");
        Sleep(2000);
        system("cls");
        loadmenu();
    }
}

int admin_account_num()//统计管理员账号密码文本个数
{
    FILE *fp;
    int username=0,n;
    char password[20];
    fp=fopen("administrator.txt","r");//打开文件
    for (n = 0; !feof(fp); n++) //逐个读文件
        fscanf(fp,"%d %s",&username,password);
    fclose(fp);//关闭文件
    return n;//返回个数
}

void user_land()
{
    int username;
    char password[20];
    int i=2,j,k,n;
    char hit=0;
    system("cls");
    do
    {
        printf("\n请输入账号:\n");
        scanf("%d",&username);
        printf("确认输入请按回车，重新输入请按ESC");
        hit=getch();//暂停程序，当hit接受后继续
        for (; hit!=13&&hit!=27;)//保证只有输入CR或ESC
        {
            hit=getch();
        }
    }
    while(hit==27);
    printf("\n请输入密码:\n");
    scanf("%s",password);
    getchar();
    i=match(username,password);
    if(i==1)
    {
        printf("登陆成功!按任意键继续");
        getch();
        user_system();
    }
    else
    {
        if(i==-1)
        {
            printf("密码错误!");
            getch();
            user_land();
        }
        if(i==0)
            printf("不存在此用户");
        getch();
        system("cls");
        loadmenu();
    }
}

int match(int u, char p[20])
{
    FILE*fp;
    int n=0,i=0;
    int username;
    char password[20];

    if ((fp=fopen("land.txt","r"))==NULL)
    {
        system ("cls");
        printf("\n 不存在此用户!请新建账户");
        getch();
        system("cls");
        loadmenu();
    }
    for(; !feof(fp);)
    {
        fscanf(fp,"%d%s",&username,password);
        if(u==username)
        {
            if(strcmp(p,password)==0)
                return 1;
            else
            {
                return -1;
            }
        }
    }
    return 0;
}