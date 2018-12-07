
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

//===========================
//===========================
class book
{
friend class library;

private:
    char book_name[11];
    char explain[51];
    char aouther[11];
    char part;

    char user[11];    
     int reserved;

    book *next;

public:
         book();
    void edit();
    void reserv();
    void getback();
}
//---------------------------
     book::book()
    {
     clrscr();

     cout<<"============ add a new book =================="
         <<"\n\nto insert new book ,enter flow informations:"
         <<"\n\nbook name?";
     gets(book_name);
     book_name[10]=NULL;

     cout<<"\naouther name?";
     gets(aouther);
     aouther[10]=NULL;

     cout<<"\nany explain?";
     gets(explain);
     explain[50]=NULL;

     part=book_name[0];

     reserved=0;

     next=NULL;

     cout<<"\n\ninformathions set!";
     getch();
    }
//---------------------------
void book::edit()
    {
cout<<"error ";
    }
//---------------------------
void book::reserv()
    {
     clrscr();
     cout<<"\n=========== reserving book ===================";

     if(reserved==0)
        {
         cout<<"\n\nuser name?";
         gets(user);
         user[11]=NULL;

         reserved=1;
        }

     if(reserved==0)
        {
         cout<<"\n\nsorry! book has been reserved befor"
             <<"by user:";
         puts(user);
        }

     getch();
    }
//---------------------------
void book::getback()
    {
     reserved=0;

     cout<<"\n\nbook got bak.";
     getch();
    }
//===========================
//===========================
class library
{
public:
          library();
     void run_menu();

private:
     book *parts[24];
     void insert(book*);
     void find();
     void search();

}
//---------------------------
     library::library()
    {
     for(int i=0;i<=23;i++)
        parts[i]=NULL;

    }
//---------------------------
void library::run_menu()
    {

     char ch='n';

     while(ch!='4')
        {
         clrscr();

         cout<<"================= LIBRARY =================="
             <<"\n\n1:add a new book."
             <<"\n2:find a book."
             <<"\n3:search a book."
             <<"\n4:exit."
             <<"press numbers:";


         ch=getch();


         if(ch=='1')
            {
             book *n=new book;
             insert(n);
            }
         if(ch=='2')
            {
             find();
            }
         if(ch=='3')
            {
             search();
            }

        }//while
    }
//---------------------------
void library::insert(book *s)
    {
     int d=s->part-97;

     if(parts[d]==NULL)
        {
         parts[d]=s;
        }
     else
        {
         book *p=parts[d],*q;
         while(p!=NULL && strcmp(p->book_name,s->book_name)<0)
            {
             q=p;
             p=p->next;
            }
         q->next=s;
         s->next=p;
        }

    }
//---------------------------
void library::find()
    {
     clrscr();

     cout<<"=========== edit / delete books ============"
         <<"\nenter exact book name:";
     char name[11];
     gets(name);
     name[11]=NULL;
     int d=name[0]-97;

     book *p=parts[d],*q;
     while(p!=NULL && strcmp(p->book_name,name)!=0)
        {
         q=p;
         p=p->next;
        }
     if(p==NULL)
        {
         cout<<"not found!";
        }
     if(p!=NULL)
        {
         cout<<"\n\ndelete it?('d')  or edit?('e')"
             <<"  or reserv?('r')   or getback?('g') :";
         char ch=getch();
         if(ch=='d')
             {
              q->next=p->next;
              delete p;
             }
         if(ch=='e')
             {
              p->edit();
             }
         if(ch=='r')
             {
              p->reserv();
             }
         if(ch=='g')
            {
             p->getback();
            }
        }
     getch();
    }
//---------------------------
void library::search()
    {
     char ch='6';

     while(ch!='4')
        {
         clrscr();
         cout<<"================== SEARCH ===================";
         cout<<"\n\n1:search for name."
             <<"\n2:search for aouther."
             <<"\n3:search for explanations."
             <<"\n4:back to main menu.(press numbers)";

         ch=getch();

         if(ch=='1')
            {
             cout<<"\n\nenter exact name:";
             char name[10];
             gets(name);
             name[11]=NULL;

             int d=name[0]-97;
             book *p=parts[d];
             while(p!=NULL && strcmp(p->book_name,name)!=0)
                {
                 p=p->next;
                }
             if(p==NULL)
                {
                 cout<<"\nnot founded!";
                }
             else
                {
                 cout<<"\n\n";
                 cout<<"name:";puts(p->book_name);
                 cout<<"aouther:";puts(p->aouther);
                 cout<<"explain:";puts(p->explain);
                 if(p->reserved==1)
                    {
                     cout<<"RESERVED by:";
                     puts(p->user);
                    }
                 else
                    {
                     cout<<"NOT RESERVES";
                    }
                }//else
             getch();
            }//1
         if(ch=='2')
            {
             cout<<"\n\nenter exact aouther name:";
             char name[11];
             gets(name);
             name[11]=NULL;
             int f=0;

             for(int i=0;i<=23;i++)
               {
                book *p=parts[i];
                while(p!=NULL)
                {
                 if(strcmp(p->aouther,name)==0)
                    {
                     f++;
                     cout<<"\n"<<f<<":";
                     cout<<"name:";puts(p->book_name);
                     cout<<"aouthor:";puts(p->aouther);
                     cout<<"explain:";puts(p->explain);
                     if(p->reserved==1)
                        {
                         cout<<"RESERVED BY";
                         puts(p->user);
                        }
                     else
                        {
                         cout<<"NOT RESERVED";
                        }
                    }

                 p=p->next;
                }//while
               }
             getch();
            }//2
         if(ch=='3')
            {
             cout<<"\n\nenter key(15char):";
             char name[16];
             gets(name);
             name[15]=NULL;
             int f=0;

             for(int i=0;i<=23;i++)
               {
                book *p=parts[i];
                while(p!=NULL)
                {
                 char *tokenptr;
                 tokenptr=strtok(p->explain," ");
                 while(tokenptr!=NULL)
                    {
                     if(strcmp(tokenptr,name)==0)
                        {
                         f++;

                         cout<<"\n"<<f<<":";
                         cout<<"name:";puts(p->book_name);
                         cout<<"aouthor:";puts(p->aouther);
                         cout<<"explain:";puts(p->explain);
                         if(p->reserved==1)
                             {
                              cout<<"RESERVED BY";
                              puts(p->user);
                             }
                         else
                             {
                              cout<<"NOT RESERVED";
                             }
                        }
                     tokenptr=strtok(NULL," ");
                    }

                 p=p->next;
                }//while
               }//for i
             getch();
            }//3

        }

    }
//===========================
//===========================
int main()
    {
     clrscr();

     library l1;
     l1.run_menu();

     return(0);
}