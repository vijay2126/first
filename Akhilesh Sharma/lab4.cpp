#include<iostream>
#include<string.h>
#include<stdlib.h>
#define COUNT 10 
using namespace std;
struct tree
{
	char data[30];
	struct tree* left;
	struct tree* right;
};
struct tree *getNode()
{
	struct tree *newnode;
	newnode = (struct tree*)malloc(sizeof(struct tree));
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct tree *searchNode(struct tree *start, char *data) 
{ 
   
	if(start==NULL)
		return NULL;
	if(!strcmp(start->data,data))
		return start;
	struct tree *temp=searchNode(start->left,data);
	if(temp!=NULL)
		return temp;
	temp=searchNode(start->right,data);
	return temp; 
} 
void displayTree(struct tree *root,int space) 
{
    if (root == NULL) 
        return; 
	space += COUNT; 
	displayTree(root->right, space); 
  	printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->data); 
  	displayTree(root->left, space); 
} 
void insert(struct tree *head)
{
	system("cls");
	char search[20];
	struct tree *cur,*newNode;
	newNode=getNode();	
	cout<<"\tEnter New Node Name :- ";
	cin>>newNode->data;
	cout<<"\tEnter Parent Node :- ";
	cin>>search;
	cur=searchNode(head,search);
	if(cur==NULL)
	{
		cout<<"\n------------Node not found--------------\n";
		return;
	}
	if(cur->left==NULL)
	{
		cur->left=newNode;
		return;
	}
	if(cur->right==NULL)
	{
		cur->right=newNode;
		return;
	}
	cout<<"\n-----------------Space are not avalable--------------\n";
};
struct tree *findparent(struct tree *p,char *ch)
{
	if(p==NULL)
		return(NULL);
	if(p->left!=NULL && (!strcmp(p->left->data,ch)) || p->right!=NULL && (!strcmp(p->right->data,ch)))
		return p;
	struct tree *temp=findparent(p->left,ch);
	if(temp==NULL)
	{
		temp=findparent(p->right,ch);
		return(temp);
	}
};
void displayData(struct tree *root)
{
	struct tree *temp1,*temp2;
	char dis[20];
	printf("\n\n\t\tEnter a Tag Name :- ");
	scanf("%s",dis);
	system("cls");
	temp1=searchNode(root,dis);
	if(temp1==NULL)
	printf("\n\t\t-----------Element Not Found-----------\n");
	else
	{
		printf("\n\t\t---------------Element Found----------------\n");
		if(temp1->left!=NULL || temp1->right!=NULL)
		{
			printf("\n\t\tChildrean are :- %s  %s\n",temp1->left->data,temp1->right->data);
			if(temp1->left->left!=NULL)
			{
			printf("\n\t\tSubchild are  :- %s  %s ",temp1->left->left->data,temp1->left->right->data);
			if(temp1->right!=NULL)
			printf(" %s  %s\n",temp1->right->left->data,temp1->right->right->data);
			else
				printf("\n");
			}
			else
			printf("\n\t\t----------Parent have not Subchild----------\n");
		}
		else
		{
			printf("\n\t\t-----------Parent have not child-----------\n");
			printf("\n\t\t----------Parent have not Subchild----------\n");
		}
		
		if(strcmp(root->data,dis)==0)
		printf("\n\t\troot element\n");
		else
		{
			temp2=findparent(root,dis);
			printf("\n\t\tperent is\t :- %s \n",temp2->data);
			printf("\n\t\tSibling is\t :- %s , %s\n",temp2->left->data,temp2->right->data);
		}
	}
}

int main()
{
	char s[10];
	struct tree *root;
	root = getNode();
	strcpy(root->data,"<html>");
	root->left=getNode();
	root->right=getNode();	
	strcpy(root->left->data,"<head>");
	strcpy(root->right->data,"<body>");
	while(1)
	{
		char choise;
		cout<<"\n\t\t1. Insert Node";
		cout<<"\n\t\t2. Display Node data";
		cout<<"\n\t\t3. Display Full Tree";
		cout<<"\n\t\t4. Exit";
		cout<<"\n\n\t\tEnter a Number :- ";
		cin>>choise;
		switch(choise)
		{
			case '1':
			{
				system("cls");
				insert(root);
				break;
			}
			case '2':
			{
				system("cls");
				displayData(root);
				break;
			}
			case '3':
			{
				system("cls");
				displayTree(root,0);
				break;
			}
			case '4': exit(0);
			default :
			{
				system("cls");
				cout<<"\n\t\tEnter Valid choise\n";
				break;
			}
		}
	}
}
