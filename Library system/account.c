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
    printf("Please enter the administrator account:\n");
    scanf("%d",&username);
    printf("Please enter the password:\n");
    scanf("%s",&password);
    getchar();
    for(i=0; i<K; i++)
    {
        if(username==s[i].username)
        {
            if(strcmp(s[i].password,password)==0)
            {
                printf("login successful\n");
                system("cls");
                admin_system();
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("Incorrect username or password\n");
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
        printf("\nplease enter account:\n");
        scanf("%d",&username);
        printf("To confirm the input, please press Enter, to re-enter please press ESC");
        hit=getch();//暂停程序，当hit接受后继续
        for (; hit!=13&&hit!=27;)//保证只有输入CR或ESC
        {
            hit=getch();
        }
    }
    while(hit==27);
    printf("\nPlease enter the password:\n");
    scanf("%s",password);
    getchar();
    i=match(username,password);
    if(i==1)
    {
        printf("Log in successfully! Press any key to continue");
        getch();
        user_system();
    }
    else
    {
        if(i==-1)
        {
            printf("wrong password!");
            getch();
            user_land();
        }
        if(i==0)
            printf("this user does not exist");
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

    if ((fp=fopen("users.txt","r"))==NULL)
    {
        system ("cls");
        printf("\n This user does not exist! Please create a new account");
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
        printf("\nPlease enter the account in the following format:\nStudent ID Password\n");
        printf("please enter:");
        scanf("%d %s",&username,password);
        printf("Enter the password again:\n");
        scanf("%s",password1);
        if(strcmp(password,password1)==0)
        {
            flag=1;
            fprintf(fp,"%d %s\n",username,password);
            break;
        }
        else
        {
            printf("The two input passwords are inconsistent, please try again\n");
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
    printf("Created successfully, press any key to return");
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
        printf("\nPlease enter the account you want to delete:");//输入删除账号
        scanf("%d",&username);
        printf("\nPlease press Enter to confirm deletion, press Esc to cancel\n");
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
    printf("\nsuccessfully deleted \nPress any key to return to the previous level\n");
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
        printf("Not yet registered, please register\n");
        fp = fopen("users.txt","w");
        getchar();
        system("cls");
        loadmenu();
    }
    fp = fopen("users.txt","r");
    printf("please enter account:\n");
    scanf("%d",&username);
    printf("Please enter the password:\n");
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
                printf("Please enter a new password:\n");
                scanf("%s",password1);
                printf("Please enter the new password again:\n");
                scanf("%s",password2);
                if(strcmp(password1,password2)==0)
                {
                    strcpy(s[k].password,password1);
                    printf("password has been updated!\n");
                    Sleep(2000);
                    system("cls");
                }
                else
                {
                    printf("The two password entries are inconsistent, press any key to exit!\n");
                    getch();
                    user_system();
                    system("cls");
                }
            }
        }
    }
    if(flag==0)
    {
        printf("This user has not registered yet, please register\n");
        Sleep(3000);
    }
    if(flag==1)
    {
        printf("Enter the password incorrectly, please re-enter\n");
        Sleep(3000);
    }
    fp = fopen("users.txt","w");
    for(j=0; j<m; j++)
    {
        fprintf(fp,"%d %s\n",s[j].username1,s[j].password);
    }
    fclose(fp);
    system("cls");
    user_system();
}
