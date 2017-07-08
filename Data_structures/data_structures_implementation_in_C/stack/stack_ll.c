//a program to implement stack using single linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;

void push(int);
int pop();
void traverse();

main()
{
	int ch,x,t;
	while(1)
	{
		printf("STACK OPERATIONS...\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.traverse\n");
		printf("4.exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element\n");
				scanf("%d",&x);
				push(x);
				break;

			case 2:
				t=pop();
				if(t!=-1)
					printf("poped element is [%d]\n",t);
				break;

			case 3:
				traverse();
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("error!!!wrong choice\n");
				break;
		}
	}
}
void push(int item)
{
	node *p=(node *)malloc(sizeof(node));
	if(p==NULL)
		printf("Error!!Malloc\n");
	else
	{
		p->data=item;
		p->next=NULL;
		p->next=head;
		head=p;
	}
}

int pop()
{
	int d;
	node *p,*temp;
	if(head==NULL)
	{
		printf("Error!!Underflow\n");
		return -1;
	}
	else
	{
		d=head->data;
		p=head;
		head=head->next;
		free(p);
		return(d);
	}
}

void traverse()
{
	node *temp;
	int i=1;
	temp=head;
	if(!temp)
		printf("ERROR!! Stack is empty\n");
	else
	{
		printf("Stack\n");
		while(temp)
		{
			printf(" %d\n",temp->data);
			temp=temp->next;	
		}

	}
}
