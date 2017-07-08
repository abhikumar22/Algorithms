// a program to find no. of times the inner and outer loop are executing in insertion sort algorithm
#include<stdio.h>
void input();
void insertion_sort();
void output();
int a[100],n;
main()
{
	printf("enter the number of elements\n");
	scanf("%d",&n);
	input(a,n);
	insertion_sort(a,n);
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
void insertion_sort(int a[],int n)
{
	int i,j,key;
	for(j=2;j<=n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>0 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}

}
void output()
{
	int i;
	printf("the elements of the array after sorting is...\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}

