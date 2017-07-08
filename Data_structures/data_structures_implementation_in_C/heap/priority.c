#include<stdio.h>
#include<stdlib.h>
void heapsort(int [],int);
void max_heapify(int [],int,int);
void build_max_heap(int [],int);
//int heap_maximum();
int heap_extract_max(int [],int);
void heap_increase_key(int [],int,int);	
int max_heap_insert(int a[],int heapsize,int key);
int parent(int);
int right(int i);
int left(int i);
void display(int a[],int n);
int heapsize,n;
exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int i,ch,key,temp,pos,n;
	printf("enter the value for n\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("before sorting the array is \n");
	heapsize=n;
	while(1)
	{
		printf("\n");	
		printf("1.MAXHEAP\n2.Extract_Max\n3.Increase_key\n4.Insert\n5.Sort\n6.Display\n7.Exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		
			case 1:
				build_max_heap(a,heapsize);
				break;
			case 2:
				temp=heap_extract_max(a,heapsize);
				if(temp!=-1)
					printf("Extracted Max value=%d\n",temp);
				break;
			case 3:
				printf("Enter the increased Value\n");	
				scanf("%d",&temp);
				printf("Enter the position\n");
				scanf("%d",&pos);
				heap_increase_key(a,pos,temp);	
				break;
			case 4:
				printf("Enter the Element to be inserted\n");
				scanf("%d",&temp);
				max_heap_insert(a,heapsize,temp);
				break;
			case 5:
				heapsort(a,heapsize);
				display(a,heapsize);
				break;
			case 6:
				display(a,heapsize);
				break;	
			case 7:
				exit(1);
				break;
		}
	}
}
void display(int a[],int n)
{
	int i;
	printf("After Sorting\n");
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
}
int left(int i)
{
	return (2*i);
}
int right(int i)
{
	return((2*i)+1);
}
int parent (int i)
{
	return(i/2);
}
void heapsort(int a[],int n)
{
	int i,temp;
	build_max_heap(a,n);
	for(i=n;i>=2;i--)
	{
		exchange(&a[1],&a[i]);
		//temp=a[1];
		//a[1]=a[i];
		//a[1]=temp;
		heapsize-=1;
		max_heapify(a,heapsize,1);
	}
}
void build_max_heap(int a[],int n)
{
	int i;
	for(i=(n/2);i>=1;i--)
		max_heapify(a,n,i);
}
void max_heapify(int a[],int n,int i)
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
		max_heapify(a,n,largest);
	}
}
int heap_maximum(int a[])
{
	return a[1];
}
int heap_extract_max(int a[],int n)
{
	int max;
	if(a[heapsize]<1)
	{
		printf("heap underflow\n");
		return -1;
	}
	else
	{
		max=a[1];
		a[1]=a[heapsize];
		heapsize-=1;
		max_heapify(a,heapsize,1);
		return max;
	}
}

void heap_increase_key(int a[],int i,int key)
{
	if(key<a[i])
		printf("new key is smaller than the current key\n");
	else
	{

		a[i]=key;
		while(i>1 && a[parent(i)]<a[i]);
		{
			exchange(&a[parent(i)],&a[i]);
			i=parent(i);
		}
	}
}
int max_heap_insert(int a[],int heapsize,int key)
{
	heapsize=heapsize+1;
	a[heapsize]=-999999;
	heap_increase_key(a,heapsize,key);
}



