//Implementation of HUFFMAN'S ALGORITHM
#include<stdio.h>
#include<stdlib.h>
struct node
{
	char c;
	int freq;
	struct node *left,*right;
};
struct item
{
	int key;
	struct node *add;
};
int heap_size=-1,length=100;
int left(int);
int right(int);
int parent(int);
void insert(struct item[],int,struct node*);
struct node * heap_extract_min(struct item[]);
void heap_decrease_key(struct item[],int,int);
void min_heapify(struct item *,int);
void huffman_codes(struct node *,int[],int);
main()
{
	int n,i,arr[length];
	struct item q[length];
	struct node *root,*x,*y,*z;
	printf("Enter the numbers of character you want:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the the character and freq:");
		scanf(" %c%d",&(temp->c),&(temp->freq));
		temp->left=NULL;
		temp->right=NULL;
		insert(q,temp->freq,temp);
	}
	for(i=1;i<=n;i++)
	{
		z=(struct node *)malloc(sizeof(struct node));
		x=heap_extract_min(q);
		z->left=x;
		y=heap_extract_min(q);
		z->right=y;
		z->freq=x->freq + y->freq;
		insert(q,z->freq,z);
	}
	root=heap_extract_min(q);
	huffman_codes(root,arr,1);
	printf("\n");
}
void huffman_codes(struct node *r,int arr[],int d)
{
	int i;
	if(r->left==NULL && r->right==NULL)
	{
		printf("\n code of %c :",r->c);
		for(i=1;i<=d;i++)
			printf("%d",arr[i]);
	}
	else
	{
		if(r->left!=NULL)
		{
			arr[d]=0;
			huffman_codes(r->left,arr,d+1);
		}
		if(r->right!=NULL)
		{
			arr[d]=1;
			huffman_codes(r->right,arr,d+1);
		}
	}
}
void insert(struct item q[],int key,struct node *a)
{
	heap_size=heap_size+1;
	q[heap_size].key=999999;
	q[heap_size].add=a;
	heap_decrease_key(q,heap_size,key);
}
struct node * heap_extract_min(struct item a[])
{
	struct node *temp;
	if(heap_size<0)
		exit(0);
	temp=a[1].add;
	a[1]=a[heap_size];
	heap_size=heap_size-1;
	min_heapify(a,1);
	return(temp);
}
void heap_decrease_key(struct item a[],int i,int k)
{
	struct item temp;
	if(k>a[i].key)
	{
		printf("greater\n");
		exit(0);
	}
	a[i].key=k;
	while(i>1 && (a[parent(i)].key > a[i].key))
	{
		temp=a[parent(i)];
		a[parent(i)]=a[i];
		a[i]=temp;
		i=parent(i);
	}
}
void min_heapify(struct item * p,int i)
{
	int l,r,smallest;
	struct item temp;
	l=left(i);
	r=right(i);
	if(l<=heap_size && ((p+1)->key < (p+i)->key))
		smallest=l;
	else
		smallest=i;
	if(r<=heap_size && ( (p+r)->key < (p+smallest)->key))
		smallest=r;
	if(smallest!=i)
	{
		temp=*(p+i);
		*(p+i)=*(p+smallest);
		*(p+smallest)=temp;
		min_heapify(p,smallest);
	}
}
int parent(int i)
{
	return(i)/2;
}
int left(int i)
{
	return(2*i);
}
int right(int i)
{
	return(i*2+1);
}
