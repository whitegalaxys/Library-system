//
// Created by Administrator on 2021/3/20.
//

#ifndef LIBRARY_SYSTEM_MENU_H
#define LIBRARY_SYSTEM_MENU_H

//Select user login type menu
void loadmenu();
//Administrator login menu
void admin_system_land();
//User login menu
void user_system_land();
//Administrator manage user menu
void admin_manage_User();
//Print information of select user login type menu
void loadmenu_display();
//Print information of admin menu homepage
void admin_system_display();
//Print information of user menu homepage
void user_system_display();
//Print information of administrator login menu
void admin_system_land_display();
//Print information of user login menu
void user_system_land_display();
//Print information of administrator manage user menu
void admin_manage_User_display();
//Print information of find book information menu
void find_book_display();
//Print information of find books by title
void find_book_by_title_display();
//Print information of find books by author
void find_book_by_author_display();
//Print information of find books by year
void find_book_by_year_display();

#endif //LIBRARY_SYSTEM_MENU_H