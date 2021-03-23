//
// Created by Administrator on 2021/3/21.
//

#ifndef CLIONPROJECTS_ACCOUNT_H
#define CLIONPROJECTS_ACCOUNT_H



#define S 100

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

int admin_account_num();
int user_account_num();

int match();

void adduser();
void deluser();

void admin_land();
void user_land();

void password_change();

#endif //CLIONPROJECTS_ACCOUNT_H


