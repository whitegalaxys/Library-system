#include "book_management.h"
#include "account.h"

int store_books()
{
    FILE *fp;
    Book *t=Book_head->next;
    if(!t)
        return -1;
    if((fp=fopen("Booknode.txt","w+"))==NULL){
        printf("\t\tOpen failed\n");
        exit(1);
    }
    while(t->next){
        fprintf(fp,"%i",&t->id);
        fprintf(fp,"%s",t->title);
        fprintf(fp,"%s",t->authors);
        fprintf(fp,"%i",&t->year);
        fprintf(fp,"%i",&t->copies);
        t=t->next;
    }
    fprintf(fp,"%i",&t->id);
    fprintf(fp,"%s",t->title);
    fprintf(fp,"%s",t->authors);
    fprintf(fp,"%i",&t->year);
    fprintf(fp,"%i",&t->copies);
    fclose(fp);
    return 0;
}

Book *load_books()
{
    FILE *fp;
    Book *h=NULL,*t=h,*p;
    if((fp=fopen("Booknode.txt","r"))==NULL){
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
        fscanf(fp,"%i",&p->id);
        fscanf(fp,"%s",p->title);
        fscanf(fp,"%s",p->authors);
        fscanf(fp,"%i",&p->year);
        fscanf(fp,"%i",&p->copies);
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
    gets(new->id);
    if(find_book_by_id(new->id)){
        free(new);
        printf("\t\tThe book has already been put on the shelves, please choose to increase inventory\n");
        printf("\t\tPress any key to exit");
        getch();
        return -1;
    }
    printf("\t\ttitle:");
    gets(new->title);
    printf("\t\tauthor:");
    gets(new->authors);
    printf("\t\tyear:");
    scanf("%u",&new->year);
    getchar();
    printf("\t\tcopies:");
    scanf("%u",&new->copies);
    getchar();
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
    Book *t=Book_head->next;
    Lookofnum();
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
    t->copies=0;
    Sleep(500);
    printf("\t\tIs being removed...\n");
    Sleep(500);
    printf("\t\tSuccessfully removed!\n");
    printf("\t\tPress any key to exit");
    getch();
}

BookArray find_book_by_title(const char* title)
{
    BookArray *t=Book_head->next;
    while(t){
        if(strcmp(title,t->array->title)==0)
            return *t;
        t=t->array->next;
    }
}

BookArray find_book_by_author(const char* author)
{
    BookArray *t=Book_head->next;
    while(t){
        if(strcmp(author,t->array->authors)==0)
            return *t;
        t=t->array->next;
    }
}

BookArray find_book_by_year(unsigned int year)
{
    BookArray *t=Book_head->next;
    while(t){
        if(strcmp(year,t->array->year)==0)
            return *t;
        t=t->array->next;
    }
}

Book *find_book_by_id(unsigned int id)
{
    Book *t=Book_head->next;
    while(t){
        if(strcmp(id,t->id)==0)
            return t;
        t=t->next;
    }
}

void Lookofnum(void)
{
    if(Book_head->next==NULL)
    {
        printf("\t\tNo books\n");
        return;
    }
    if(Book_head->next->next==NULL)
    {
        return;
    }
    Book *p1,*p2,*p3,*end,*tem;
    Book *head=Book_head;
    end=NULL;
    while(head->next!=end){
        for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
            if((strcmp(p2->id,p3->id))>0){
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
    Manager_Print_Book();
}

void Manager_Print_Book(void)
{
    Book *t=Book_head->next;;
    if(t==NULL){
        printf("\t\tNo book information\n");
        return;
    }
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-10s%-8s\n\n",
           "ID","title","author","year","copies");
    while(t)
    {
        printf("\t %-8u%-12s%-12s%-18u%-10i-8d\n",
               t->id,t->title,t->authors,t->year,t->copies);
        t=t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
}

void Manager_Add_copise(void)
{
    Book *t;
    int n;
    char ch[20];
    Lookofnum();
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
    Sleep(500);
    printf("\t\tAdding...\n");
    Sleep(500);
    printf("\t\tSuccessfully added %d books\n",n);
    printf("\t\tPress any key to exit");
    getch();
}

void Find_Book(void)
{
    Book *t=Book_head->next;
    char book_n[20];
    if(t==NULL){
        printf("\t\tSorry, no books\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    printf("\t\tPlease enter the title of the book you need to find:");
    gets(book_n);
    while(t){
        if(strcmp(book_n,t->title)==0)
            break;
        t=t->next;
    }
    if(t==NULL){
        printf("\t\tSorry, no such book\n");
        printf("\t\tPress any key to exit");
        getch();
        return;
    }
    t=Book_head->next;
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-10s%-8s\n\n",
           "ID","title","author","year","copies");
    while(t){
        if(strcmp(book_n,t->title)==0)
            printf("\t %-8u%-12s%-12s%-10.2u%-8d\n",
                   t->id,t->title,t->authors,t->year,t->copies);
        t=t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit");
    getch();

}

Book *Book_exit(char *Book_num)
{

    Book *t=Book_head->next;
    while(t){
        if(strcmp(t->id,Book_num)==0)
            break;
        t=t->next;
    }
    return t;
}


