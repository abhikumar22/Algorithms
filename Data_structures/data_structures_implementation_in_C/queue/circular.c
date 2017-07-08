//a menu driven program for implementation of circular queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
char queue[SIZE];
void traverse();
void insert(char );
char delete();
int front=-1,rear=-1;
main()
{
	int i;
	char x,temp;
	printf("Queue implementation of SIZE 5\n");
	while(1)
	{
		printf("\n****************\n");
		printf("Queue operations\n");
		printf("1.INSERT\n");
		printf("2.DELETE\n");
		printf("3.TRAVERSE\n");
		printf("4.EXIT\n");
		printf("********************\n");
		printf("please!!!!!!!enter your choice\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("enter the element\n");
				scanf(" %c",&x);
				insert(x);
				break;
			case 2:
				temp=delete();
				if(temp!=-1)
					printf("deleted element is %c \n",temp);
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);

			default:
				printf("Error....please enter the Right Choice\n");
		}
	}
}

void insert(char x)
{
	if(((front==0)&&(rear==(SIZE-1)))||(rear==front-1))
		printf("QUEUE is full\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else
			rear=(rear+1)%SIZE;
		queue[rear]=x;
	}
}

char delete()
{
	char x;
	if(front==-1)
	{
		printf("**QUEUE is empty**\n");
		return -1;
	}
	else
	{
		x=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1);
		return x;
	}
}

void traverse()
{
	int i;
	if(front==-1)
		printf("**QUEUE is empty**\n");
	else
	{
		if(rear>=front)
			for(i=front;i<=rear;i++)
				printf("%c..",queue[i]);
		else
		{
			for(i=front;i<SIZE;i++)
				printf("%c\n",queue[i]);
			for(i=0;i<=rear;i++)
				printf("%c\n",queue[i]);
		}
	}
}
	
