#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int st[MAX],top=-1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

void main()
{
   clrscr();
   int op,val;
   do
   {
	printf("MAIN MENU\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter any one option\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("Enter the number to be pushed onto stack\n");
			scanf("%d",&val);
			push(st,val);
			break;
		case 2:
			val=pop(st);
			if(val!=-1)
			{
				printf("The number removed from stack is %d\n",val);
				break;
			}
		case 3:
			val=peek(st);
			if(val!=-1)
			{
				printf("The top element of the stack is %d\n",val);
				break;
			}
		case 4:
			display(st);
			break;
	}
   }while(op!=5);
   getch();
}

void push(int st[],int val)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{	top+=1;
		st[top]=val;
	}
}

int pop(int st[])
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
	{
		return st[top--];
	}
}

int peek(int st[])
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
	{
		return st[top];
	}
}

void display(int st[])
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		for(int i=top;i>=0;--i)
		{
			printf("%d",st[i]);
			printf("\n");
		}
	}
}































