//a program to convert infix expression to postfix expression and to evaluate the result
#include<string.h>
#include<stdio.h>
# define SIZE 15
char stack[SIZE];
int top=-1;
void push(char);
char pop();
int precedence(char);
void conversion(char *,char *);
int evaluation(char *postfix);
main()
{
	char infix[30],postfix[30],result;
	printf("enter the INFIX EXPRESSION\n");
	scanf(" %s",infix);
	conversion(infix,postfix);
	printf("the POSTFIX EXPRESSION is %s\n",postfix);
	top=-1;
	result=evaluation(postfix);
	printf("After the evaluation the result is %d \n",result);
		
}
void push(char c)
{
	if(top==SIZE-1)
		printf("stack is full\n");
	else
	{
		top=top+1;
		stack[top]=c;
	}
}

char pop()
{
	if(top==-1)
		printf("stack is empty\n");
	else
	{
		return(stack[top--]);
	}
}
int precedence(char ch)
{
	switch(ch)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
	}
}

void conversion(char *infix,char *postfix)
{
	int i=0,j=0,len=0;
	char ch;
	len=strlen(infix);
	infix[len]=')';
	infix[len+1]='\0';
	push('(');
	
	while(infix[i]!='\0')
	{
		ch=infix[i];
		switch(ch)
		{
			case '(':
				push('(');
				break;
			case ')':
			while(stack[top]!='(')
				postfix[j++]=pop();
				pop();//for popping (
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
			while(precedence(stack[top])>=precedence(ch))
				postfix[j++]=pop();
				push(ch);
				break;
			default:
			postfix[j++]=ch;
		}
		i++;
	}
	postfix[j]='\0';
}

int evaluation(char *postfix)
{
	int i=0,v1,v2,res;
	char ch;
	
	while(postfix[i]!='\0')
	{
		ch=postfix[i];
		switch(ch)
		{
			case '+':
				v1=pop();
				printf("v1=%d\n",v1);
				v2=pop();
				printf("v1=%d\n",v1);
				res=v1+v2;
				printf("res.%d\n",res);
				push(res);
				break;
			case '-':
				v1=pop();
				v2=pop();
				res=v1-v2;
				push(res);
				break;
			case '*':
				v1=pop();
				printf("v1=%d\n",v1);
				v2=pop();
				printf("v1=%d\n",v1);
				res=v1*v2;
				printf("res*.%d\n",res);
				push(res);
				break;
			case '/':	
				v1=pop();
				v2=pop();
				res=v1/v2;
				push(res);
				break;
			case '^':
				v1=pop();
				v2=pop();
				res=v1^v2;
				push(res);
				break;
			case '%':
				v1=pop();
				v2=pop();
				res=v1%v2;
				push(res);
				break;
			default:
			        push(ch);
				break;
		}
		i++;
	}
	printf("top=%d\n",top);
	return(stack[top]);
}
