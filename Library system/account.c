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

void admin_land()
{
    system("cls");
    char Manager_num[20];
    Manager *t;
    printf("\n\t\taccount number:");
    gets(Manager_num);
    t=Manager_check(Manager_num);
    if(!t){
        printf("\t\tSorry, the account does not exist\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tpassword:");
    if(Password_Text_Find(t->man_passw)==0){
        printf("\n\t\tYou have entered the wrong password three times, you will be logged out of the system...\n");
        Sleep(5000);
        return;
    }
    Sleep(500);
    printf("\n\t\tlogging in...\n");
    Sleep(500);
    printf("\t\tlogin successful...\n");
    Sleep(500);
    printf("\t\tloading...\n");
    Sleep(1000);
    admin_system();

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
        printf("\n\t\tPlease enter your account number:");
        gets(enter_num);
        l=strlen(enter_num);
        if(l!=6)
            printf("\t\tThe account number is wrong, please enter an account number of the correct length\n");
    }
    enter_num[6]='\0';
    enter_stu=Find_Num(enter_num);
    if(enter_stu==NULL){
        printf("\n\t\tSorry, no such account");
        Sleep(500);
        printf("\n\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tPlease enter your password:");
    if(Password_Text_Find(enter_stu->stu_passw)==0){
        printf("\n\t\tYou have entered incorrectly 3 times in a row, you will be logged out of the system...");
        Sleep(2000);
        return;
    }
    Sleep(500);
    printf("\n\t\tLogging in");
    Sleep(500);
    printf("\n\t\t...\n");
    Sleep(500);
    printf("\n\t\tlogin successful! Press any key to continue\n");
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
                printf("\n\t\tThe two input passwords are inconsistent, please re-enter, you still have %d chances to input:",3-n);
            }
            else if(n==3)
                printf("\n\t\tinput error\n");
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
    printf("\n\t\tWelcome to the registration system!\n");
    Sleep(500);
    printf("\t\tloading...\n");
    Sleep(500);
    printf("\t\tPlease enter the following information\n");
    printf("\t\tstudent ID:");
    scanf("%s",new->stu_num);
    printf("\t\tName:");
    scanf("%s",new->stu_name);
    printf("\t\ttelephone number:");
    scanf("%s",new->stu_tel);
    printf("\t\tpassword:");
    Password_Input(new->stu_passw);
    printf("\n\t\tEnter the password again:");
    if(Password_Text(new->stu_passw)==0){
        printf("\n\t\tYou have entered incorrectly 3 times in a row, you will be logged out of the registration system...");
        Sleep(5000);
        free(new);
        return;
    }
    printf("\n\n\t\tSecret security question is used to retrieve the password\n");
    printf("\t\tSuch as:\n");
    printf("\t\t    When is my mother's birthday?\n");
    printf("\t\t    When is my father's birthday?\n");
    printf("\t\t    When is my birthday?\n");
    printf("\n\t\tSecurity Question:");
    scanf("%s",new->stu_find_question);
    printf("\t\tSecret question password:");
    Password_Input(new->stu_find_passw);
    printf("\n\t\tEnter the secret question password again:");
    if(Password_Text(new->stu_find_passw)==0){
        printf("\n\t\tYou have entered incorrectly 3 times in a row, you will be logged out of the registration system...");
        Sleep(5000);
        free(new);
        return;
    }
    Sleep(500);
    printf("\n\t\tRegistering...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\tregistration success!\n");
    printf("\t\tYour account number is:%s\n",new->stu_num);
    printf("\t\tPlease remember your account password!\n");
    while(getchar()!='\n');
    t=Student_head;
    while(t->next){
        t=t->next;
    }
    t->next=new;
    printf("Created successfully, press any key to return");
    getch();
    system("cls");
    user_system();
}

