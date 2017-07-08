#include<stdio.h>
#define MAX 10
int nv;
struct vertex
{
	char color;
	int d, pi;
}v[MAX];
int q[MAX];
int rear=-1;
int front=0;
void bfs(int g[8][8],int);
void printpath(int ,int);
void enqueue(int);
int dequeue();
main()
{
	int g[][8]={0,1,0,0,1,0,0,0,
		1,0,0,0,0,1,0,0,
		0,0,0,1,0,1,0,0,
		0,0,1,0,0,0,1,1,
		1,0,0,0,0,0,0,0,
		0,1,1,0,0,0,1,0,
		0,0,0,1,0,1,0,1,
		0,0,0,1,0,0,1,0};
	int s,i,j,end;
	printf("enter no. of vertices\n");
	scanf("%d",&nv);
	printf("enter the starting vertex:\n");
	scanf("%d",&s);
	bfs(g,s);
	for(i=0;i<nv;i++)
		printf("%d:%d\t",i,v[i].pi);
	printf("\nenter the destination vertex:\n");
	scanf("%d",&end);
	printf("\nPATH:\n");
	printpath(s,end);
	printf("\n");
}
void printpath(int s,int p)
{
	if(s==p)
		printf("%d",s);
	else 
	{
		if(v[p].pi==-1)
			printf("no path from %d to %d\n:",s,p);
		else
		{
			printpath(s,v[p].pi);
			printf("--->%d",p);
		}
			
	}
}
void enqueue(int a)
{
	if(rear==-1)
	{
		q[0]=a;
		rear=front=0;
	}
	else if(rear==MAX-1)
		printf("overflow:\n");
	else
	{
		rear=rear+1;
		q[rear]=a;
	}

}
int dequeue()
{
	if(front==-1 || front==rear+1)
		printf("queue is full\n");

	else if(rear==0)
	{
		front=rear=-1;
		return q[rear+1];
	}
	else if(front==rear)
	{
		int s=rear;
		rear=front=-1;
		return q[s];
	}
	else
	{	front++;
		return q[front-1];
	}
}
void bfs(int g[][8],int s)
{
	int i,u;
	for(i=0;i<=nv;i++)
	{
		if(i==s)
			continue;
		v[i].color='w';
		v[i].d=99999;
		v[i].pi=-1;
	}
	v[s].color='g';
	v[s].d=0;
	v[s].pi=-1;
	enqueue(s);
	while(rear!=-1)
	{
		u=dequeue();
		for(i=0;i<=nv;i++)
		{
			if(g[u][i]==1)
			{
				if(v[i].color=='w')
				{
					v[i].color='g';
					v[i].d=v[u].d+1;
					v[i].pi=u;
					enqueue(i);
				}
			}
		}
		v[u].color='b';
	}
}
