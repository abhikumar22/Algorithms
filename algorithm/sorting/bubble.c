#include<stdio.h>
void input(int [],int);
void bubble_sort(int [],int n);
void output(int [],int);
int a[100],n,u,m;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
main()
{
	int n;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	input(a,n);
	bubble_sort(a,n);
	output(a,n);
}
void input(int a[],int n)
{
	int i=1;
	printf("enter the elements of the array\n");
	while(i<=n)
	{
		scanf("%d",&a[i]);
		i++;
	}
}
void bubble_sort(int a[],int n)
{
	int i,j,swapped;
	for(i=1;i<=n;i++)
	{
		swapped=0;
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swapped=1;
			}
		}
		if(swapped==0)
			break;
	}
}
void output(int a[],int n)
{
	int i;
	printf("the elements of the array after sorting is...\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
}

