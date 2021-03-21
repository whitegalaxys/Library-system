//
// Created by Administrator on 2021/3/21.
//

#include "account.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

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

int user_account_num()//统计普通用户账号密码文本个数
{
    FILE *fp;
    int username=0,n;
    char password[20];
    fp=fopen("users.txt","r");//打开文件
    for (n=0; !feof(fp); n++) //逐个读文件
        fscanf(fp,"%d %s",&username,password);
    n--;
    fclose(fp);//关闭文件
    return (n);//返回个数
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

void adduser()
{
    FILE *fp;
    int username,flag=0;
    char password[20],password1[20];
    char hit=0;
    if ((fp=fopen("users.txt","r"))==NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    system("cls");
    fp=fopen("users.txt","a");
    for(;;)
    {
        printf("\n请按以下格式输入账户:\n学号 密码\n");
        printf("请输入:");
        scanf("%d %s",&username,password);
        printf("再次输入密码:\n");
        scanf("%s",password1);
        if(strcmp(password,password1)==0)
        {
            flag=1;
            fprintf(fp,"%d %s\n",username,password);
            break;
        }
        else
        {
            printf("两次输入密码不一致，请重新操作\n");
            for(; hit!=13&&hit!=27;)
                hit=getch();
            if(hit=27){
                system("cls");
                users_info_management();
            }
            if(hit=13)
            {
                system("cls");
                adduser();
            }
        }
    }
    fclose(fp);
    printf("创建成功，按任意键返回");
    getch();
    system("cls");
    users_info_management();
}

void deluser()
{
    struct delete_user *head=NULL;
    struct delete_user *p,*p1,*p2;
    int username,username1;
    char password[20];
    char i,j,k,n=0;
    FILE *fp;
    if ((fp=fopen("users.txt","r"))==NULL)//打开文件
    {
        system ("cls");
        printf("File open error\n");
        getch();
    }
    else
    {
        system ("cls");
        printf("\n请输入你要删除的账号:");//输入删除账号
        scanf("%d",&username);
        printf("\n确认删除请回车，取消请按Esc\n");
        i=getch();
        for(; i!=13&&i!=27;)
            i=getch();
        if (i==27)
            users_info_management();
        fp=fopen("users.txt","r");
        j=user_account_num();
        for (k=0; k<j; k++)
        {
            fscanf(fp,"%d %s",&username1,password);
            if (username!=username1)
            {
                n++;
                if (n==1)
                {
                    p1=p2=(struct delete_user*)malloc(sizeof(struct delete_user));
                    head=p1;
                }
                else
                {
                    p2->next=p1;
                    p2=p1;
                    p1=(struct delete_user*)malloc(sizeof(struct delete_user));//新建链表
                }

                strcpy(p1->password2,password);
                p1->username2=username1;
            }
        }
        if (n==0)
        {
            head=NULL;
        }
        else
        {
            p2->next=p1;
            p1->next=NULL;
            fclose(fp);
        }
    }
    fp=fopen("users.txt","w");//清空文件，只写打开，然后关闭
    fclose(fp);
    fp=fopen("users.txt","a");//追加文件
    p=head;
    for (; p!=NULL;) //把链表内容覆盖到文件
    {
        fprintf(fp,"%-4d  %-5s\n",p->username2,p->password2);
        p=p->next;
    }
    fclose(fp);
    system ("cls");
    printf("\n删除成功 \n按任意键返回上一层\n");
    getch();
    users_info_management();
}

void password_change()
{
    system("cls");
    FILE*fp;
    struct passwordchange s[100];
    int i=0,j,k,m=0;
    int username,flag=0;
    char password[20],password1[20],password2[20];
    if((fp = fopen("users.txt","r"))==NULL)
    {
        printf("还未注册，请注册\n");
        fp = fopen("users.txt","w");
        getchar();
        system("cls");
        loadmenu();
    }
    fp = fopen("users.txt","r");
    printf("请输入账号:\n");
    scanf("%d",&username);
    printf("请输入密码:\n");
    scanf("%s",password);
    getchar();
    m=user_account_num();
    for(; !feof(fp);)
    {
        fscanf(fp,"%d %s",&s[i].username1,s[i].password);
        i++;
    }
    for(k=0; k<m; k++)
    {
        if(username==s[k].username1)
        {
            flag=1;
            if(strcmp(password,s[k].password)==0)
            {
                flag=2;
                printf("请输入新密码:\n");
                scanf("%s",password1);
                printf("请再次输入新密码:\n");
                scanf("%s",password2);
                if(strcmp(password1,password2)==0)
                {
                    strcpy(s[k].password,password1);
                    printf("修改密码成功!\n");
                    Sleep(2000);
                    system("cls");
                }
                else
                {
                    printf("两次密码输入不一致，按任意键退出!\n");
                    getch();
                    user_system();
                    system("cls");
                }
            }
        }
    }
    if(flag==0)
    {
        printf("此用户尚未注册,请注册\n");
        Sleep(3000);
    }
    if(flag==1)
    {
        printf("输入密码错误，请重新进入\n");
        Sleep(3000);
    }
    fp = fopen("land.txt","w");
    for(j=0; j<m; j++)
    {
        fprintf(fp,"%d %s\n",s[j].username1,s[j].password);
    }
    fclose(fp);
    system("cls");
    user_system();
}
