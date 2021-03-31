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
    char Admin_num[20];
    Admin *t;
    printf("\n\t\taccount number:");
    gets(Admin_num);
    t=find_admin_by_id(Admin_num);
    if(!t){
        printf("\t\tSorry, the account does not exist\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tpassword:");
    if(password_input_times(t->admin_passw)==0){
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
    admin_system(t);

}

Admin *find_admin_by_id(char *Admin_num)
{

    Admin *t=Admin_head->next;
    while(t){
        if(strcmp(Admin_num,t->admin_acc)==0)
            break;
        t=t->next;
    }
    return t;
}

void user_land()
{
    char enter_num[50];
    int l=1;
    User *enter_user;
    while(l!=6){
        printf("\n\t\tPlease enter your account number:");
        gets(enter_num);
        l=strlen(enter_num);
        if(l!=6)
            printf("\t\tThe account number is wrong, please enter an account number of the correct length\n");
    }
    enter_num[6]='\0';
    enter_user=find_user_by_id(enter_num);
    if(enter_user==NULL){
        printf("\n\t\tSorry, no such account");
        Sleep(500);
        printf("\n\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tPlease enter your password:");
    if(password_input_times(enter_user->user_passw)==0){
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
    user_system(enter_user);
}

int Password_Text(char *Password)
{
    char password_tem[20];
    int tem=0;
    int n=0;
    while(n!=3){
        password_length_control(password_tem);
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
    char bh[10];
    User *t, *b;
    User *new=(User *)malloc(sizeof(User));
    new->next=NULL;
    for(int i=0;i<10;i++){
        new->user_bor_book[i][0]='0';
        new->user_bor_book[i][1]='\0';
    }
    printf("\n\t\tWelcome to the registration system!\n");
    Sleep(500);
    printf("\t\tloading...\n");
    Sleep(500);
    printf("\t\tPlease enter the following information\n");
    printf("\t\tUser ID(6 digits):");
    gets(bh);
    if(strlen(bh)!=6){
        printf("The entered user ID digits are incorrect\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    b=find_user_by_id(bh);
    if(b){
        printf("\t\tSorry, this account has been registered, please use another account\n");
        printf("\t\tPress any key to exit");
        free(new);
        getch();
        return;
    }
    strcpy(new->user_num,bh);
    printf("\t\tName:");
    scanf("%s",new->user_name);
    printf("\t\ttelephone number:");
    scanf("%s",new->user_tel);
    printf("\t\tpassword(6~10 digits):");
    password_length_control(new->user_passw);
    printf("\n\t\tEnter the password again:");
    if(Password_Text(new->user_passw)==0){
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
    scanf("%s[^\n]",new->user_find_question);
    printf("\t\tSecret question password:");
    password_length_control(new->user_find_passw);
    printf("\n\t\tEnter the secret question password again:");
    if(Password_Text(new->user_find_passw)==0){
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
    printf("\t\tYour account number is:%s\n",new->user_num);
    printf("\t\tPlease remember your account password!\n");
    while(getchar()!='\n');
    t=User_head;
    while(t->next){
        t=t->next;
    }
    t->next=new;
    printf("Created successfully, press any key to return");
    getch();
    system("cls");
    user_system_land();
}

void deluser()
{
    char bh[20];
    Book *a;
    User *head=User_head;
    User *t=User_head->next;
    printf("\t\tPrinting the list of Users...\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\tSorry, there are no Users\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\n\n     *************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-15s%-12s%-10s\n\n",
           "Name","User ID","telephone number","password","Number of books borrowed");
    while(t)
    {
        int n=0;
        for(int i=0;i<10;i++){
            if(strcmp(t->user_bor_book[i],"0")!=0)
                n++;
        }
        printf("      %-10s%-12s%-15s%-12s%-10d\n",
               t->user_name,t->user_num,t->user_tel,t->user_passw,n);
        t=t->next;
    }
    printf("\n     *****************************************");
    printf("****************************\n\n\n");

    printf("\t\tPlease enter the account of the User you want to delete:");
    gets(bh);
    t=find_user_by_id(bh);
    if(!t){
        printf("\t\tSorry, no such User\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    Sleep(500);
    printf("\t\tdeleting...\n");
    Sleep(500);
    printf("\t\tsuccessfully deleted!\n");
    for(int i=0;i<10;i++){
        if(strcmp(t->user_bor_book[i],"0")!=0){
            a=find_book_by_id(t->user_bor_book[i]);
            a->copies_now+=1;
        }
    }
    t=User_head->next;
    while(t){
        if(strcmp(bh,t->user_num)==0){
            head->next=t->next;
            free(t);
            break;
        }
        head=t;
        t=t->next;
    }
    printf("\nsuccessfully deleted \nPress any key to return to the previous level\n");
    getch();
    admin_manage_User();
}

void password_find()
{
    User *find_tem;
    char num_tem[50];
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
    find_tem=find_user_by_id(num_tem);
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
    printf("\t\t%s,Hello!\n",find_tem->user_name);
    Sleep(300);
    printf("\t\tThe security questions you set are: %s\n",find_tem->user_find_question);
    Sleep(300);
    printf("\t\tPlease enter your secret question password:");
    if(password_input_times(find_tem->user_find_passw)==0){
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
    printf("\t\t%s Hello, your password is: %s",find_tem->user_name,find_tem->user_passw);
    printf("\n\t\tPlease remember your password\n");
    printf("\t\tPress any key to exit");
    getch();
    system("cls");
    user_system_land();
}

void password_length_control(char *Password)
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

int password_input_times(char *Password)
{
    char password_tem[20];
    int tem=0;
    int n=0;
    while(n!=3){
        password_length_control(password_tem);
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

User *find_user_by_id(char *User_num)
{
    User *t=User_head->next;
    while(t){
        if(strcmp(t->user_num,User_num)==0)
            break;
        t=t->next;
    }
    return t;
}

User *load_user(void)
{
    FILE *fp;
    User *h=NULL,*t=h,*p;
    if((fp=fopen("User.txt","r"))==NULL){
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
        p=(User *)malloc(sizeof(User));
        p->next=NULL;
        fscanf(fp,"%s",p->user_passw);
        fscanf(fp,"%s",p->user_find_question);
        fscanf(fp,"%s",p->user_find_passw);
        fscanf(fp,"%s",p->user_num);
        fscanf(fp,"%s",p->user_name);
        fscanf(fp,"%s",p->user_tel);
        for(int i=0;i<10;i++){
            fscanf(fp,"%s",p->user_bor_book[i]);
        }
        //Password information decryption
        int len=strlen(p->user_passw);
        for(int i=0;i<len;i++){
            p->user_passw[i]=p->user_passw[i]-(i%4+1);
        }
        len=strlen(p->user_find_passw);
        for(int i=0;i<len;i++){
            p->user_find_passw[i]=p->user_find_passw[i]-(i%4+1);
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

Admin *load_admin(void)
{
    FILE *fp;
    Admin *h=NULL,*t=h,*p;
    if((fp=fopen("Admin.txt","r"))==NULL){
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
        p=(Admin *)malloc(sizeof(Admin));
        p->next=NULL;
        fscanf(fp,"%s",p->admin_name);
        fscanf(fp,"%s",p->admin_acc);
        fscanf(fp,"%s",p->admin_passw);
        //Password information decryption
        int len=strlen(p->admin_passw);
        for(int i=0;i<len;i++){
            p->admin_passw[i]=p->admin_passw[i]-(i%4+1);

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


void user_save(void)
{
    FILE *fp;
    User *t=User_head->next;
    if(!t)
        return;
    if((fp=fopen("User.txt","w+"))==NULL){
        printf("\t\tOpen failed\n");
        exit(1);
    }
    while(t->next){
        //Password information encryption
        int len=strlen(t->user_passw);
        for(int i=0;i<len;i++){
            t->user_passw[i]=t->user_passw[i]+(i%4+1);
        }
        len=strlen(t->user_find_passw);
        for(int i=0;i<len;i++){
            t->user_find_passw[i]=t->user_find_passw[i]+(i%4+1);
        }
        fprintf(fp,"%s ",t->user_passw);
        fprintf(fp,"%s ",t->user_find_question);
        fprintf(fp,"%s ",t->user_find_passw);
        fprintf(fp,"%s ",t->user_num);
        fprintf(fp,"%s ",t->user_name);
        fprintf(fp,"%s ",t->user_tel);
        for(int i=0;i<9;i++){
            fprintf(fp,"%s ",t->user_bor_book[i]);
        }
        fprintf(fp,"%s\n",t->user_bor_book[9]);
        t=t->next;
    }
//Password information encryption
    int len=strlen(t->user_passw);
    for(int i=0;i<len;i++){
        t->user_passw[i]=t->user_passw[i]+(i%4+1);
    }
    len=strlen(t->user_find_passw);
    for(int i=0;i<len;i++){
        t->user_find_passw[i]=t->user_find_passw[i]+(i%4+1);
    }
    fprintf(fp,"%s ",t->user_passw);
    fprintf(fp,"%s ",t->user_find_question);
    fprintf(fp,"%s ",t->user_find_passw);
    fprintf(fp,"%s ",t->user_num);
    fprintf(fp,"%s ",t->user_name);
    fprintf(fp,"%s ",t->user_tel);
    for(int i=0;i<9;i++){
        fprintf(fp,"%s ",t->user_bor_book[i]);
    }
    fprintf(fp,"%s",t->user_bor_book[9]);
    fclose(fp);

}

void admin_save(void)
{
    FILE *fp;
    Admin *t=Admin_head->next;
    if(!t)
        return;
    if((fp=fopen("Admin.txt","w+"))==NULL){
        printf("\t\tOpen failed\n");
        exit(1);
    }
    while(t->next){
        //Password information encryption
        int len=strlen(t->admin_passw);
        for(int i=0;i<len;i++){
            t->admin_passw[i]=t->admin_passw[i]+(i%4+1);
        }
        fprintf(fp,"%s ",t->admin_name);
        fprintf(fp,"%s ",t->admin_acc);
        fprintf(fp,"%s\n",t->admin_passw);
        t=t->next;
    }
    //Password information encryption
    int len=strlen(t->admin_passw);
    for(int i=0;i<len;i++){
        t->admin_passw[i]=t->admin_passw[i]+(i%4+1);
    }
    fprintf(fp,"%s ",t->admin_name);
    fprintf(fp,"%s ",t->admin_acc);
    fprintf(fp,"%s",t->admin_passw);
    fclose(fp);
}

void all_save(void)
{
    store_books();
    user_save();
    admin_save();
}

void view_users(void)
{
    User *t=User_head->next;
    printf("\t\tPrinting the list of Users...\n");
    Sleep(1000);
    if(!t){
        printf("\n\t\tSorry, there are no Users\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\n\n     ***************************************************");
    printf("********************************\n\n");
    printf("      %-10s%-12s%-20s%-12s%-10s\n\n",
           "Name","User ID","telephone number","password","Number of books borrowed");
    while(t)
    {
        int n=0;
        for(int i=0;i<10;i++){
            if(strcmp(t->user_bor_book[i],"0")!=0)
                n++;
        }
        printf("      %-10s%-12s%-20s%-12s%-10d\n",
               t->user_name,t->user_num,t->user_tel,t->user_passw,n);
        t=t->next;
    }
    printf("\n     *******************************************************");
    printf("****************************\n\n\n");
    printf("\t\tPress any key to exit");
    getch();

}

void user_book_borrow(User *User_num)
{
    int n=0;
    Book *t;
    char numa[10];
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")!=0)
            n++;
    }
    printf("\n\t\tWelcome to the library system\n");
    printf("\n\t\tLoading...\n");
    Sleep(1000);
    if(n==10){
        printf("\t\tHello, you have borrowed 10 books and the maximum borrowing limit has been reached.\n");
        printf("\t\tPlease return the borrowed books first\n\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tYou have borrowed %d books and you can borrow %d books\n",n,10-n);
    Sleep(2000);
    printf("\t\tThe book list is as follows\n");
    admin_print_book();
    printf("\n\t\tPlease select the ID of the book you want to borrow:");
    gets(numa);
    t=find_book_by_id(numa);
    printf("\t\tProcessing...\n");
    Sleep(1000);
    if(!t){
        printf("\t\tSorry, there is no such book, the borrowing failed\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    if(t->copies_now==0){
        printf("\t\tSorry, the inventory is insufficient and the borrowing failed\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    if(whether_lent(User_num,numa)){
        printf("\t\tSorry, you have already borrowed this book, please do not borrow again\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")==0){
            User_num->user_bor_book[i][0]='\0';
            strcat(User_num->user_bor_book[i],numa);
            t->copies_now--;
            break;
        }
    }
    printf("\t\t...\n");
    printf("\t\tCongratulations on your success!\n");
    printf("\t\tPress any key to exit");
    getch();
}


int whether_lent(User *User_num,char *Book_num)
{
    int tem=0;
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],Book_num)==0){
            tem=1;
            break;
        }
    }
    return tem;
}

void user_book_return(User *User_num)
{
    char book_num[10];
    int tem=0;
    printf("\n\t\tWelcome to the book return system\n");
    printf("\n\t\tLoading...\n");
    Sleep(500);
    printf("\n\t\tLooking for borrowed books...\n");
    Sleep(500);
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")!=0){
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
    print_borrow_booklist(User_num);
    printf("\n\t\tPlease enter the book number to return:");
    gets(book_num);
    tem=0;
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],book_num)==0){
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
    user_return_book_case(User_num,book_num);
    printf("\t\tSuccessfully returned!\n");
    printf("\t\tPress any key to exit");
    getch();
}

void print_borrow_booklist(User *User_num)
{
    Book *t;
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-20s%-20s%-18s\n\n",
           "ID","title","author","year");
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")!=0){
            t=find_book_by_id(User_num->user_bor_book[i]);
            printf("\t %-8s%-20s%-20s%-18u\n",
                   t->id,t->title,t->authors,t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
}


void user_return_book_case(User *User_num,char *Book_num)
{
    Book *t;
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],Book_num)==0){
            User_num->user_bor_book[i][0]='0';
            User_num->user_bor_book[i][1]='\0';
            break;
        }
    }
    t=find_book_by_id(Book_num);
    t->copies_now++;
}

void user_borrow_record(User *User_num)
{
    int tem=0;
    Book *t;
    printf("\t\tSearching...\n");
    Sleep(1000);
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")!=0){
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
    printf("\t %-8s%-20s%-20s%-18s\n\n",
           "ID","title","author","year");
    for(int i=0;i<10;i++){
        if(strcmp(User_num->user_bor_book[i],"0")!=0){
            t=find_book_by_id(User_num->user_bor_book[i]);
            printf("\t %-8s%-20s%-20s%-18u\n",
                   t->id,t->title,t->authors,t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();
}

void admin_change_password(Admin *Admin_num)
{
    char password_tem[20];
    printf("\t\tLoading...\n");
    Sleep(500);
    printf("\t\tPlease enter the original password:");
    if(password_input_times(Admin_num->admin_passw)==0){
        printf("\n\t\tIf you have entered the wrong password three times, you will exit the password modification system...\n");
        Sleep(1500);
        return;
    }
    printf("\n\t\tVerifying...\n");
    Sleep(1000);
    printf("\t\tThe verification is successful!\n");
    Sleep(500);
    printf("\t\tPlease enter a new password (6~10 digits):");
    password_length_control(password_tem);
    printf("\n\t\tPlease enter the new password again:");
    if(Password_Text(password_tem)==0){
        printf("\t\tIf you have entered the wrong password three times, you will exit the password modification system...\n");
        Sleep(1500);
        return;
    }
    Admin_num->admin_passw[0]='\0';
    strcat(Admin_num->admin_passw,password_tem);
    Sleep(500);
    printf("\n\t\tPlease wait, it is being revised...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\tCongratulations! Successfully modified!\n");
    printf("\t\tPress any key to exit");
    getch();
}

void user_change_password(User *User_num)
{
    char password_tem[20];
    printf("\t\tLoading...\n");
    Sleep(500);
    printf("\t\tPlease enter the original password:");
    if(password_input_times(User_num->user_passw)==0){
        printf("\n\t\tIf you have entered the wrong password three times, you will exit the password modification system...\n");
        Sleep(1500);
        return;
    }
    printf("\n\t\tVerifying...\n");
    Sleep(1000);
    printf("\t\tThe verification is successful!\n");
    Sleep(500);
    printf("\t\tPlease enter a new password (6~10 digits):");
    password_length_control(password_tem);
    printf("\n\t\tPlease enter the new password again:");
    if(Password_Text(password_tem)==0){
        printf("\t\tIf you have entered the wrong password three times, you will exit the password modification system...\n");
        Sleep(3000);
        return;
    }
    User_num->user_passw[0]='\0';
    strcat(User_num->user_passw,password_tem);
    Sleep(500);
    printf("\n\t\tPlease wait, it is being revised...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\t...\n");
    Sleep(1000);
    printf("\t\tCongratulations! Successfully modified!\n");
    printf("\t\tPress any key to exit");
    getch();
}