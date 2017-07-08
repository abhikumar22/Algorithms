//a c program for implementation of stack using arrays
#include<stdlib.h>
#include<stdio.h>
# define SIZE 100

int stack[SIZE];
int top=-1;
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
void push(int c)
{
	if(top==SIZE-1)
		printf("OVERFLOW!!stack is full\n");
	else
		stack[++top]=c;
}

int pop()
{
	int temp;
	if(top==-1)
	{
		printf("UNDERFLOW!!stack is empty \n");
		return -1;
	}
	else
	{
		temp=stack[top];
		top=top-1;
		return(temp);
	}
}

void traverse()
{
	int i=top;
	if(top==-1)
		printf("ERROR!! Stackis empty\n");
	else
	{
		while(i>=0)
		{
			printf("%d\n",stack[i]);
			i--;
		}
	}
}



