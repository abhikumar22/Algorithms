// a program to find no. of times the inner and outer loop are executing in insertion sort algorithm
#include<stdio.h>
void counting_sort(int [],int[],int,int);
void output(int [],int);
int a[100],b[100],n;
main()
{
	int i=1,k;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the Range of numbers\n");
	scanf("%d",&k);
	printf("enter the elements of the array\n");
	while(i<=n)
	{
		scanf("%d",&a[i]);
		i++;
	}
	counting_sort(a,b,k,n);
	output(b,n);
}

void counting_sort(int a[],int b[],int k,int n)
{
	int i,j,c[k];
	for(i=1;i<=k;i++)
		c[i]=0;
	
	for(j=1;j<=n;j++)
		c[a[j]]=c[a[j]]+1;
	
	for(i=2;i<=k;i++)
		c[i]=c[i-1]+c[i];

	for(j=n;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
}
void output(int b[],int n)
{
	int i;
	printf("the elements of the array after sorting is...\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",b[i]);
	}
	printf("\n");
}

