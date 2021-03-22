//
// Created by Administrator on 2021/3/21.
//

#include "account.h"
#include "menu.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
int id_record=0;
void admin_land()
{
    system("cls");
    char Manager_num[20];
    Manager *t;
    printf("\n\t\t账号：");
    gets(Manager_num);
    t=Manager_check(Manager_num);
    if(!t){
        printf("\t\t抱歉，账号不存在\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    printf("\t\t密码：");
    if(Password_Text_Find(t->man_passw)==0){
        printf("\n\t\t已经错误输入密码三次，将退出登录系统···\n");
        Sleep(5000);
        return;
    }
    Sleep(500);
    printf("\n\t\t登录中···\n");
    Sleep(500);
    printf("\t\t登录成功···\n");
    Sleep(500);
    printf("\t\t正在加载···\n");
    Sleep(1000);
    loadmenu();

}

Manager *Manager_check(char *Manager_num)
{

    Manager *t=Manager_head->next;
    while(t){
        if(strcmp(Manager_num,t->man_acc)==0)
            break;
        t=t->next;
    }
    return t;
}

void user_land()
{
    char enter_num[50];
    char enter_passw[20];
    int l=1;
    Student *enter_stu;
    while(l!=6){
        printf("\n\t\t请输入你的账号：");
        gets(enter_num);
        id_record=enter_num;
        l=strlen(enter_num);
        if(l!=6)
            printf("\t\t账号有误，请输入正确长度的账号\n");
    }
    enter_num[6]='\0';
    enter_stu=Find_Num(enter_num);
    if(enter_stu==NULL){
        printf("\n\t\t抱歉，无此账号");
        Sleep(500);
        printf("\n\t\t按任意键退出");
        getch();
        return;
    }
    printf("\t\t请输入密码：");
    if(Password_Text_Find(enter_stu->stu_passw)==0){
        printf("\n\t\t您已连续输错3次，将退出登录系统···");
        Sleep(2000);
        return;
    }
    Sleep(500);
    printf("\n\t\t正在登录");
    Sleep(500);
    printf("\n\t\t···\n");
    Sleep(500);
    printf("\n\t\t登录成功！按任意键继续\n");
        getch();
        user_system();

}

int Password_Text(char *Password)
{
    char password_tem[20];
    int tem=0;
    int n=0;    //检测输入次数
    while(n!=3){
        Password_Input(password_tem);
        if(strcmp(password_tem,Password)==0){
            tem=1;
            break;
        }
        else{
            n++;
            if(n!=3){
                printf("\n\t\t两次输入密码不一致，请重新输入,您还有%d次输入机会：",3-n);
            }
            else if(n==3)
                printf("\n\t\t输入错误\n");
        }
    }
    return tem;
}

void adduser()
{
    char password[20];
    Student *t;
    Student *new=(Student *)malloc(sizeof(Student));
    new->next=NULL;
    for(int i=0;i<10;i++){
        new->stu_bor_book[i][0]='0';
        new->stu_bor_book[i][1]='\0';
    }
    printf("\n\t\t欢迎来到注册系统！\n");
    Sleep(500);
    printf("\t\t正在加载···\n");
    Sleep(500);
    printf("\t\t请输入以下信息\n");
    printf("\t\t学号：");
    scanf("%s",new->stu_num);
    printf("\t\t姓名：");
    scanf("%s",new->stu_name);
    printf("\t\t电话：");
    scanf("%s",new->stu_tel);
    printf("\t\t密码：");
    Password_Input(new->stu_passw);
    printf("\n\t\t再次输入密码：");
    if(Password_Text(new->stu_passw)==0){
        printf("\n\t\t您已连续输错3次，将退出注册系统···");
        Sleep(5000);
        free(new);
        return;
    }
    printf("\n\n\t\t密保问题用于找回密码\n");
    printf("\t\t如：\n");
    printf("\t\t    我母亲的生日是？\n");
    printf("\t\t    我父亲的生日是？\n");
    printf("\t\t    我的生日是？\n");
    printf("\n\t\t密保问题：");
    scanf("%s",new->stu_find_question);
    printf("\t\t密保问题密码：");
    Password_Input(new->stu_find_passw);
    printf("\n\t\t再次输入密保问题密码：");
    if(Password_Text(new->stu_find_passw)==0){
        printf("\n\t\t您已连续输错3次，将退出注册系统···");
        Sleep(5000);
        free(new);
        return;
    }
    Sleep(500);
    printf("\n\t\t正在注册···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t注册成功！\n");
    printf("\t\t您的账号是: %s\n",new->stu_num);
    printf("\t\t请务必牢记账号密码！\n");
    while(getchar()!='\n');
    t=Student_head;
    while(t->next){
        t=t->next;
    }
    t->next=new;
    printf("创建成功，按任意键返回");
    getch();
    system("cls");
    users_info_management();
}

void deluser()
{
    char bh[20];
    BookArray *a;
    Student *head=Student_head;
    Student *t=Student_head->next;
    printf("\t\t正在打印学生名单···\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\t抱歉，暂无学生\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    printf("\n\n     *************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-15s%-12s%-10s\n\n",
           "姓名","学号","电话","密码","借书数量");
    while(t)
    {
        int n=0;
        for(int i=0;i<10;i++){
            if(strcmp(t->stu_bor_book[i],"0")!=0)
                n++;
        }
        printf("      %-10s%-12s%-15s%-12s%-10d\n",
               t->stu_name,t->stu_num,t->stu_tel,t->stu_passw,n);
        t=t->next;
    }
    printf("\n     *****************************************");
    printf("****************************\n\n\n");

    printf("\t\t请输入你想删除学生的账号：");
    gets(bh);
    t=Find_Stu(bh);
    if(!t){
        printf("\t\t抱歉，无该学生\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    Sleep(500);
    printf("\t\t正在删除···\n");
    Sleep(500);
    printf("\t\t删除成功！\n");
    for(int i=0;i<10;i++){
        if(strcmp(t->stu_bor_book[i],"0")!=0){
            *a=find_book_by_title(t->stu_bor_book[i]);
            a->array->copies+=1;
        }
    }
    t=Student_head->next;
    while(t){
        if(strcmp(bh,t->stu_num)==0){
            head->next=t->next;

            free(t);
            break;
        }
        head=t;
        t=t->next;
    }
    printf("\n删除成功 \n按任意键返回上一层\n");
    getch();
    users_info_management();
}

void password_find()
{
    Student *find_tem;
    char num_tem[50];
    char password_find[20];
    printf("\t\t欢迎来到找回密码系统\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    int l=1;
    while(l!=6){
        printf("\t\t请输入六位账号：");
        gets(num_tem);
        l=strlen(num_tem);
        if(l!=6)
            printf("\t\t账号有误，请输入正确长度的账号\n");
    }
    num_tem[6]='\0';
    find_tem=Find_Num(num_tem);
    printf("\t\t您输入的账号：");
    puts(num_tem);
    Sleep(500);
    printf("\t\t正在为您查找\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    if(find_tem==NULL){
        printf("\t\t抱歉，无此账号，即将退出注册系统\n");
        Sleep(1000);
        printf("\t\t···\n");
        Sleep(3000);
        return;
    }
    printf("\t\t%s，您好！\n",find_tem->stu_name);
    Sleep(300);
    printf("\t\t你设置的密保问题是： %s\n",find_tem->stu_find_question);
    Sleep(300);
    printf("\t\t请输入你的密保问题密码：");
    if(Password_Text_Find(find_tem->stu_find_passw)==0){
        printf("\n\t\t您已连续输错3次，将退出找回密码系统···\n");
        Sleep(1500);
        return;
    }
    Sleep(500);
    printf("\n\t\t正在查找\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    printf("\t\t%s 您好，您的密码是 ：%s",find_tem->stu_name,find_tem->stu_passw);
    printf("\n\t\t请牢记您的密码\n");
    printf("\t\t按任意键退出");
    getch();
    system("cls");
    user_system();
}

void Password_Input(char *Password)
{
    char ch;
    int i;
    int len=4;
    while(len<6 || len>10){
        for(i=0;i<20;i++){
            ch=getch();
            if(ch==8){
                if((i-1)>=0){
                    i-=2;
                    printf("\b \b");
                }
                else
                    i--;
                continue;
            }
            if(ch=='\r')
                break;
            Password[i]=ch;
            printf("*");
        }
        Password[i]='\0';
        len=strlen(Password);
        if(len<6 || len>10)
            printf("\n\t\t输入错误，请输入正确长度的密码:");
    }
}

int Password_Text_Find(char *Password)
{
    char password_tem[20];
    int tem=0;
    int n=0;    //检测输入次数
    while(n!=3){
        Password_Input(password_tem);
        if(strcmp(password_tem,Password)==0){
            tem=1;
            break;
        }
        else{
            n++;
            printf("\n\t\t输入错误，请重新输入，你还有%d次机会：",3-n);
        }
    }
    return tem;
}

Student *Find_Num(char *Stu_num)
{
    Student *t=Student_head->next;
    while(t){
        if(strcmp(t->stu_num,Stu_num)==0)
            break;
        t=t->next;
    }
    return t;
}

Student *Find_Stu(char *Stu_Stuty)
{
    Student *t=Student_head->next;
    while(t){
        if(strcmp(t->stu_num,Stu_Stuty)==0)
            break;
        t=t->next;
    }
    return t;
}

Student *Student_load(void)
{
    FILE *fp;
    Student *h=NULL,*t=h,*p;
    if((fp=fopen("Studentnode.txt","r"))==NULL){
        printf("\t\t打开失败\n");
        exit(1);
    }
    getc(fp);
    if(feof(fp)){
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while(!feof(fp)){
        p=(Student *)malloc(sizeof(Student));
        p->next=NULL;
        fscanf(fp,"%s",p->stu_passw);
        fscanf(fp,"%s",p->stu_find_question);
        fscanf(fp,"%s",p->stu_find_passw);
        fscanf(fp,"%s",p->stu_num);
        fscanf(fp,"%s",p->stu_name);
        fscanf(fp,"%s",p->stu_tel);
        for(int i=0;i<10;i++){
            fscanf(fp,"%s",p->stu_bor_book[i]);
        }
        int len=strlen(p->stu_passw);			//密码解密
        for(int i=0;i<len;i++){
            p->stu_passw[i]=p->stu_passw[i]-(i%4+1);
        }
        len=strlen(p->stu_find_passw);			//密保密码解密
        for(int i=0;i<len;i++){
            p->stu_find_passw[i]=p->stu_find_passw[i]-(i%4+1);
        }
        if(h==NULL)
            h=p;
        else
            t->next=p;
        t=p;
    }
    fclose(fp);
    return h;
}
Manager *Manager_load(void)
{
    FILE *fp;
    Manager *h=NULL,*t=h,*p;
    if((fp=fopen("Managernode.txt","r"))==NULL){
        printf("\t\t打开失败\n");
        exit(1);
    }
    getc(fp);
    if(feof(fp)){
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while(!feof(fp)){
        p=(Manager *)malloc(sizeof(Manager));
        p->next=NULL;
        fscanf(fp,"%s",p->man_name);
        fscanf(fp,"%s",p->man_acc);
        fscanf(fp,"%s",p->man_passw);
        int len=strlen(p->man_passw);			//密码解密
        for(int i=0;i<len;i++){
            p->man_passw[i]=p->man_passw[i]-(i%4+1);

        }
        if(h==NULL)
            h=p;
        else
            t->next=p;
        t=p;
    }
    fclose(fp);
    return h;
}

/*保存学生链表至文件*/
void Save_Student(void)
{
    FILE *fp;
    Student *t=Student_head->next;
    if(!t)
        return;
    if((fp=fopen("Studentnode.txt","w+"))==NULL){
        printf("\t\t打开失败\n");
        exit(1);
    }
    while(t->next){
        int len=strlen(t->stu_passw);			//密码加密
        for(int i=0;i<len;i++){
            t->stu_passw[i]=t->stu_passw[i]+(i%4+1);
        }
        len=strlen(t->stu_find_passw);			//密保密码加密
        for(int i=0;i<len;i++){
            t->stu_find_passw[i]=t->stu_find_passw[i]+(i%4+1);
        }
        fprintf(fp,"%s ",t->stu_passw);
        fprintf(fp,"%s ",t->stu_find_question);
        fprintf(fp,"%s ",t->stu_find_passw);
        fprintf(fp,"%s ",t->stu_num);
        fprintf(fp,"%s ",t->stu_name);
        fprintf(fp,"%s ",t->stu_tel);
        for(int i=0;i<9;i++){
            fprintf(fp,"%s ",t->stu_bor_book[i]);
        }
        fprintf(fp,"%s\n",t->stu_bor_book[9]);
        t=t->next;
    }

    int len=strlen(t->stu_passw);			//密码加密
    for(int i=0;i<len;i++){
        t->stu_passw[i]=t->stu_passw[i]+(i%4+1);
    }
    len=strlen(t->stu_find_passw);			//密保密码加密
    for(int i=0;i<len;i++){
        t->stu_find_passw[i]=t->stu_find_passw[i]+(i%4+1);
    }
    fprintf(fp,"%s ",t->stu_passw);
    fprintf(fp,"%s ",t->stu_find_question);
    fprintf(fp,"%s ",t->stu_find_passw);
    fprintf(fp,"%s ",t->stu_num);
    fprintf(fp,"%s ",t->stu_name);
    fprintf(fp,"%s ",t->stu_tel);
    for(int i=0;i<9;i++){
        fprintf(fp,"%s ",t->stu_bor_book[i]);
    }
    fprintf(fp,"%s",t->stu_bor_book[9]);
    fclose(fp);

}
/*保存管理员链表至文件*/
void Save_Manger(void)
{
    FILE *fp;
    Manager *t=Manager_head->next;
    if(!t)
        return;
    if((fp=fopen("Managernode.txt","w+"))==NULL){
        printf("\t\t打开失败\n");
        exit(1);
    }
    while(t->next){
        int len=strlen(t->man_passw);			//密码加密
        for(int i=0;i<len;i++){
            t->man_passw[i]=t->man_passw[i]+(i%4+1);
        }
        fprintf(fp,"%s ",t->man_name);
        fprintf(fp,"%s ",t->man_acc);
        fprintf(fp,"%s\n",t->man_passw);
        t=t->next;
    }
    int len=strlen(t->man_passw);			//密码加密
    for(int i=0;i<len;i++){
        t->man_passw[i]=t->man_passw[i]+(i%4+1);
    }
    fprintf(fp,"%s ",t->man_name);
    fprintf(fp,"%s ",t->man_acc);
    fprintf(fp,"%s",t->man_passw);
    fclose(fp);
}
/*所有信息保存至文件*/
void Massage_Save(void)
{
    store_books();
    Save_Student();
    Save_Manger();
}

void Manager_Look_Stu(void)
{
    Student *t=Student_head->next;
    printf("\t\t正在打印学生名单···\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\t抱歉，暂无学生\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    printf("\n\n     *************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-15s%-12s%-10s\n\n",
           "姓名","学号","电话","密码","借书数量");
    while(t)
    {
        int n=0;
        for(int i=0;i<10;i++){
            if(strcmp(t->stu_bor_book[i],"0")!=0)
                n++;
        }
        printf("      %-10s%-12s%-15s%-12s%-10d\n",
               t->stu_name,t->stu_num,t->stu_tel,t->stu_passw,n);
        t=t->next;
    }
    printf("\n     *****************************************");
    printf("****************************\n\n\n");
    printf("\t\t按任意键退出");
    getch();

}

void Stu_Borrow(Student *Stu_num)
{
    int n=0;
    Book *t;
    char numb[10];
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0)
            n++;
    }
    printf("\n\t\t欢迎进入借书系统\n");
    printf("\n\t\t加载中···\n");
    Sleep(1000);
    if(n==10){
        printf("\t\t您好，您已借书10本，已到最大借书限额，");
        printf("\t\t请先归还已借书籍\n\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    printf("\t\t您已借书籍%d本，还可借%d本\n",n,10-n);
    printf("\t\t书单如下\n");
    Manager_Print_Book();
    printf("\n\t\t请选择你想借书的编号：");
    gets(numb);
    t=Book_exit(numb);
    printf("\t\t正在办理···\n");
    Sleep(1000);
    if(!t){
        printf("\t\t抱歉，无此书，借书失败\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    if(t->copies==0){
        printf("\t\t抱歉，库存不足，借书失败\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    if(Ifborrow(Stu_num,numb)){
        printf("\t\t抱歉，您已借过此书，请勿重复借书\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")==0){
            Stu_num->stu_bor_book[i][0]='\0';
            strcat(Stu_num->stu_bor_book[i],numb);
            t->copies--;
            break;
        }
    }
    printf("\t\t···\n");
    printf("\t\t恭喜您办理成功！\n");
    printf("\t\t按任意键退出");
    getch();
    return;
}

/*查询学生是否借过此书*/
int Ifborrow(Student *Stu_num,char *Book_num)
{
    int tem=0;
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],Book_num)==0){
            tem=1;
            break;
        }
    }
    return tem;
}

void Stu_Back(Student *Stu_num)
{
    char book_num[15];
    int tem=0;
    printf("\n\t\t欢迎进入还书系统\n");
    printf("\n\t\t加载中···\n");
    Sleep(500);
    printf("\n\t\t正在查找已借书籍···\n");
    Sleep(500);
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            tem=1;
            break;
        }
    }
    if(tem==0){
        printf("\n\t\t暂无借书记录\n");
        printf("\n\t\t按任意键退出");
        getch();
        return;
    }
    Print_Borbook(Stu_num);
    printf("\n\t\t请输入书的编号进行归还：");
    gets(book_num);
    tem=0;
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],book_num)==0){
            tem=1;
            break;
        }
    }
    if(!tem){
        printf("\t\t输入错误，您未借过此书\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }

    Sleep(500);
    printf("\t\t正在归还···\n");
    Sleep(500);
    Bake_Book(Stu_num,book_num);
    printf("\t\t归还成功！\n");
    printf("\t\t按任意键退出");
    getch();
}

void Print_Borbook(Student *Stu_num)
{

    int tem=0;
    Book *t;
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s-10s\n\n",
           "编号","书名","作者","年份");
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            t=find_book_by_id(Stu_num->stu_bor_book[i]);
            printf("\t %-8u%-12s%-12s%-18u\n",
                   t->id,t->title,t->authors,t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
}

/*还书具体操作*/
void Bake_Book(Student *Stu_num,char *Book_num)
{
    Book *t;
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],Book_num)==0){
            Stu_num->stu_bor_book[i][0]='0';
            Stu_num->stu_bor_book[i][1]='\0';
            break;
        }
    }
    t=find_book_by_id(Book_num);
    t->copies++;
}

void Find_Theborrow(Student *Stu_num)
{
    int tem=0;
    Book *t;
    printf("\t\t查找中···\n");
    Sleep(1000);
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            tem=1;
            break;
        }
    }
    if(tem==0){
        printf("\t\t暂无借书记录\n");
        printf("\t\t按任意键退出");
        getch();
        return;
    }
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s%-10s\n\n",
           "编号","书名","作者","出版社","价格");
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            t=find_book_by_id(Stu_num->stu_bor_book[i]);
            printf("\t %-8u%-12s%-12s%-18u\n",
                   t->id,t->title,t->authors,t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
    printf("\n\t\t按任意键退出");
    getch();
}