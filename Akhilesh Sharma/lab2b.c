#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	
	char str[100];
	int choice;
	while(1)
	{
		printf("\nenter 1  for write on file\n");
		printf("enter 2  for undo\n");
		printf("enter 3  for redo\n");
		printf("enter 4  for exit\n");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			case 1:
				{
					FILE *fp=fopen("undoredo","w");
					if(fp==NULL)
					{
						printf("error opening file\n");
						exit(1);
					}
					else
					{
						printf("enter string\n");
						scanf("%s",str);
						fprintf(fp,"%s",str);
						printf("\n data saved properly");
					}	
					break;
				}
			case 2:
				{
					FILE *fr=fopen("Z:\\undoredo","a");
					fseek(fr,-1,SEEK_END);
					ftruncate(fileno(fr),ftello(fr));
					break;
				}
			case 3:
				{
					
				}
			case 4:
				{
					exit(1);
					break;
				}
			default:
				{
				printf("wrong choice");
				break;
				}
		}
	}
	return 0;
}
