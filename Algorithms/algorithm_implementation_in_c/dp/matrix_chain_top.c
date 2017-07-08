#include<stdio.h>
#include<stdlib.h>
int m[100][100],s[100][100];
int memoized_matrix_chain(int p[],int n);
int lookup_chain(int m[][100],int p[],int i,int j);
void print_optimal_paren(int s[][100],int i,int j);
main()
{
	int n,i;
	int p[10],t;

	printf("Enter the Number of matrices\n");
	scanf("%d",&n);

	printf("Enter the dimention of the array P \n");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
		
	t=memoized_matrix_chain(p,n);	
	printf("The Minimum No of Scalar Multiplication is= ");
	printf("%d\n",t);
	print_optimal_paren(s,1,n);
}
int lookup_chain(int m[][100],int p[],int i,int j)
{
	int k,q;
	if(m[i][j]<9999999)
		return m[i][j];
	if (i==j)
		m[i][j]=0;
	else
	{
		for(k=i;k<=j-1;k++)
		{
			q=lookup_chain(m,p,i,k)+lookup_chain(m,p,k+1,j)+p[i-1]*p[k]*p[j];
			if(q<m[i][j])
			{
				m[i][j]=q;
				s[i][j]=k;
			}
		}
	}
	return m[i][j];
}

			
	
int memoized_matrix_chain(int p[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			m[i][j]=9999999;
	return lookup_chain(m,p,1,n);
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







