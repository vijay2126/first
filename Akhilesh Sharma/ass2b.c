#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int i,j=0,l;
int ch;
char *s;
FILE *fp;
//system("cls");
fp=fopen("new.txt","a");
gets(s);
fputs(s,fp);
//system("cls");
do
{
printf("Press 1.Undo operation\npress 2.Redo operation\npress 3.Exit\n");
scanf("%d",&ch);
 switch(ch)
 {
 case 1:fp=fopen("new.txt","r");
	while(fgets(s,20,fp)!=NULL)
	l=strlen(s);
	if(j<(l))
	{
	j++;
	if(j==l-1)
	{
	printf("data not available\n");
	break;
	}
	for(i=0;i<(l-j);++i)
	 printf("%c",s[i]);
	}
	else
	 printf("data not available\n");
	break;
 case 2:if(j>0)
	{
	 j--;
	 for(i=0;i<(l-j);++i)
	  printf("%c",s[i]);
	 }
	 else
	  printf("\n");
	 break;
 case 3:break;
 default:printf("Invalid Choice\n");
 }
 getch();
 system("cls");
 }while(ch!=3);
 return 0;
}

