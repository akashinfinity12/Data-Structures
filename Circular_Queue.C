#include<stdio.h>
#include<conio.h>
#define MAX 3
int cqueue[MAX];
int front=-1;
int rear=-1;
void einsert(int a);
int edelete(void);
int peek(void);
void display(void);

void main()
{
	clrscr();
	int n,op;
	do
	{
		printf("MAIN MENU\n");
		printf("1.Insert an element in circular queue\n");
		printf("2.Delete an element from circular queue\n");
		printf("3.Display the topmost element in circular queue\n");
		printf("4.Display all the elements of circular queue\n");
		printf("5.Exit\n");
		printf("Enter any one option\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the element you want to add\n");
				scanf("%d",&n);
				einsert(n);
				break;
			case 2:
				n=edelete();
				if(n!=-1)
					printf("Deleted element is %d\n",n);
				break;
			case 3:
				n=peek();
				if(n!=-1)
					printf("Topmost element is %d\n",n);
				break;
			case 4:
				display();
				break;
		}
	}while(op!=5);
	getch();
}

void einsert(int a)
{
	if(front==0 && rear==MAX-1)
	{
		printf("Circular Queue Overflow\n");
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		cqueue[rear]=a;
	}
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		cqueue[rear]=a;
	}
	else
	{
		rear++;
		cqueue[rear]=a;
	}
}

int edelete()
{
	int val;
	if(front==-1 && rear==-1)
	{
		printf("Circular Queue Underflow\n");
		return -1;
	}
	val = cqueue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{ 
		if(front==MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
	return val;
}

int peek()
{
	if(front==-1 && rear==-1)
	{
		printf("Circular Queue Underflow\n");
		return -1;
	}
	else
	{
		return cqueue[front];
	}
}

void display()
{
	if(front==-1 && rear==-1)
	{
		printf("Circular Queue Underflow\n");
	}
	else
	{
		if(front<rear)
		{
			for(int i=front;i<=rear;++i)
			{
				printf("%d\t",cqueue[i]);
			}
			printf("\n");
		}
		else
		{
			for(int i=front;i<=MAX-1;++i)
			{
				printf("%d\t",cqueue[i]);
			}
			printf("\n");
			for(i=0;i<=rear;++i)
			{
				printf("%d\t",cqueue[i]);
			}
			printf("\n");
		}
	}
}