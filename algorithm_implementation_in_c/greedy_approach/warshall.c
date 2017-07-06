#include<stdio.h>
#define SIZE 5
int min(int,int);
int d[10][10];
int p[10][10];
void warshall(int[][10],int);
main()
{
	int i,j,n;
	printf("Enter the size\n");
	scanf("%d",&n);
	int w[n][n];
	printf("Enter the Weighted matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&w[i][j]);

	printf("Enter the Parent Matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d\n",&p[i][j]);

	/*
	={          0,    3,    8,   9999,   -4,
		       	    9999,    0, 9999,      1,    7,
		            9999,    4,    0,   9999, 9999,
		               2,    5,   -5,      0,   -2,
		            9999, 9999, 9999,      6,    0};


	int p[5][5]={          0,    1,    1,      0,    1,
		       	       0,    0,    0,      2,    2,
		               0,    3,    0,      0,    0,
		               4,    0,    4,      0,    0,
		               4,    0,    0,      5,    0};
	*/
	warshall(w,n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",p[i][j]);
		}
		printf("\n");
	}
}
void warshall(int w[][10],int n)
{
	int i,j,k,m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j]=w[i][j];

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				m=d[i][j];
				d[i][j]=min(d[i][j],(d[i][k]+d[k][j]));
					if(m<d[i][j])
						p[i][j]+=1;
			}
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}




	
