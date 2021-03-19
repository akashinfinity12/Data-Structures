#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	struct node *next;
	int data;
};

struct queue
{
	struct node *rear;
	struct node *front;
};

struct queue *q;
struct queue *einsert(struct queue *,int);
struct queue *edelete(struct queue *);
struct queue *display(struct queue *);
void create(struct queue *);
int peek(struct queue *);

void main()
{
	clrscr();
	create(q);
	int val,op;
	do
	{
		printf("MAIN MENU\n");
		printf("1. Insert Element\n");
		printf("2. Delete Element\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter any one option\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the element to be inserted on linked queue\n");
				scanf("%d",&val);
				q=einsert(q,val);
				break;
			case 2:
				q=edelete(q);
				break;
			case 3:
				val=peek(q);
				printf("Topmost Element:%d\n",val);
				break;
			case 4:
				q=display(q);
				break;
		}
	}while(op!=5);
	getch();
}

void create(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}

struct queue *einsert(struct queue *q,int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next = q->rear->next = NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}

struct queue *edelete(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
		printf("No elements in the linked queue\n");
	else
	{
		printf("Element deleted:%d\n",q->front->data);
		q->front=q->front->next;
		free(ptr);
	}
	return q;
}

struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
		printf("No elements in the linked queue\n");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
	return q;
}

int peek(struct queue *q)
{
	if(q->front==NULL)
		printf("No elements in the linked queue\n");
	else
	{
		return q->front->data;
	}
}