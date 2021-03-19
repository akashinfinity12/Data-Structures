#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front=-1;
int rear=-1;
void einsert(int a);
int edelete(void);
int peek(void);
void display(void);

void main()
{
	clrscr();
	int op,n;
	do
	{
		printf("MAIN MENU\n");
		printf("1.Insert an element in queue\n");
		printf("2.Delete an element from queue\n");
		printf("3.Display top element of queue\n");
		printf("4.Display the entire queue\n");
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
				printf("The number deleted is %d\n",n);
				break;
			case 3:
				n=peek();
				if(n!=-1)
				printf("The topmost element is %d\n",n);
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
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=a;
	}
	else
	{
		rear++;
		queue[rear]=a;
	}
}

int edelete()
{
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	else
	{
		return queue[front++];
		if(front>rear)
			front=rear=-1;
	}
}

int peek()
{
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	else
	{
		return queue[front];
	}
}
void display()
{
	if(front==-1 || front>rear)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		for(int i=front;i<=rear;++i)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}