void deluser()
{
    char bh[20];
    BookArray *a;
    Student *head=Student_head;
    Student *t=Student_head->next;
    printf("\t\tPrinting the list of students...\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\tSorry, there are no students\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\n\n     *************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-15s%-12s%-10s\n\n",
           "Name","student ID","telephone number","password","Number of books borrowed");
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

    printf("\t\tPlease enter the account of the student you want to delete:");
    gets(bh);
    t=Find_Stu(bh);
    if(!t){
        printf("\t\tSorry, no such student\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    Sleep(500);
    printf("\t\tdeleting...\n");
    Sleep(500);
    printf("\t\tsuccessfully deleted!\n");
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
    printf("\nsuccessfully deleted \nPress any key to return to the previous level\n");
    getch();
    Manager_Manager_Stu();
}

void password_find()
{
    Student *find_tem;
    char num_tem[50];
    char password_find[20];
    printf("\t\tWelcome to the password recovery system\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    int l=1;
    while(l!=6){
        printf("\t\tplease enter account:");
        gets(num_tem);
        l=strlen(num_tem);
        if(l!=6)
            printf("\t\tThe account number is wrong, please enter an account number of the correct length\n");
    }
    num_tem[6]='\0';
    find_tem=Find_Num(num_tem);
    printf("\t\tThe account number you entered:");
    puts(num_tem);
    Sleep(500);
    printf("\t\tLooking for you\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    if(find_tem==NULL){
        printf("\t\tSorry, no such account, will log out of the registration system\n");
        Sleep(1000);
        printf("\t\t...\n");
        Sleep(3000);
        return;
    }
    printf("\t\t%s，Hello!\n",find_tem->stu_name);
    Sleep(300);
    printf("\t\tThe security questions you set are: %s\n",find_tem->stu_find_question);
    Sleep(300);
    printf("\t\tPlease enter your secret question password:");
    if(Password_Text_Find(find_tem->stu_find_passw)==0){
        printf("\n\t\tYou have entered incorrectly 3 times in a row, you will exit the password retrieval system...\n");
        Sleep(1500);
        return;
    }
    Sleep(500);
    printf("\n\t\tLooking for\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    printf("\t\t%s Hello, your password is: %s",find_tem->stu_name,find_tem->stu_passw);
    printf("\n\t\tPlease remember your password\n");
    printf("\t\tPress any key to exit");
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
            printf("\n\t\tInput error, please input the correct length of the password:");
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
            printf("\n\t\tInput error, please re-enter, you still have %d chances:",3-n);
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
        printf("\t\tOpen failed\n");
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
        printf("\t\tOpen failed\n");
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
        printf("\t\tOpen failed\n");
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
        printf("\t\tOpen failed\n");
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
    printf("\t\tPrinting the list of students...\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\tSorry, there are no students\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\n\n     *************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-15s%-12s%-10s\n\n",
           "Name","student ID","telephone number","password","Number of books borrowed");
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
    printf("\t\tPress any key to exit");
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
    printf("\n\t\tWelcome to the library system\n");
    printf("\n\t\tLoading...\n");
    Sleep(1000);
    if(n==10){
        printf("\t\tHello, you have borrowed 10 books and the maximum borrowing limit has been reached.");
        printf("\t\tPlease return the borrowed books first\n\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tYou have borrowed %d books and you can borrow %d books\n",n,10-n);
    printf("\t\tThe book list is as follows\n");
    Manager_Print_Book();
    printf("\n\t\tPlease select the number of the book you want to borrow:");
    gets(numb);
    t=Book_exit(numb);
    printf("\t\tProcessing...\n");
    Sleep(1000);
    if(!t){
        printf("\t\tSorry, there is no such book, the borrowing failed\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    if(t->copies==0){
        printf("\t\tSorry, the inventory is insufficient and the borrowing failed\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    if(Ifborrow(Stu_num,numb)){
        printf("\t\tSorry, you have already borrowed this book, please do not borrow again\n");
        printf("\t\tPress any key to exit");
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
    printf("\t\t...\n");
    printf("\t\tCongratulations on your success!\n");
    printf("\t\tPress any key to exit");
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
    printf("\n\t\tWelcome to the book return system\n");
    printf("\n\t\tLoading...\n");
    Sleep(500);
    printf("\n\t\tLooking for borrowed books...\n");
    Sleep(500);
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            tem=1;
            break;
        }
    }
    if(tem==0){
        printf("\n\t\tNo borrowing records\n");
        printf("\n\t\tPress any key to exit");
        getch();
        return;
    }
    Print_Borbook(Stu_num);
    printf("\n\t\tPlease enter the book number to return:");
    gets(book_num);
    tem=0;
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],book_num)==0){
            tem=1;
            break;
        }
    }
    if(!tem){
        printf("\t\tInput error, you have not borrowed this book\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }

    Sleep(500);
    printf("\t\tReturning...\n");
    Sleep(500);
    Bake_Book(Stu_num,book_num);
    printf("\t\tSuccessfully returned!\n");
    printf("\t\tPress any key to exit");
    getch();
}

void Print_Borbook(Student *Stu_num)
{

    int tem=0;
    Book *t;
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s-10s\n\n",
           "ID","title","author","year");
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
    printf("\t\tSearching...\n");
    Sleep(1000);
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            tem=1;
            break;
        }
    }
    if(tem==0){
        printf("\t\tNo borrowing records\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s\n\n",
           "ID","title","author","year");
    for(int i=0;i<10;i++){
        if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
            t=find_book_by_id(Stu_num->stu_bor_book[i]);
            printf("\t %-8u%-12s%-12s%-18u\n",
                   t->id,t->title,t->authors,t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();
}

void Manager_Change_Password(Manager *Man_num)
{
    char password_tem[20];
    printf("\t\t加载中···\n");
    Sleep(500);
    printf("\t\t请输入原密码：");
    if(Password_Text_Find(Man_num->man_passw)==0){
        printf("\n\t\t已经错误输入密码三次，将退出修改密码系统···\n");
        Sleep(1500);
        return;
    }
    printf("\n\t\t验证中···\n");
    Sleep(1000);
    printf("\t\t验证成功！\n");
    Sleep(500);
    printf("\t\t请输入新密码(6~10位)：");
    Password_Input(password_tem);
    printf("\n\t\t请再次输入新密码：");
    if(Password_Text(password_tem)==0){
        printf("\t\t已经错误输入密码三次，将退出修改密码系统···\n");
        Sleep(1500);
        return;
    }
    Man_num->man_passw[0]='\0';
    strcat(Man_num->man_passw,password_tem);
    Sleep(500);
    printf("\n\t\t请稍等，正在修改···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t恭喜！修改成功！\n");
    printf("\t\t按任意键退出");
    getch();
}

void Change_Stupassword(Student *Stu_num)
{
    char password_tem[20];
    printf("\t\t加载中···\n");
    Sleep(500);
    printf("\t\t请输入原密码：");
    if(Password_Text_Find(Stu_num->stu_passw)==0){
        printf("\n\t\t已经错误输入密码三次，将退出修改密码系统···\n");
        Sleep(1500);
        return;
    }
    printf("\n\t\t验证中···\n");
    Sleep(1000);
    printf("\t\t验证成功！\n");
    Sleep(500);
    printf("\t\t请输入新密码(6~10位)：");
    Password_Input(password_tem);
    printf("\n\t\t请再次输入新密码：");
    if(Password_Text(password_tem)==0){
        printf("\t\t已经错误输入密码三次，将退出修改密码系统···\n");
        Sleep(3000);
        return;
    }
    Stu_num->stu_passw[0]='\0';
    strcat(Stu_num->stu_passw,password_tem);
    Sleep(500);
    printf("\n\t\t请稍等，正在修改···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t恭喜！修改成功！\n");
    printf("\t\t按任意键退出");
    getch();
}