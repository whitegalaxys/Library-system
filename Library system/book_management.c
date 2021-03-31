#include "book_management.h"


int store_books()
{
    FILE *fp;
    Book *t=Book_head->next;
    if(!t)
        return -1;
    if((fp=fopen("Book.txt","w+"))==NULL){
        printf("\t\tOpen failed\n");
        exit(1);
    }
    while(t->next){
        fprintf(fp,"%s ",t->id);
        fprintf(fp,"%s ",t->title);
        fprintf(fp,"%s ",t->authors);
        fprintf(fp,"%d ",t->year);
        fprintf(fp,"%d ",t->copies);
        fprintf(fp,"%d\n",t->copies_now);
        t=t->next;
    }
    fprintf(fp,"%s ",t->id);
    fprintf(fp,"%s ",t->title);
    fprintf(fp,"%s ",t->authors);
    fprintf(fp,"%d ",t->year);
    fprintf(fp,"%d ",t->copies);
    fprintf(fp,"%d",t->copies_now);
    fclose(fp);
    return 0;
}

Book *load_books()
{
    FILE *fp;
    Book *h=NULL,*t=h,*p;
    if((fp=fopen("Book.txt","r"))==NULL){
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
        p=(Book *)malloc(sizeof(Book));
        p->next=NULL;
        fscanf(fp,"%s",p->id);
        fscanf(fp,"%s",p->title);
        fscanf(fp,"%s",p->authors);
        fscanf(fp,"%d",&p->year);
        fscanf(fp,"%d",&p->copies);
        fscanf(fp,"%d",&p->copies_now);
        if(h==NULL)
            h=p;
        else
            t->next=p;
        t=p;
    }
    fclose(fp);
    return h;
}

