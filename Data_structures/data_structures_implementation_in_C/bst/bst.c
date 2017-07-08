#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *lc,*rc;
	int data;
}node;

node *insert(node *t,int x)
{
	if(t==NULL)
	{
		t=(node*)malloc(sizeof(node));
		t->data=x;
		t->lc=t->rc=NULL;
	}
	else if(t->data>x)
		t->lc=insert(t->lc,x);
	else if(t->data<x)
		t->rc=insert(t->rc,x);
	else
	{
		printf("Dublicate Data\n");
	}
	return t;
}

/*node *delete(node *t,char x)
{
	if(t==NULL)
		printf("\nthe tree is empty");
	else if(t->data>x)
		t->lc=delete(t->lc,x);
	else if(t->data<x)
		t->rc=delete(t->rc,x);
	else if(t->lc!=NULL&&t->rc!=NULL)
	{
		node *delnode;
		delnode=max(t->lc);
		t->data=delnode->data;
		t->lc=delete(t->lc,delnode->data);
	}
	else
	{
		node *delnode=t;
		if(t->lc==NULL)
			t=t->rc;
		else
			t=t->lc;
		free(delnode);
	}
	return t;
}*/
/*void traverse_inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->lc);
		printf("%c",t->data);
		inorder(t->rc);
	}
}*/
node *max(node *t)
{
	while(t->rc!=NULL)
	{
		t=max(t->rc);
	}
	return(t);
}

void main()
{
	int ch,i,num,numb,n;
	node *root,*new;
	while(1)
	{
		printf("*****************\n");
		printf("Operations on Binary Search Tree\n");		
		printf("1.insert\n2.traverse\n3.delete\n4.search\n5.No.of Leaf NODE\n6.Height\n7.exit");
		printf("please enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the no. of nodes you want\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("enter the data\n");
					scanf("%d",&num);
					insert(root,num);
				}
				break;
			case 2:
			//	traverse_inorder(root);
				break;
			case 3:
				printf("enter the data you want to delete\n");
				scanf("%d",&numb);
				//delete(root,numb);
			case 7:
				exit(1);
		}
	}
}



