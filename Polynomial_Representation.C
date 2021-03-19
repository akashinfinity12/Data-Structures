#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int num;
	int coeff;
};

struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *display(struct node *);
struct node *create(struct node *);
struct node *addpoly(struct node *,struct node *,struct node *);
struct node *subpoly(struct node *,struct node *,struct node *);
struct node *addnode(struct node *,int,int);

void main()
{
	clrscr();
	int op;
	do
	{
		printf("MAIN MENU\n");
		printf("1. Enter 1st polynomial\n");
		printf("2. Display 1st polynomial\n");
		printf("3. Enter 2nd polynomial\n");
		printf("4. Dislay 2nd polynomial\n");
		printf("5. Add the polynomials\n");
		printf("6. Subtract the polynomials\n");
		printf("7. Display addition result\n");
		printf("8. Display subtraction result\n");
		printf("9. Exit\n");
		printf("Enter any one option\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				start1=create(start1);
				break;
			case 2:
				start1=display(start1);
				break;
			case 3:
				start2=create(start2);
				break;
			case 4:
				start2=display(start2);
				break;
			case 5:
				start3=addpoly(start1,start2,start3);
				break;
			case 6:
				start4=subpoly(start1,start2,start4);
				break;
			case 7:
				start3=display(start3);
				break;
			case 8:
				start4=display(start4);
				break;
		}
	}while(op!=9);
getch();
}

struct node *create(struct node *start)
{
	struct node *new_node,*ptr;
	int p,c;
	printf("Enter -1 to end\n");
	printf("Enter the coefficient\n");
	scanf("%d",&c);
	printf("Enter the power\n");
	scanf("%d",&p);
	while(c!=-1)
	{
		if(start==NULL)
		{
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->coeff=c;
			new_node->num=p;
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->coeff=c;
			new_node->num=p;
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("Enter the coefficient\n");
		scanf("%d",&c);
		if(c==-1)
			break;
		printf("Enter the power\n");
		scanf("%d",&p);
	}
return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	printf("Elements are..\n");
	ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d raise %d\t",ptr->coeff,ptr->num);
		ptr=ptr->next;
	}
	printf("%d raise %d\n",ptr->coeff,ptr->num);
return start;
}

struct node *addpoly(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sum;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->num==ptr2->num)
		{
			sum=ptr1->coeff + ptr2->coeff;
			start3=addnode(start3,sum,ptr1->num);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->num > ptr2->num)
		{
			start3=addnode(start3,ptr1->coeff,ptr1->num);
			ptr1=ptr1->next;
		}
		else if(ptr2->num > ptr1->num)
		{
			start3=addnode(start3,ptr2->coeff,ptr2->num);
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start3=addnode(start3,ptr2->coeff,ptr2->num);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start3=addnode(start3,ptr1->coeff,ptr1->num);
			ptr1=ptr1->next;
		}
	}
return start3;
}

struct node *subpoly(struct node *start1,struct node *start2,struct node *start4)
{
	struct node *ptr1,*ptr2;
	int diff;
	ptr1=start1;
	ptr2=start2;
	do
	{
		if(ptr1->num==ptr2->num)
		{
			diff=ptr1->coeff - ptr2->coeff;
			start4=addnode(start4,diff,ptr1->num);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->num > ptr2->num)
		{
			start4=addnode(start4,ptr1->coeff,ptr1->num);
			ptr1=ptr1->next;
		}
		else if(ptr2->num > ptr1->num)
		{
			start4=addnode(start4,ptr2->coeff,ptr2->num);
			ptr2=ptr2->next;
		}
	}while(ptr1!=NULL || ptr2!=NULL);
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start4=addnode(start4,ptr2->coeff,ptr2->num);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start4=addnode(start4,ptr1->coeff,ptr1->num);
			ptr1=ptr1->next;
		}
	}
return start4;
}

struct node *addnode(struct node *start,int c,int p)
{
	struct node *new_node,*ptr;
	if(start==NULL)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->coeff=c;
		new_node->num=p;
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		new_node->coeff=c;
		new_node->num=p;
		ptr->next=new_node;
		new_node->next=NULL;
	}
return start;
}