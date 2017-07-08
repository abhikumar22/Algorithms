#include<stdio.h>
#include<stdlib.h>
int m[100][100],s[100][100];
void mat_chain_order(int [],int);
void print_optimal_paren(int [][100],int,int);
main()
{
	int n,i;
	int p[10];

	printf("Enter the Number of matrices\n");
	scanf("%d",&n);

	printf("Enter the dimention of the array P \n");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
		
	mat_chain_order(p,n);
	printf("\nThe optimal parenthesized solution is:: \n");
	print_optimal_paren(s,1,n);
	printf("\n\n");
}
void mat_chain_order(int p[],int x)
{
	int n,i,l,j,k,q;
	n=x;
	
	for(i=1;i<=n;i++)
		m[i][i]=0;

	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			m[i][j]=99999; //initializing by infinity

			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void print_optimal_paren(int s[][100],int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		print_optimal_paren(s,i,s[i][j]);
		print_optimal_paren(s,s[i][j]+1,j);
		printf(")");
	}
}







