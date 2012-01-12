#include<stdio.h>
#include<malloc.h>
/*Structure defintion*/
typedef struct tree
{
	int value;
	struct tree *lchild,*rchild;
}t;
struct queue
{
	int front,rear;
	struct tree *value[20];
};
/*Function declaration*/
t * insert(t *root,int value);
void traverse(t *root,struct queue *q);
void display(t *root);
void duplicate(t *root,t *root1);
int main()
{	//Creating root of tree
	t *root=NULL;
	t *root1;
	int ch,value;
	while(1)
	{//Prompting and accepting choice from user
		printf("--------------MENU-----------------\n");
		printf("1.Insert node\n");
		printf("2.Display tree\n");
		printf("3.Display mirror image of tree\n");
		printf("4.Exit.\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1://Case to insert node
					printf("Enter value of node:");
					scanf("%d",&value);
					root=insert(root,value);
					break;
			case 2://Case to display tree
					display(root);
					break;
			case 3://Case to display mirror image
					if(root!=NULL)
					{
						root1=(t*)malloc(sizeof(t));
						root1->value=root->value;
						duplicate(root,root1);
						printf("Mirror image of tree:\n");
						display(root1);
					}
					else
						printf("Tree doesnt exist.\n");
					break;
			case 4://Exit case
					return 0;
			default://Default case
					printf("Invalid choice.");
		}
	}
}
/*Function defintion*/
t * insert(t * root,int value)
{
	t *temp,*temp1;
	int flag=0;
	if(root==NULL)
	{//Creating root node
		root=(t *)malloc(sizeof(t));
		root->value=value;
		return(root);
	}
	else
	{//Creating child node
		temp=root;
		//Finding the location where to link new child
		while(1)
		{
			if(temp->value<value)
			{
				if(temp->rchild==NULL)
				{
					flag=1;
					break;
				}
				else
					temp=temp->rchild;
			}
			else if(temp->value>value)
			{
				if(temp->lchild==NULL)
				{
					flag=2;
					break;
				}
				else
					temp=temp->lchild;
			}
			else
			{
				flag=3;
				break;
			}
		}
		if(flag==1)
		{//Creating right child of temp
			temp1=(t *)malloc(sizeof(t));
			temp1->value=value;
			temp->rchild=temp1;
		}
		else if(flag==2)
		{//Creating left child of temp
			temp1=(t *)malloc(sizeof(t));
			temp1->value=value;
			temp->lchild=temp1;
		}
	}
	return(root);
}

void display(t *root)
{
	if(root==NULL)
	{//Null condition
		printf("Tree doesnt exist.\n");
		return;
	}
	//Displaying the tree levelwise
	printf("Tree is as above:\n");
	int level=0;
	t *p1,*p2;
	//Creating structure variable to store nodes in queue
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	printf("Level 0:\n");
	q->front=0;
	q->rear=0;
	p1=root;
	p2=root;
	q->value[q->front]=root;
	while(q->front!=-1 && q->rear!=-1)
	{
		printf("%d ",p1->value);
		if((q->value[q->front])->lchild!=NULL)
		{
			(q->rear)++;
			q->value[q->rear]=(q->value[q->front])->lchild;
		}
		if((q->value[q->front])->rchild!=NULL)
		{
			(q->rear)++;
			q->value[q->rear]=(q->value[q->front])->rchild;
		}
		if((p1->value)==(p2->value) && q->front!=q->rear)
		{
			level++;
			printf("\nLevel %d\n",level);
			p2=q->value[q->rear];
		}
		if(q->front==q->rear)
		{
			q->front=-1;
			q->rear=-1;
		}
		else
		{
			p1=q->value[q->front+1];
			(q->front)++;
		}
	}
	printf("\n");
}

void duplicate(t *root,t *root1)
{
	if(root->lchild!=NULL)
	{//Copying left child of nodes to right of other tree
		t *temp=(t*)malloc(sizeof(t));
		temp->value=(root->lchild)->value;
		root1->rchild=temp;
		duplicate(root->lchild,root1->rchild);
	}
	else
		root1->rchild=NULL;
	if(root->rchild!=NULL)
	{//Copying right child of nodes to left of other tree
		t *temp=(t*)malloc(sizeof(t));
		temp->value=(root->rchild)->value;
		root1->lchild=temp;
		duplicate(root->rchild,root1->lchild);
	}
	else
		root1->lchild=NULL;
}
