#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10
void push(char c);
char pop();
int st[MAX];
int top=-1;
void main()
{
   clrscr();
   char a[MAX],temp;
   int flag=1;
   printf("Enter the expression\n");
   gets(a);
   for(int i=0;i<strlen(a);++i)
   {
      if(a[i]=='(' || a[i]=='{' || a[i]=='[')
      {
	push(a[i]);
      }
      if(a[i]==')' || a[i]=='}' || a[i]==']')
      {
	if(top==-1)
	{
		flag=0;
	}
	else
	{
		temp=pop();
		if(a[i]==')' && (temp=='[' || temp=='{'))
		{
			flag=0;
		}
		if(a[i]==']' && (temp=='(' || temp=='{'))
		{
			flag=0;
		}
		if(a[i]=='}' && (temp=='(' || temp=='('))
		{
			flag=0;
		}
	}
	if(top>=0)
	{
		flag=0;
	}
	if(flag==1)
	{
		printf("Valid Expression");
	}
	else
	{
		printf("Invalid Expression");
	}
      }
   }
	getch();
}

void push(char c)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top+=1;
		st[top]=c;
	}
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		return st[top--];
	}
}