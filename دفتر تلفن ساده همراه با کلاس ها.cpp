#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//=====================================
//=====================================
struct address {
       char name[30] ;
       char street[30] ;
       char city[20] ;
       char state[3] ;
       char number[14] ;
       struct address *next ;
       struct address *prior ;
} list_entry ;
//=====================================
//=====================================
struct address *start ;
struct address *last ;

void enter() , display() , search() ;
void list() , del();
void display(struct address *info, int *row);

struct address *find(char *);
int menu_select();
struct address *store(struct address *, struct address *);
//=====================================
//=====================================




//****************

int menu_select()
{
      char s[5];
      system("cls");
      gotoxy(25,4) ;
      printf("1. enter a name ") ;
      gotoxy(25,6) ;
      printf("2. delete a name ") ;
      gotoxy(25, 8) ;
      printf("3. list all files ") ;
      gotoxy(25, 10) ;
      printf("4. search ") ;
      gotoxy(25, 12) ;
      printf("5. quit ") ;
      do {
      gotoxy(20, 18) ;
      printf("enter your select--power By majid (1-5):");
      gets(s);
      } while (atoi(s) < 0 || atoi(s) > 5) ;
      return atoi(s) ;
}
//*********************


void enter ()
{
   struct address *info ;
   int i ;
   char ch ;
   system("cls") ;
   gotoxy(3, 2) ;
   printf("   name        street     city     state    number");
   gotoxy(3, 3) ;
   printf(" ------------ -------- ");
   printf("--------   -----  ------- ");
   i = 4 ;
   for (;;) {
     info = (struct address *)malloc(sizeof(list_entry)) ;
     if(!info) {
    printf("\n out of memory. press a key ") ;
    getch();
    return ;
     }
     gotoxy(3, i) ;
     gets(info -> name) ;
     if (!info -> name[0]) {
      gotoxy(15, i + 1) ;
      printf("press a key to continue");
      getch() ;
      break ;
     }//end of if
     gotoxy(18, i);
     gets(info -> street) ;
     gotoxy(28, i) ;
     gets(info -> city) ;
     gotoxy(38, i) ;
     gets(info -> state) ;
     gotoxy(45, i) ;
     gets(info -> number) ;
     i++ ;
     start = store(info, start) ;
     } /* entry loop */
    }
//**************


struct address *store(struct address *i, struct address *top)
{
   struct address *old, *p ;
   if(last == NULL) {
    i -> next = NULL ;
    i -> prior = NULL ;
    start = i;
    last = i ;
    return i ;
   }
   p = top ;
   old = NULL ;
   while (p != NULL) {
       if(strcmp(p -> name, i -> name) < 0) {
          old = p ;
          p = p -> next ;
       }//end of if
       else {
         if (p -> prior) {
          p -> prior -> next=i ;
          i -> next=p ;
          i -> prior=p -> prior;
          p -> prior=i ;
          return top ;
         }//end of if
         i -> next = p ;
         i -> prior = NULL ;
         p -> prior = i ;
         return i ;
       }//end of if
   } // end of while
   old -> next = i ;
   i -> next = NULL ;
   i -> prior = old ;
   last = i ;
   return start ;
}
//******************


void del()
{
   struct address *info;
   char name[80];
   gotoxy(20, 20) ;
   printf(" enter name for delete : ") ;
   gets(name) ;
   info = find(name) ;
   if(info == NULL) {
       gotoxy(10, 20) ;
       printf(" name not found! press a key to continue.");
       getch() ;
   }
   if (info)
     if (start == info)
    {
      start = info -> next ;
      if(start)
         start -> prior = NULL ;
      else
         last = NULL ;
    } //end of if
     else  {
       info -> prior -> next = info -> next;
       if(info != last)
         info -> next -> prior = info -> prior;
       else
        last = info -> prior ;
     } //end of else
     free(info) ;
     gotoxy(10,20) ;
     printf("name deleted, press a key to continue.");
     getch() ;
}
//*******************************


struct address *find(char *name)
{
     struct address *info ;
     info = start ;
     while(info != NULL) {
    if (strcmp(name, info -> name) == 0)
       return info;
    info = info -> next ;
     }
     return NULL ;
}
//*****************


void list ()
{
    struct address *info ;
    int i ;
    info = start ;
    system("cls") ;
    gotoxy(3, 2) ;
    printf("   name        street     city     state    number");
    gotoxy(3, 3) ;
    printf(" ------------ --------  -");
    printf("-------   -----  ------- ");
    i = 4 ;
    while(info != NULL) {
    display(info, &i) ;
    info = info -> next ;
    }
    gotoxy(15, i + 2) ;
    printf("press a key to continue.");
    getch() ;
}
//*******************


void display(struct address *info, int *row)
{
      gotoxy(3, *row) ;
      printf("%s", info -> name) ;
      gotoxy(18, *row) ;
      printf("%s", info -> street) ;
      gotoxy(28, *row) ;
      printf("%s", info -> city) ;
      gotoxy(38, *row) ;
      printf(info -> state) ;
      gotoxy(47, *row) ;
      printf(info -> number) ;
      *row = *row + 1 ;
}
//**************************


void search()
{
     char name[40] ;
     int i ;
     struct address *info;
     gotoxy(20, 20) ;
     printf(" enter name to find : ");
     gets(name) ;
     info = find(name) ;
     if(info == NULL) {
      gotoxy(10, 20) ;
      printf(" name not found! press a key to continue.");
      getch() ;
     }//end of if
     else  {
          system("cls") ;
          gotoxy(3, 2) ;
          printf("   name        street   city     state   number");
          gotoxy(3, 3) ;
          printf(" ------------ -------");
          printf("-  --------   -----  ------- ") ;
          i = 4 ;
          display(info ,&i) ;
          gotoxy(15, i + 2) ;
          printf("press a key to continue.");
          getch() ;
     }//end of else
}
//*********************

int main()
{
       start = last = NULL ;
       for(;;) {
         switch(menu_select()) {
           case 1:  enter();  break ;
           case 2 : del();    break ;
            case 3:  list() ;  break ;
           case 4:  search(); break ;
           case 5:  exit(0) ;

        }//end of switch
       }//end of for
}//end of main