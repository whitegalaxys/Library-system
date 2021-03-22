//
// Created by Administrator on 2021/3/22.
//
#include "account.h"
#include "menu.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

int main(void)
{
    Book_head=(Book *)malloc(sizeof(Book));
    Student_head=(Student *)malloc(sizeof(Student));
    Manager_head=(Manager *)malloc(sizeof(Manager));

    Book_head->next= load_books();
    Student_head->next=Student_load();
    Manager_head->next=Manager_load();
    loadmenu();
    system("PAUSE");
    return 0;
}
