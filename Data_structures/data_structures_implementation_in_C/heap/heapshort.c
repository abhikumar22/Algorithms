#include<stdio.h>
void display(int [],int);
void heapsort(int [],int);
void heapify(int [],int,int);
void build_max_heap(int [],int);
int x,y;
exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
main()
{
	int n,i,a[100];
	printf("Enter the size you want\n");
	scanf("%d",&n);
	printf("Enter the element to the array\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n);
	display(a,n);

}
void display(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}
void heapsort(int a[],int n)
{
	int i,temp,heapsize;
	build_max_heap(a,n);
	heapsize=n;
	for(i=n;i>=2;i--)
	{
		exchange(&a[1],&a[i]);
		//temp=a[1];
		//a[1]=a[i];
		//a[1]=temp;
		heapsize-=1;
		heapify(a,heapsize,1);
	}
}
void build_max_heap(int a[],int n)
{
	int i;
	for(i=(n/2);i>=1;i--)
		heapify(a,n,i);
}
void heapify(int a[],int n,int i)
{
	int largest,l,r,temp;
	largest=i;
	l=(2*i);
	r=(2*i)+1;
	if(l<=n && a[l]>a[i])
		largest=l;
	//else
	//	largest=i;

	if(r<=n && a[r]>a[largest])
		largest=r;
	if(a[largest]!=a[i])
	{
		exchange(&a[largest],&a[i]);
		//temp=a[largest];
		//a[largest]=a[i];
		//a[i]=temp;
		heapify(a,n,largest);
	}
}

