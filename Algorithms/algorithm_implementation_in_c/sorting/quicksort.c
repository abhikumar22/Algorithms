#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void quickshort(int[],int,int);
int partition(int[],int,int);
exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int p,int r)
{
	int x,i,j;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=x)
		{
			i+=1;
			exchange(&a[i],&a[j]);
		}
	}
	exchange(&a[i+1],&a[r]);
	return i+1;
}

void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);	
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
void main()
{
	int a[MAX];
	int n,i;
	printf("enter the No. of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,1,n);
	printf("after sorting,elements of the given array are...\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
}


