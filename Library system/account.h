//
// Created by Administrator on 2021/3/21.
//

#ifndef CLIONPROJECTS_ACCOUNT_H
#define CLIONPROJECTS_ACCOUNT_H




#define S 100

typedef struct stu{
    char stu_passw[15];				//学生密码
    char stu_find_question[30];		//密保问题
    char stu_find_passw[15];		//密保问题密码
    char stu_num[10];				//学生学号
    char stu_name[20];				//学生姓名
    char stu_tel[15];				//学生电话
    char stu_bor_book[10][20];		//所借书号
    struct stu *next;				//下位学生
}Student;

typedef struct manager{
    char man_name[15];				//管理员姓名
    char man_acc[10];				//管理员账号
    char man_passw[15];				//管理员密码
    struct manager *next;			//下个管理员
}Manager;

Student *Student_head;
Manager *Manager_head;


Manager *Manager_check(char *Manager_num);

struct admin_land_info//管理员登录信息
{
    int username;
    char password[20];
};

struct passwordchange//修改密码
{
    int username1;
    char password[20];
};

struct delete_user//删除用户账号
{
    int username2;
    char password2[20];
    struct delete_user *next;
};

int match();

void adduser();
void deluser();

void admin_land();
void user_land();

void password_find();

void Password_Input(char *Password);
int Password_Text_Find(char *Password);
Student *Find_Num(char *Stu_num);
Student *Find_Stu(char *Stu_Stuty);
Student *Student_load(void);
//将学生文件中的信息加载至学生链表
Manager *Manager_load(void);
//将管理员文件的信息加载至管理员链表
void Save_Student();
void Save_Manger();
void Manager_Look_Stu(void);
void Stu_Borrow(Student *Stu_num);
int Ifborrow(Student *Stu_num,char *Book_num);
void Stu_Back(Student *Stu_num);
void Print_Borbook(Student *Stu_num);
void Bake_Book(Student *Stu_num,char *Book_num);
void Find_Theborrow(Student *Stu_num);
void Manager_Change_Password(Manager *Man_num);
void Change_Stupassword(Student *Stu_num);

#endif //CLIONPROJECTS_ACCOUNT_H