int add_book()
{
    printf("\t\tPlease enter the following information:\n");
    Book *new=(Book *)malloc(sizeof(Book));
    new->next=NULL;
    Book *t=Book_head;
    printf("\t\tID:");
    gets(&new->id);
    if(find_book_by_id(new->id)){
        free(new);
        printf("\t\tThe book has already been put on the shelves, please choose to increase inventory\n");
        printf("\t\tPress any key to exit");
        getch();
        return -1;
    }
    printf("\t\ttitle:");
    gets(new->title);

    printf("\t\tauthors:");
    gets(new->authors);
    printf("\t\tyear:");
    scanf("%d",&new->year);
    getchar();
    printf("\t\tcopies:");
    scanf("%d",&new->copies);
    getchar();
    new->copies_now=new->copies;
    Sleep(500);
    printf("\t\tAdding...\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    printf("\t\t...\n");
    Sleep(500);
    printf("\t\tAdded successfully!\n");
    while(t->next){
        t=t->next;
    }
    t->next=new;
    printf("\t\tPress any key to exit");
    getch();
}

int remove_book()
{
    char book_num[20];
    Book *head=Book_head;
    Book *t=Book_head->next;
    look_of_num();
    if(!t){
        printf("\t\tPress any key to exit");
        getch();
        return -1;
    }
    printf("\t\tPlease enter the ID of the book to be removed:");
    gets(book_num);
    t=find_book_by_id(book_num);
    if(!t){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
        return -1;
    }
    //Check whether all copies of the book have been returned
    if(t->copies!=t->copies_now){
        printf("Sorry, the book still has copies to borrow and has not been returned\n");
        printf("Press any key to exit");
        getch();
        return -1;
    }
    t=Book_head->next;
    while(t){
        if(strcmp(book_num,t->id)==0){
            head->next=t->next;
            free(t);
            break;
        }
        head=t;
        t=t->next;
    }
    Sleep(500);
    printf("\t\tIs being removed...\n");
    Sleep(500);
    printf("\t\tSuccessfully removed!\n");
    printf("\t\tPress any key to exit");
    getch();
    Sleep(500);
}

BookArray find_book_by_title(const char* title)
{
    Book *t=Book_head->next;
    while(t){
        if(strcmp(title,t->title)==0)
            break;
        t=t->next;
    }
    if(t==NULL){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
    }
    else{
    t=Book_head->next;
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-20s%-20s%-10s%-8s\n\n",
           "ID","title","author","year","copies");
    while(t){
        if(strcmp(title,t->title)==0)
            printf("\t %-8s%-20s%-20s%-10.2u%-8d\n",
                   t->id,t->title,t->authors,t->year,t->copies_now);
        t=t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();
}}

BookArray find_book_by_author(const char* author)
{
    Book *t=Book_head->next;
    while(t){
        if(strcmp(author,t->authors)==0)
            break;
        t=t->next;
    }
    if(t==NULL){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
    }
    else{
    t=Book_head->next;
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-20s%-20s%-10s%-8s\n\n",
           "ID","title","author","year","copies");
    while(t){
        if(strcmp(author,t->authors)==0)
            printf("\t %-8s%-20s%-20s%-10.2u%-8d\n",
                   t->id,t->title,t->authors,t->year,t->copies_now);
        t=t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();
}}

BookArray find_book_by_year(unsigned int year)
{
    Book *t=Book_head->next;
    while(t){
        if(year==t->year)
            break;
        t=t->next;
    }
    if(t==NULL){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
    }
    else{
    t=Book_head->next;
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-20s%-20s%-10s%-8s\n\n",
           "ID","title","author","year","copies");
    while(t){
        if(year==t->year)
            printf("\t %-8s%-20s%-20s%-10.2u%-8d\n",
                   t->id,t->title,t->authors,t->year,t->copies_now);
        t=t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();
}}

Book *find_book_by_id(char *id)
{
    Book *t=Book_head->next;
    while(t){
        if(strcmp(id,&t->id)==0)
            return t;
        t=t->next;
    }
}

void look_of_num(void)
{
    if(Book_head->next==NULL)
    {
        printf("\t\tNo books\n");
        return;
    }
    if(Book_head->next->next==NULL)
    {
        admin_print_book();
        printf("Press any key to exit the view\n");
        getch();
        return;
    }
    Book *p1,*p2,*p3,*end,*tem;
    Book *head=Book_head;
    end=NULL;
    //Sort books by ID
    while(head->next!=end){
        for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
            if((strcmp(&p2->id,&p3->id))>0){
                p1->next=p2->next;
                p2->next=p3->next;
                p3->next=p2;
                tem=p2;
                p2=p3;
                p3=tem;
            }

        }
        end=p2;
    }
    admin_print_book();
    printf("Press any key to exit the view\n");
    getch();
}

void admin_print_book(void)
{
    Book *t=Book_head->next;
    if(t==NULL){
        printf("\t\tNo book information\n");
        return;
    }
    system("cls");
    printf("\n\n\t**********************************************************************");
    printf("********************************\n\n");
    printf("\t %-8s%-20s%-20s%-10s%-20s%-10s\n\n",
           "ID","title","author","year","existing copies","total number of copies");
    while(t)
    {
        printf("\t %-8s%-20s%-20s%-10u%-20i%-10i\n",
               t->id,t->title,t->authors,t->year,t->copies_now, t->copies);
        t=t->next;
    }
    printf("\n\t**************************************************************************");
    printf("****************************\n\n\n");
}

void admin_add_copies(void)
{
    Book *t;
    int n;
    char ch[20];
    look_of_num();
    if(!Book_head->next){
        printf("\t\tCan't increase copies\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tEnter the ID of the new book:");
    gets(ch);
    t=find_book_by_id(ch);
    if(!t){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tEnter the number of new copies:");
    scanf("%d",&n);
    getchar();
    t->copies+=n;
    t->copies_now+=n;
    Sleep(500);
    printf("\t\tAdding...\n");
    Sleep(500);
    printf("\t\tSuccessfully added %d books\n",n);
    printf("\t\tPress any key to exit");
    getch();
}


