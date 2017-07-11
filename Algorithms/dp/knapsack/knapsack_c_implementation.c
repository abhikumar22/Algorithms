#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int t[MAX][MAX],b[MAX][MAX],w[MAX],p[MAX];
void print_selected(int c,int n)
{
	if(c==0 || n==0)
		return;
	else if(b[c][n]==1)
	{
		print_selected(c-1,n-w[c]);
		printf("ITEM[%d]\t",c);
	}
	else
		print_selected(c-1,n);
}
void knapsack(int c,int n,int p[],int w[])
{
	int i,j;
	for(i=0;i<=c;i++)
		t[0][i]=0;
	for(i=1;i<=n;i++)
	{
		t[i][0]=0;	
		for(j=1;j<=c;j++)
		{
			if((w[i]<=j)&&(t[i-1][j-w[i]]+p[i])>t[i][j])
			{
				t[i][j]=t[i-1][j-w[i]]+p[i];
				b[i][j]=1;
			}
			else
			{
				t[i][j]=t[i-1][j];
				b[i][j]=0;
			}

		}
	}
	printf("\n***************\n");
	printf("TOTAL PROFIT=%d\n",t[n][c]);
}

main()
{
	int n,c,i,j;
	printf("Enter the total capacity of the knapsack\n");
	scanf("%d",&c);
	printf("Enter the number of items\n");
	scanf("%d",&n);
	printf("Enter weight of each item\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Enter the profit in each item\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	knapsack(c,n,p,w);
	printf("Items in KNAPSACK are....\n");
	print_selected(n,c);
	printf("\n");
	printf("***************\n");
}



