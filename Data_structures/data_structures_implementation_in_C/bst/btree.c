#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *left,*right;
	int data;
}node;
//node *root=NULL;
void insert(int ,node*);
//void delete(int);
void inorder(node*);
void postorder(node*);
void preorder(node*);
int find_max(node*);
int find_min(node*);
int height(node*);
int full_nodes(node*);
int leaves(node*);
int nonleaves(node*);
int nodes(node*);
int cbt(node*);
int find_node(int x,node*);
main()
{		
	int n,num,i,ch,d,temp;
	node *root=NULL;
	//node *t;
	while(1)
	{
		//t=root;
		printf("\n**************************\n");
		printf("Binary Search Tree Operations\n");
		printf("1.Insert\n2.Delete\nTraverse-\n3.Preorder\n4.Inorder\n5.Postorder\n6.Find MAX\n7.Find MIN\n8.Height\n9.Find Full Nodes\n10.find No. of Leaves\n11.Find no. of non Leaves\n12.Count No. of Nodes\n13.Is Complete Btree\n14.find_node\n15.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number of nodes\n");
				scanf("%d",&n);
				printf("Enter the data\n");
				for(i=1;i<=n;i++)
				{
					scanf("%d",&num);
					insert(num,root);
				}
				break;
		
			case 2:
				printf("Enter the data to be Deleted\n");
				scanf("%d",&d);
				//delete(d);
				break;
	
			case 3:
				printf("Preorder Traversal is\n");
				preorder(root);
				break;
			case 4:
				printf("Inorder Traversal is\n");
				inorder(root);
				break;
			case 5:
				printf("Postorder Traversal is\n");
				postorder(root);
				break;
			case 6:
				temp=find_max(root);
				printf("Maximum is %d \n",temp);
				break;
			case 7:
				temp=find_min(root);
				printf("Minimum is %d \n",temp);
				break;
			case 8:
				printf("Height of the tree is %d \n",height(root));
				break;
			case 9:
				printf("No of Full Nodes is %d \n",fn(root));
				break;
			case 10:
				printf("No. of leaves is %d \n",leaves(root));
				break;
			case 11:
				printf("No of NON leaves is %d \n",nonleaves(root));
				break;
			case 12:
				printf("No. of Nodes is %d \n",nodes(root));
				break;
			case 13:
				if(temp=1)
					printf("Complete Binary Tree\n");
				else
					printf("Not a Complete Binary tree\n");
				break;
			case 14:
				printf("enter the element you want to search\n");
				scanf("%d",&n);
				temp=find_node(n,root);
				if(temp!=-1)
					printf("Data Present\n");
				break;
			case 15:
				exit(1);
				break;
			default:
				printf("ERROR!! Wrong input provided\n");
			
		}
	}
}
void insert(int x,node *temp)
{
	if(temp==NULL)
	{
		//node *newnode; 
		temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		//printf("add%d\n",newnode->data);
		//temp=newnode;
		//printf("%d",temp->data);
	}	
	else if(x > temp -> data )	
		insert(x,temp->right);

	else if((x < temp -> data))
		insert(x,temp->left);
	else 
		printf("Dublicate input Provided\n");
}
void preorder(node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\n",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\n",temp->data);
		inorder(temp->right);
	}
}

void postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\n",temp->data);
	}
}

int find_max(node *temp)
{
	if(temp!=NULL)
	{
		while(temp->right)
			temp=temp->right;
		return(temp->data);
	}
}

int find_min(node *temp)
{
	if(temp!=NULL)
	{
		while(temp->left)
			temp=temp->left;
		return (temp->data);
	}
}

int height(node *temp)
{
	int l,r;
	if(!temp)
		return(0);
	if(!(temp->left)&&(!(temp->right)))
		return(0);
	l=height(temp->left);
	r=height(temp->right);
	return(1+((l>r)?l:r));
}

int fn(node *temp)
{
	if(!temp)
		return(0);
	if(!(temp->left)&&(!(temp->right)))
		return(0);
	else return(fn(temp->left)+fn(temp->right)+(temp->left&&temp->right?1:0));
}

int leaves(node *temp)
{
	if(temp==NULL)
		return 0;
	else if(temp->left==NULL && temp->right==NULL)
		return 1;
	else
		return(leaves(temp->left)+leaves(temp->right));
}

int nonleaves(node *temp)
{
	if(temp==NULL)
		return 0;
	else if(temp->left==NULL && temp->right==NULL)
		return 0;
	else
		return(1+nonleaves(temp->left)+nonleaves(temp->right));
}

int nodes(node *temp)
{
	if(temp)
		return(1+nodes(temp->left)+nodes(temp->right));
	else 
		return 0;
}

int cbt(node *temp)
{
	if(temp==NULL)
		return 1;
	else if(!temp->left && !temp->right)
		return 1;
	else if(temp->left && temp->right)
		return(cbt(temp->left)&&cbt(temp->right));
	else
		return 0;
}

int find_node(int x,node *temp)
{
	if(x>temp->data)	
		return find_node(x,temp->right);
	else if(x<temp->data)
		return find_node(x,temp->left);
	else if(x==temp->data)
		return temp->data;
	else 
	{
		printf("Data Not found\n");
		return -1;
	}
}

/*void delete(int x)
{
	node *temp,*temp1;
	temp=root;
	temp1=find_node(x,temp);
	
	
	
}*/	
	
	





			
	
	
			
	
	
