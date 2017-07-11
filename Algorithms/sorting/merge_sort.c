#include<stdio.h>
void merge(int [],int,int,int);
void merge_sort(int[],int,int);
void display(int [],int);
main()
{
	int a[100],n,i;
	printf("Enter the No. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,1,n);
	display(a,n);
}

void merge_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)

{
	int i,j,k,n1,n2;
	n1=q-p+1;
	n2=r-q;
	int L[n1],R[n2];
	
	for(i=1;i<=n1;i++)
		L[i]=a[p+i-1];
	
	for(j=1;j<=n2;j++)
		R[j]=a[q+j];

	L[n1+1]=9999999;//initializing with infinity
	R[n2+1]=9999999;//initializing with infinity
	i=j=1;
	
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i+=1;
		}
		else
		{
			a[k]=R[j];
			j+=1;
		}
	}
}
void display(int a[],int n)
{
	int i;
	printf("the elements in the array after sorting is\n");
       	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
}


