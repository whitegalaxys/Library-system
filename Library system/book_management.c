#include "book_management.h"
#include "menu.h"

int store_books(FILE* file)
{
    FILE*fp;
    int digit=0;
    float price=0;
    char  nam[20],aut[20],pub[20],num[20];
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    fp = fopen(file,"a");
    scanf("%s%s%s%s%d%f",num,nam,aut,pub,&digit,&price);
    fprintf(fp,"%-8s%-9s%-14s%-16s%-7d%-8.2f\n",num,nam,aut,pub,digit,price);
    fclose(fp);
}

int load_books(FILE* file)
{
    FILE *fp;
    if ((fp=fopen("library.txt","r"))==NULL)//打开文件
    {
        system ("cls");
        printf("\n记录文件不存在!按任意键返回");
        getch();
    }
}

int add_book(Book book)
{
    char i;
    system ("cls");
    printf("\n请按以下格式输入图书信息:\n书号    书名     作者    出版社     进库量      单价");
    for(; i!=27;)
    {
        printf("\n请输入:\n");
        store_books("library.txt");
        printf("结束输入请按ESC\n");
        i=getch();
    }
    printf("\n保存成功，按任意键返回上一层!");
    getch();
    admin_book();
}

int remove_book(Book book)
{
    struct _Book *head=NULL;
    struct _Book *p,*p1,*p2;
    int tmany=0,n=0,j,k;
    float tprice=0;
    char  tnam[20],taut[20],tcat[20],tpub[20],tnum[20];
    char jnam[20];
    char i,hit;
    FILE *fp;
    if ((fp=fopen("library.txt","r"))==NULL)//打开文件
    {
        system ("cls");
        printf("\n记录文件不存在!按任意键返回");
        getch();
        admin_book();
    }
    else//实现删除的功能
    {
        system ("cls");
        printf("\n请输入你要删除的书名:");//输入删除图书书名
        scanf("%s",jnam);
        printf("\n确认删除请回车，取消请按Esc\n");
        i=getch();
        for(; i!=13&&i!=27;)
            i=getch();
        if (i==27)
            admin_book();
        fp=fopen("library.txt","r");
        j=books_num();
        for (k=0; k<j; k++)
        {
            fscanf(fp,"%s%s%s%s%d%f",tnum,tnam,taut,tpub,&tmany,&tprice);
            if (strcmp(jnam,tnam)!=0)//比较名字，将不同名字的信息复制到链表
            {
                n++;
                if (n==1)//建立链表
                {
                    p1=p2=(struct _Book*)malloc(sizeof(struct _Book));
                    head=p1;
                }
                else
                {
                    p2->next=p1;
                    p2=p1;
                    p1=(struct _Book*)malloc(sizeof(struct _Book));//新建链表
                }

                strcpy(p1->num,tnum);//复制书号
                strcpy(p1->nam,tnam);//复制书名
                strcpy(p1->aut,taut);//复制作者名字
                strcpy(p1->pub,tpub);//复制出版社
                p1->digit=tmany;//复制个数
                p1->price=tprice;//复制单价
            }
        }
        if (n==0)
        {
            head=NULL;
        }
        else
        {
            p2->next=p1;
            p1->next=NULL;
            fclose(fp);
        }
    }
    fp=fopen("library.txt","w");//清空文件，只写打开，然后关闭
    fclose(fp);
    fp=fopen("library.txt","a");//追加文件
    p=head;
    for (; p!=NULL;) //把链表内容覆盖到文件
    {
        fprintf(fp,"%-8s%-9s%-14s%-16s%-7d%-8.2f\n",p->num,p->nam,p->aut,p->pub,p->digit,p->price);
        p=p->next;
    }
    fclose(fp);
    printf("\n删除成功,按任意键返回上一层\n");
    getch();
    admin_book();
}

BookArray find_book_by_title(const char* title)
{

}

BookArray find_book_by_author(const char* author)
{

}

BookArray find_book_by_year(unsigned int year)
{
    
}

int books_num()//统计图书文本个数
{
    FILE *fp;
    int many=0,n;
    float tprice=0;
    char tname[20],tauthor[20],tchuban[20],tshuhao[20];
    fp=fopen("library.txt","r");//打开文件
    for (n=0; !feof(fp); n++) //逐个读文件
        fscanf(fp,"%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,&many,&tprice);
    n--;
    fclose(fp);//关闭文件
    return (n);//返回个数
}