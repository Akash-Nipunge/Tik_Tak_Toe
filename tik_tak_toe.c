#include<stdio.h>
#include<windows.h>
char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int p,p1=0,p2=0;
void print_h(void)
{
    for(int i=0;i<11;i++)
    printf("_");
}
void print_box(void)
{
   
    for(int i=0;i<3;i++)
    {
            printf("\033[1;31m");
            printf("\t\t");
            printf(" %c   %c   %c ",a[i][0],a[i][1],a[i][2]);
            printf("\033[1;32m");
            printf("\n\t\t___|___|___ \n");
             printf("\033[0;30m");
    }
}
int check(void)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==' ')
            return 1;
        }
    }
     return 0;
}
int cheackwin(void)
{
   
    for(int i=0;i<3;i++)
    {
        if((a[i][0]=='X'&&a[i][1]=='X'&&a[i][2]=='X' )|| (a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X') || ( a[0][i]=='X'&&a[1][i]=='X'&&a[2][i]=='X') || (a[0][2]=='X'&& a[1][1]=='X' && a[2][0]=='X'))
        {
            p1++;
            return 1;
        }
       if((a[i][0]=='O'&&a[i][1]=='O'&&a[i][2]=='O' )|| (a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O' )|| (a[0][i]=='O'&&a[1][i]=='O'&&a[2][i]=='O') || (a[0][2]=='O'&& a[1][1]=='O' && a[2][0]=='O'))
        {
            p2++;
            return 1;
        }
    }
    return 0;
}
void make_blank(void)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        a[i][j]=' ';
    }
}
int main()
{
    int r,c;
   
    do
    {
    make_blank();
     system("CLS");
    print_box();
    while(check())
   {
    if(check()==0)
    break;
    do
   { printf("\033[1;36m");
     printf("\n\tPLAYER 1\n\tENTER THE POSITION row(1-3) col(1-3) : ");
      printf("\033[0;30m");
    scanf("%d %d",&r,&c);
    printf("\033[1;31m");
    if(a[r-1][c-1]!=' ')
    printf("\n\t\tINVALID MOVE");
     printf("\033[0;30m");
   }
   while(a[r-1][c-1]!=' ');
    system("CLS");
   a[r-1][c-1]='X';
    print_box();
    if(cheackwin())
    break;
    if(check()==0)
    break;
    do
   { 
    printf("\033[1;35m");
     printf("\n\tPLAYER 2\n\tENTER THE POSITION row(1-3) col(1-3) : ");
      printf("\033[0;30m");
    scanf("%d %d",&r,&c);
    printf("\033[1;31m");
    if(a[r-1][c-1]!=' ')
   {
     printf("\n\t\tINVALID MOVE");
   }
     printf("\033[0;30m");
   }
   while(a[r-1][c-1]!=' ');
   a[r-1][c-1]='O';
    system("CLS"); 
    print_box();
   if(cheackwin())
   break;
    }
    printf("\033[1;33m");
    printf("\n\tWANT TO PLAY AGAIN PRESS 1 \n\tIF NOT PRESS 0 : ");
     printf("\033[0;30m");
    scanf("%d",&p);
    }
    while(p==1);
    printf("\033[1;32m");
    if(p1>p2)
   {
     printf("\n\n\n\t\tPLAYER 1 WINS WITH SCORE %d \n\n\n\n\n",p1);
   }
    else if(p1==p2)
    {
        printf("\n\n\n\t\tPLAYER 1 AND PLAYER 2 HAS SAME SCORE\n\n\n\n\n");
    }
    else
   {
     system("CLS");
     printf("\n\n\n\t\tPLAYER 2 WINS WITH SCORE %d\n\n\n\n\n",p2);
   }
    printf("\033[0;30m");
    return 0;
}
