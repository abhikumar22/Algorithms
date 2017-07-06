//implementation of prim algo
#include<stdio.h>
#define max 15
struct vertex 
{
	int no,key,pi,pres,qp;
}ver[max];


int parent(int i)
{
	return((i/2)+1);
}
int left(int i)
{
	return (2*i+1);
}
int right(int i)
{
	return((2*i)+2);
}
void buildheap()
{
	int i;

	heap_size=n;
	int x=n/2;
	for(i=x;i>=0;i--)
	{
		minheapify(i);
	}
}
void minheapify(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest;
	if(l<=heap_size && a[l]<a[i])
	{
		smallest=l;
	}
	else
	{
		smallest=i;
	}
	if(r<=heap_size && a[r]<a[smallest])
	{
		smallest=r;
	}
	if(smallest !=i)
	{
	
		swap(vertex,i,smallest);
		minheapify(smallest);
	}
}

int heap_extract_min()
{
	int max;
	if( heap_size[a]<1)
	{
		printf("error queue underflow\n");
	}
	max=a[1];
	a[1]=a[heap_size];
	heap_size=heap_size-1;
	maxheapify(1);
	return max;
}
void heap_decrease_key(int i,int j)
{
	if(key>a[i])

	a[i]=key;
	while(i>1 && a[parent(i)]<a[i]);
	{
		swap(a[parent(i)],a[i]);
		i=parent(i);
	}
}
void mst_prim(int w[max][max],int r)
{
	struct vertex q[max];
	int i;
	int u;
	for(i=0;i<heapsize;i++)
	{
		ver[i].key=9999;
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
		for(i=0;i<n;i++)
		{
			if(w[u][i]!=0)
			{
				if(ver[i].pres==1 && w[u][i] < ver[i].key)
				{	
					ver[i].pi=u;
					ver[i].key=w[u][i];
					heap_decrease_key(q,ver[i].qp,w[u][i]);
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
main()
{
	int i,j,w[max][max],root,totweight=0;
	printf("enter the no of vertices in the graph:");
	scanf("%d",&n);
	printf("enter the weighted matrix of the graph:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	printf("enter the root of the spanning tree to be found:");
	scanf("%d",&root);
	mst_prim(w,root);
	printf("the edges of the spanning tree are:\n");
	printf("EDGE\t COST\n");
	for(i=0;i<n;i++)
	{
		if(i==root)
			continue;
		printf("%d-------%d\t%d\n",ver[i].pi,ver[i].no,ver[i].key);
		totweight+=ver[i].key;
		printf("\n TOTAL weignt of spanning tree=%d",totweight);
	}
}




	
	

