#include<stdio.h>
#define MAX 100
void bubble_sort(int [],int [],float [],int);
void greedy_knapsack(int [],int [],float [],int,int,float);
void swap_f(float *,float *);
void swap(int *,int *);
main()
{
	int n,i,m;
	float tp=0.0;
	printf("Enter the no of items in the knapsack\n");
	scanf("%d",&n);
	printf("Enter the total weight of the knapsack\n");
	scanf("%d",&m);
	int p[n],w[n];
	float pw[n];
	printf("Enter the weight of the items\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("ENTER THE Profit of the items\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	greedy_knapsack(p,w,pw,n,m,tp);
}


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swap_f(float *a,float *b)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubble_sort(int p[],int w[],float pw[],int n)
{
	int i,j,swapped;
	for(i=1;i<=n;i++)
	{
		swapped=0;
		for(j=1;j<=n-i;j++)
		{
			if(pw[j]<pw[j+1])
			{
				swap_f(&pw[j],&pw[j+1]);
				swap(&p[j],&p[j+1]);
				swap(&w[j],&w[j+1]);
				swapped=1;
			}
		}
		if(swapped==0)
			break;
	}	
}

void greedy_knapsack(int p[],int w[],float pw[],int n,int m,float tp)
{
	int i;
	for(i=1;i<=n;i++)
		pw[i]=((float)p[i]/(float)w[i]);

	bubble_sort(p,w,pw,n);
	
	for(i=1;i<=n;i++)
	{
		if(m>0 && w[i]<=m)
		{
			m=m-w[i];
			tp=tp+p[i];
		}
		else
			break;
	}
	if(m>0)
		tp+=((float)p[i]*((float)m/(float)w[i]));
	printf("Total Profit=%f\n",tp);
}
