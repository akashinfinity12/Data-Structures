#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack
{
	int data;
	struct stack *next;
};

struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
struct stack *top=NULL;
int peek(struct stack *);

void main()
{
	clrscr();
	int val,op;
	do
	{
		printf("MAIN MENU\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");;
		printf("5. Exit\n");
		printf("Enter any one option\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the element to be pushed onto the linked stack\n");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				val=peek(top);
				printf("Topmost Value:%d\n",val);
				break;
			case 4:
				top=display(top);
				break;
		}
	}while(op!=5);
	getch();
}

struct stack *push(struct stack *top,int val)
{
	struct stack *ptr;
	ptr=(struct stack *)malloc(sizeof(struct stack));
	ptr->data=val;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Linked Stack Underflow\n");
	else
	{
		top=top->next;
		printf("Value Deleted=%d\n",ptr->data);
		free(ptr);
	}
	return top;
}

struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Linked Stack Underflow\n");
	else
	{
		while(ptr->next!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
	return top;
}

int peek(struct stack *top)
{
	if(top==NULL)
		printf("Linked Stack Underflow\n");
	else
		return top->data;
}