//a menu driven program to perform the various operations on a single linked list
#include<stdio.h>
#include<stdlib.h>
void create(int);
void delete(int);
void traverse();
void insert(int,int);
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;
main()
{
	while(1)
	{
	int choice,d,position;
	printf("Single Linked List Operations\n");
	printf("1.Create\n2.Insert\n3.Delete\n4.Traverse\n5.EXIT\n");
	printf("Enter the Choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter the DATA\n");
		scanf("%d",&d);
		create(d);
		break;

		case 2:	
		printf("enter the Data\n");
		scanf("%d",&d);
		printf("enter the position\n");
		scanf("%d",&position);
		insert(d,position);
		break;

		case 3:
		printf("enter the position\n");
		scanf("%d",&position);
		delete(position);
		break;

		case 4:
		traverse();
		break;

		case 5:
		exit(1);
		break;
		
		default :
		printf("Please Provide the correct input !!ERROR\n");
		break;	
	}
	}
}

void create(int x)
{
	node *newnode,*temp;
	int n ,i ;

	newnode = ( node* )malloc( sizeof(node) ) ;
	newnode -> next = NULL;
	newnode -> data = x;
	if(head == NULL)
		head = newnode;
	else
	{
		temp = head;
		while(temp -> next)
			temp = temp -> next;
	 	temp -> next = newnode;
	} 
}


void traverse()
{
	node *temp;
	if(head == NULL)
		printf("the list is empty!! ERROR\n");
	else
	{
		temp = head;
		while(temp)
		{
			printf("%d\n",temp -> data);
			temp = temp -> next;
		}
	}
}

void insert(int x,int p)
{
	node *newnode,*temp;
	int i,po=1;
	newnode = ( node* )malloc( sizeof(node) );
	newnode -> data = x;
	newnode -> next = NULL;
	if(head == NULL )
		head = newnode;
	else if(p == 1)
	{
		newnode -> next = head;
		head = newnode;
	}
	else
	{
		temp = head;
		while(po != p-1)
		{
			temp = temp -> next;
			po+=1;
		}
		if(temp -> next == NULL)
		{
			temp -> next = newnode;
			newnode -> next = NULL;
		}
		else
		{
			newnode -> next = temp -> next;
			temp -> next = newnode;
		}
	}
}

void delete(int p)
{
	node *temp,*t;
	int i,po=1;
	if(p == 1 && head -> next == NULL)
	{
		temp =  head;
		head = head -> next;
		free(temp);
	}
	else if(p==1)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	else
	{
		temp = head;
		while(po != p-1)
		{
			temp = temp -> next;
			po=po+1;
		}
		t=temp->next;
		temp->next=temp->next->next;
		free(t);
			
	}
}
