#include<stdio.h>
#include<stdlib.h>
#define max 5
struct vertex
{
	int d,pi,no;
}ver[max];
int heap_size=-1;
int n;
void dij(int [max][max],int);
void relax(int,int,int [][max]);
void int_sing_source(int [][max],int);
void min_heapify(struct vertex[],int);
int heap_extract_min(struct vertex[]);
void build_min_heap(struct vertex []);
void heap_decrease_key(struct vertex[],int,int);
int left(int);
int right(int);
int parent(int);
void swap(struct vertex[],int,int);
void print(int,int);
main()
{
	int s,i,end;
	int w[max][max]={9999,10,9999,5,9999,
			 9999,999,1,2,9999,
			 9999,999,999,9999,4,
			 9999,3,9,9999,2,
			 7,9999,6,9999,9999};
	printf("Enter the number of vertices you want\n");
	scanf("%d",&n);
	printf("Enter the starting vertex :");
	scanf("%d",&s);
	printf("Enter the end vertex :");
	scanf("%d",&end);
	dij(w,s);
	print(s,end);
}
void print(int s,int end)
{
	if(s==end)
		printf("%d--->",s);
	else if(ver[end].pi<0)
	{
		printf("\n no path from %d to %d\n",s,end);
		return;
	}
	else
	{
		print(s,ver[end].pi);
		printf("%d......",end);
	}
}
void dij(int w[][max],int s)
{
	struct vertex q[max];
	int u,v,i;
	int_sing_source(w,s);
	for(i=0;i<n;i++)
	{
		q[i].d=ver[i].d;
		q[i].pi=ver[i].pi;
		q[i].no=i;
	}
	build_min_heap(q);
	while(heap_size>0)
	{
		u=heap_extract_min(q);
		for(v=0;v<n;v++)
		{
			if(w[u][v]<90)
			{
				relax(u,v,w);
			}
		}
	}
}
void relax(int u,int v,int w[][max])
{
	if(ver[v].d>ver[u].d + w[u][v])
	{
		ver[v].d=ver[u].d+w[u][v];
		ver[v].pi=u;
	}
}
void int_sing_source(int w[][max],int s)
{
	int i;
	for(i=0;i<n;i++)
	{
		ver[i].d=9999;
		ver[i].pi=-1;
	}
	ver[s].d=0;
}
int heap_extract_min(struct vertex q[])
{
	int min;
	if(heap_size<1)
		return -1;
	min=q[0].no;
	swap(q,0,heap_size-1);
	heap_size--;
	min_heapify(q,0);
	return min;
}
void heap_decrease_key(struct vertex q[],int i,int k)
{
	if(k>q[i].d)
		return;

	q[i].d=k;
	while(i>0 && (q[parent(i)].d > q[i].d))
	{
		swap(q,i,parent(i));
		i=parent(i);
	}
}
void build_min_heap(struct vertex q[])
{
	int i,l;
	l=n;
	heap_size=n;
	for(i=(n/2)-1;i>=0;i--)
	{
		min_heapify(q,i);
	}
}
void min_heapify(struct vertex q[],int i)
{
	int l,r,sm;
	struct vertex temp;
	l=left(i);
	r=right(i);
	if(l<=heap_size-1  && q[1].d < q[i].d)
		sm=l;
	else
		sm=i;
	if(r<=heap_size-1 && q[r].d < q[sm].d)
		sm=r;
	if(sm!=i)
	{
		swap(q,i,sm);
		min_heapify(q,sm);
	}
}
int parent(int i)
{
	return(i-1)/2;
}
int left(int i)
{
	return(2*i+1);
}
int right(int i)
{
	return(i*2+2);
}
void swap(struct vertex q[],int i,int j)
{
	struct vertex temp;
	temp=q[i];
	q[i]=q[j];
	q[j]=temp;
}

