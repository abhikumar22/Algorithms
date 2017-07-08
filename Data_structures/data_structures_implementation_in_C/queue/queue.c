//a menu driven program for linear queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void insert(int x);
int delete();
void traverse();
main()
{
	int i,x,temp;
	while(2)
	{
		printf("\n****************\n");
		printf("1.Insert\n");
		printf("2.Deletion\n");
		printf("3.Traverse\n");
		printf("4.Exit\n");
		printf("********************\n");
		printf("Please!!!!!!!enter your choice\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				temp=delete();
				if(temp!=-1)
					printf("deleted element is --%d--\n",temp);
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("ERROR!! Choose the correct option\n");
		}
	}
}

void insert(int x)
{
	if(rear==SIZE-1)
		printf("**QUEUE is full**\n");
	else
	{
		if(rear==-1)
			front=rear=0;
		else
			rear++;
		queue[rear]=x;
	}
}

int delete()
{
	if((front==-1)||(front==rear+1))
	{
		printf("**QUEUE is empty**\n");
		return (-1);
	}
	else
		return(queue[front++]);
}

void traverse()
{
	int i;
	if((front==-1)||(front==rear+1))
		printf("**QUEUE is empty**\n");
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
				




