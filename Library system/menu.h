//
// Created by Administrator on 2021/3/20.
//

#ifndef LIBRARY_SYSTEM_MENU_H
#define LIBRARY_SYSTEM_MENU_H

#endif //LIBRARY_SYSTEM_MENU_H

#define S 100

struct admin_land_info//管理员登录信息
{
    int username;
    char password[20];
};

int admin_account_num();

int match();

void loadmenu();

void loadmenu_display();

void admin_land();

void user_land();
