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
int heapsize=-1;
int length=100;
int left(int);
int right(int);
int parent(int);
void swap(struct item *,struct item *);
void insert (struct item[],int,struct node *);
struct node *heap_extract_min(struct item[]);
void heap_decrease_key(struct item[],int);
void min_heapify(struct item *,int);
void huffman_codes(struct node *,int [],int);
int main()
{
	int n,i,arr[length];
	struct item q[length];
	struct node *root,*x,*y,*z,*temp;
	printf("enter no. of characters:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	
		temp=(struct node *)malloc(sizeof(struct node));
		printf("enter character:\n");
		scanf("%c",&(temp->c));
		printf("enter frequency:\n");
		scanf("%d",&(temp->freq));
		q[i].key=temp->freq;
		q[i].add=temp;
		temp->left=NULL;
		temp->right=NULL;
		
	}
	for(i=1;i<n;i++)
	{
		z=(struct node *)malloc(sizeof(struct node));
		x=heap_extract_min(q);
		y=heap_extract_min(q);
		z->left=x;
		z->right=y;
		z->freq=x->freq+y->freq;
		insert(q,z->freq,z);
	}
	root=heap_extract_min(q);
	huffman_codes(root,arr,0);
	return 0;
}
void swap(struct item *x,struct item *y)
{
	struct item *p;
	p=(struct item *)malloc(sizeof(struct item));
	p->key=x->key;
	x->key=y->key;
	y->key=p->key;
	p->add=x->add;
	x->add=y->add;
	y->add=p->add;
}
int left(int i)
{
	return (2*i+1);
}
int right(int i)
{
	return (2*i+2);
}
int parent(int i)
{
	return (i/2);
}
void huffman_codes(struct node *r,int arr[],int d)
{
	int i;
	if(r->left==NULL && r->right==NULL)
	{
		printf("\ncode of %c:",r->c);
		for(i=0;i<d;i++)
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
void insert(struct item q[],int k,struct node *a)
{
	heapsize++;
	q[heapsize].key=99999;
	q[heapsize].add=a;
	heap_decrease_key(a,heapsize,key);
}
struct node *heap_extract_min(struct item a[])
{
	struct item temp;
	if(heapsize<1)
		return NULL;
	temp=a[1];
	a[1]=a[heapsize];
	heapsize=heapsize-1;
	min_heapify(a,1);
	return temp.add;
}

}
void min_heapify(struct item *p,int i)
{

	int l,r,s;
	struct item *temp,*p2,*p1;
	l=left(i);
	r=right(i);
	if(l<=heapsize && (p+1)->key<(p+i)->key)
		s=l;
	else
		s=i;
	if(r<=heapsize && (p+r)->key<s)
		s=r;
	if(s!=i)
	{
		temp=(p+s);
		p2=(p+s);
		p2=(p+i);
		p1=(p+i);
		p1=temp;
		min_heapify(p,s);
	}
}
void heap_decrease_key(struct item a[],int i)
{
	struct item temp;
	if(k>a[i].key)
	{
		printf("\n new key greater than current key:\n");
		return;
	}
	a[i].key=k;
	while(i>1 && a[parent(i)].key>a[i].key)
	{
		temp=a[parent(i)];
		a[parent(i)]=a[i];
		a[i]=temp;
		i=parent(i);
	}
}

}



	

