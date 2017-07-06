#include<stdio.h>
#include<string.h>
#define MAX 20
int b[MAX][MAX],c[MAX][MAX];
void lcs_length(char[],char[]);
void print_lcs(char[],int,int);

main()
{
	int i,j;
	char x[20],y[20];
	printf("ENTER THE 1ST SUBSEQUENCE\n");
	scanf("%s",x);
	printf("ENTER THE 2ND SUBSEQUENCE\n");
	scanf("%s",y);
	lcs_length(x,y);
	print_lcs(x,strlen(x),strlen(y));
	printf("\n");
}

void lcs_length(char x[],char y[])
{
	int i,j,m,n;
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else
			{
				 if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]=2;
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]=3;
				}
			}
		}
	}
	printf("LENGTH OF LCS:%d\n",c[m][n]);
	
}

void print_lcs(char x[],int i,int j)
{
	if(i==0 || j==0)
		return;
	else if(b[i][j]==1)
	{
		print_lcs(x,i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]==2)
		print_lcs(x,i-1,j);
	else
		print_lcs(x,i,j-1);
}


