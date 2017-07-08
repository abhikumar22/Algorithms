#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *left,*right;
	int data;
}node;
node *root=NULL;
void preorder(node *);
void insert(int ,node*);
main()
{		
	int n,num,i,ch,d;
	node *temp;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the data\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&num);
		insert(num,root);
	}
	printf("the preorder=\n");
	preorder(root);
}
void preorder(node *t)
{
	if(t!=NULL)
	{
		printf("%d\n",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void insert(int x,node *t)
{
	//if(t==NULL)
	//{
	
	//}	
	if(x >( t -> data ))	
		insert(x,t->right);

	else if((x < t -> data))
			insert(x,t->left);
	else
	{
		node *new; 
		new=(node*)malloc(sizeof(node));
		new->data=x;
		new->left=NULL;
		new->right=NULL;
		t=new;
		printf("done\n");
	}
	//else 
	//	printf("Dublicate input Provided\n");
}
