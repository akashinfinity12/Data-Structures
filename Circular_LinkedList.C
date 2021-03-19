#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_bef(struct node *);
struct node *insert_aft(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_bef(struct node *);
struct node *delete_aft(struct node *);
struct node *delete_ll(struct node *);
struct node *deletesp(struct node *);
struct node *sorting(struct node *);
struct node *display(struct node *);
struct node *find(struct node *);

void main()
{
	clrscr();
	int op;
	do
	{
	printf("MAIN MENU\n");
	printf("1. Create a circular linked list\n");
	printf("2. Add the node at the beginning\n");
	printf("3. Add the node at the end\n");
	printf("4. Add the node before a given node\n");
	printf("5. Add the node after a given node\n");
	printf("6. Delete the node at the beginning\n");
	printf("7. Delete the node at the end\n");
	printf("8. Delete the node before a given node\n");
	printf("9. Delete the node after a given nod\n");
	printf("10. Delete the entire linked list\n");
	printf("11. Delete a specific node\n");
	printf("12. Sort the linked list\n");
	printf("13. Display the circular linked list\n");
	printf("14. Find a node\n");
	printf("15. Exit\n");
	printf("Enter any one option\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			start=create_ll(start);
			printf("CIRCULAR LINKED LIST CREATED\n");
			break;
		case 2:
			start=insert_beg(start);
			break;
		case 3:
			start=insert_end(start);
			break;
		case 4:
			start=insert_bef(start);
			break;
		case 5:
			start=insert_aft(start);
			break;
		case 6:
			start=delete_beg(start);
			break;
		case 7:
			start=delete_end(start);
			break;
		case 8:
			start=delete_bef(start);
			break;
		case 9:
			start=delete_aft(start);
			break;
		case 10:
			start=delete_ll(start);
			printf("CIRCULAR LINKED LIST DELETED\n");
			break;
		case 11:
			start=deletesp(start);
			break;
		case 12:
			start=sorting(start);
			break;
		case 13:
			start=display(start);
			break;
		case 14:
			start=find(start);
			break;
	}
	}while(op!=15);
	getch();
}

struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("Enter -1 to end\n");
	printf("Enter the value\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
			ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=start;
		}
	printf("Enter the data\n");
	scanf("%d",&num);
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter the element\n");
	scanf("%d",&num);
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	printf("Enter the element\n");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	return start;
}

struct node *insert_bef(struct node *start)
{
	struct node *ptr,*preptr,*new_node;
	int num,val;
	printf("Enter the element\n");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	printf("Enter the value before which node has to be inserted\n");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(start==ptr)
	{
		start=new_node;
		new_node->next=ptr;
	}
	else
	{
		preptr->next=new_node;
		new_node->next=ptr;
	}
	return start;
}

struct node *insert_aft(struct node *start)
{
	int num,val;
	struct node *ptr,*preptr,*new_node;
	printf("Enter the element\n");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	printf("Enter the value after which the node has to be inserted\n");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}
struct node *deletesp(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("Enter the value of element you want to delete\n");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	printf("Deleted element is %d\n",ptr->data);
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *delete_bef(struct node *start)
{
	struct node *ptr,*preptr,*postptr;
	int val;
	printf("Enter the value before which the node has to be deleted\n");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	postptr=ptr->next;
	while(postptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
		postptr=ptr->next;
	}
	preptr->next=postptr;
	free(ptr);
	return start;
}

struct node *delete_aft(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("Enter the value after which the node has to be deleted\n");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("Value is %d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("Value is %d\n",ptr->data);
	return start;
}

struct node *sorting(struct node *start)
{
	struct node *ptr1,*ptr2;
	ptr1=start;
	int temp;
	while(ptr1->next!=start)
	{
		ptr2=ptr1->next;
		while(ptr2!=start)
		{
			if((ptr1->data)>(ptr2->data))
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return start;
}

struct node *delete_ll(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		start=delete_end(start);
	}
	free(start);
    return start;
}

struct node *find(struct node *start)
{
	int val,pos=0;
	struct node *ptr;
	printf("Enter the element you want to find\n");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
		pos++;
	}
	printf("The position of the required node is %d\n",pos);
	return start;
}