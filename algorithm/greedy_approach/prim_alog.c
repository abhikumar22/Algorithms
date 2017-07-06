#include<stdio.h>
#define max 15
struct vertex
{
	int no,key,pi,pres,qp;
}ver[max];
int n,heapsize=-1;
void mst_prim(int w[9][9],int);
void build_min_heap(struct vertex[]);
void min_heapify(struct vertex[],int);
int heap_extract_min(struct vertex[]);
void heap_decrease_key(struct vertex[],int,int);
int left(int);
int right(int);
int parent(int);
void swap(struct vertex[],int,int);
main()
{
	int i,j,root,totweight=0;
	int w[9][9]={0,4,0,0,0,0,0,8,0,
		 4,0,8,0,0,0,0,11,0,
		 0,8,0,7,0,4,0,0,2,
		 0,0,7,0,9,14,0,0,0,
		 0,0,0,9,0,10,0,0,0,
		 0,0,4,14,10,0,2,0,0,
		 0,0,0,0,0,2,0,1,6,
		 8,11,0,0,0,0,1,0,7,
		 0,0,2,0,0,0,6,7,0};
	printf("enter the no. of vertices in the graph...........\n");
	scanf("%d",&n);/*
	printf("enter the WEIGHTED MATRIX of the graph...........\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}*/
	printf("Enter the root of the SPANNING TREE to be formed....\n");
	scanf("%d",&root);
	mst_prim(w,root);
	printf("***Edges of the spanning tree are::\n");
	printf("EDGE\tCOST\t\n");
	for(i=0;i<n;i++)
	{
		if(i==root)
			continue;
		printf("%d---%d\t%d\n",ver[i].pi,ver[i].no,ver[i].key);
		totweight+=ver[i].key;
	}
	printf("\nTOTAL_WEIGHT of the spanning tree%d\n",totweight);
}
int left(int i)
{
	return ((2*i)+1);
}
int right(int i)
{
	return ((2*i)+2);
}
int parent(int i)
{
	return ((i/2)-1);
}
int heap_extract_min(struct vertex q[])
{
	int min;
	if(heapsize <1)
		return -1;
	min=q[0].no;
	ver[min].pres=0;
	swap(q,0,heapsize-1);
	heapsize--;
	min_heapify(q,0);
	return min;
}

void heap_decrease_key(struct vertex q[],int i,int k)
{
	if(k>q[i].key)
		return ;
	q[i].key=k;
	while(i>0 && q[parent(i)].key >q[i].key)
	{
		swap(q,i,parent(i));
		i=parent(i);
	}
}
	
void min_heapify(struct vertex q[],int i)
{

	int l,r,small;
	l=left(i);
	r=right(i);
	if(l<=heapsize-1 && q[l].key < q[i].key)
		small=l;
	else
		small=i;
	if(r<=heapsize-1 && q[r].key <q[small].key)
		small=r;
	if(small !=i)
	{
		swap(q,i,small);
		min_heapify(q,small);
	}
}
void build_min_heap(struct vertex q[])
{
	heapsize=n;
	int i;
	for(i=(n/2)-1;i>=0;i--)
		min_heapify(q,i);
}
void mst_prim(int w[9][9],int r)
{
	struct vertex q[max];
	int i,u,v;
	for(i=0;i<n;i++)
	{
		ver[i].key=1000;
		ver[i].pi=-1;
		ver[i].pres=1;
		ver[i].no=i;
	}
	ver[r].key=0;
	for(i=0;i<n;i++)
	{
		q[i]=ver[i];
	}
	build_min_heap(q);
	while(heapsize>0)
	{
		u=heap_extract_min(q);
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0)
			{
				if(ver[v].pres==1 && w[u][v] < ver[v].key)
				{	
					ver[v].pi=u;
					ver[v].key=w[u][v];
					heap_decrease_key(q,ver[v].qp,w[u][v]);
				}
			}
		}
	}

}
void swap(struct vertex a[],int i,int j)
{
	struct vertex temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	ver[a[i].no].qp=i;
	ver[a[j].no].qp=j;
}



			


