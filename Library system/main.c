//
// Created by Administrator on 2021/3/22.
//
#include "account.h"
#include "menu.h"
#include "book_management.h"
#include <stdlib.h>


int main(void)
{
    Book_head=(Book *)malloc(sizeof(Book));
    User_head=(User *)malloc(sizeof(User));
    Admin_head=(Admin *)malloc(sizeof(Admin));

    Book_head->next= load_books();
    User_head->next=load_user();
    Admin_head->next=load_admin();
    loadmenu();
    system("PAUSE");
    return 0;
}
