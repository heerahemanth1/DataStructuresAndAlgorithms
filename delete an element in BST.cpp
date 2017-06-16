#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode
{
	struct tnode *leftc ;
	int data ;
	struct tnode *rightc ;
} ;

void insert ( struct tnode **, int ) ;
void deletes ( struct tnode **, int ) ;
void search ( struct tnode **, int, struct tnode **, struct tnode **, int * ) ;
void inorder ( struct tnode * ) ;

int main()
{
	struct tnode *bt ;
	int  b,n;
	printf("Binary Search Tree Implementation.\n\nChoice 1: Insert an element.\nChoice 2: Delete an element.\nChoice 3: Display.\n");
	printf("\nEnter your choice :\n");
	scanf("%d",&n);
	bt = NULL ;  /* empty tree */
	while((n==1)||(n==2)||(n==3))
	{
		switch ( n )
		{
			case 1:
			{
				printf("Enter the element to be inserted :\n");
				scanf("%d",&b);
				insert (&bt,b) ;
				break;
			}
			case 2:
			{
				printf("Enter the element to be deleted :\n");
				scanf("%d",&b);
				deletes( &bt, b ) ;
				break;
			}
			case 3:
			{
				if(bt==NULL)
				{
					printf("There are no elements in the BST.");
				}
				else
				{
					inorder ( bt ) ;
				}
				printf("\n");
				break;
			}
			default:
			{
				break;
			}
		}
		printf("Enter your choice :\n");
		scanf("%d",&n);
	}
	return 0;
}

/* inserts a new node in a binary search tree */
void insert ( struct tnode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr =(struct tnode*) malloc ( sizeof ( struct tnode ) ) ;

		( *sr ) -> leftc = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightc = NULL ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> leftc ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> rightc ), num ) ;
	}
}

/* deletes a node from the binary search tree */
void deletes ( struct tnode **root, int num )
{
	int found;
	struct tnode *parent,*x,*xsucc;
	/* if tree is empty */
	if ( *root == NULL )
	{
		printf ( "Tree is empty\n" ) ;
		return ;
	}
    parent=x=NULL;
	search ( root, num, &parent, &x, &found ) ;

	if(found==0)
	{
	    printf("Data to be deleted, not found\n");
	    return;
	}
	/*if the node to be deleted has two children*/
	if(x->leftc!=NULL && x->rightc!=NULL)
	{
	    parent=x;
	    xsucc=x->rightc;
	    while(xsucc->leftc!=NULL)
	    {
	        parent=xsucc;
	        xsucc=xsucc->leftc;
	    }
	    x->data=xsucc->data;
	    x=xsucc;
	}
	
	/* if the node to be deleted has no child */
	if(x->leftc==NULL && x->rightc==NULL)
	{
	    if(parent->rightc==x)
	    {
	        parent->rightc=NULL;
	    }
	    else
	    {
	        parent->leftc=NULL;
	    }
	    free(x);
	    return;
	}

	/* if the node to be deleted has only rightc */
	if(x->leftc==NULL && x->rightc!=NULL)
	{
	    if(parent->leftc==x)
	    {
	        parent->leftc=x->rightc;
	    }
	    else
	    {
	        parent->rightc=x->rightc;
	    }
	    free(x);
	    return;
	}
	/* if the node to be deleted has only left child */
	if(x->leftc!=NULL && x->rightc==NULL)
	{
	    if(parent->leftc==x)
	    {
	        parent->leftc=x->leftc;
	    }
	    else
	    {
	        parent->rightc=x->leftc;
	    }
	    free(x);
	    return;
	}
}

/*returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */
void search ( struct tnode **root, int num, struct tnode **par, struct tnode **x, int *found )  {
	struct tnode *q ;

	q = *root ;
	*found = 0 ;
	*par = NULL ;

	while ( q != NULL )
	{
		/* if the node to be deleted is found */
		if ( q -> data == num )
		{
			*found = 1 ;
			*x = q ;
			return ;
		}
		*par = q ;

		if ( q -> data > num )
			q = q -> leftc ;
		else
			q = q -> rightc ;
	}
}

void inorder ( struct tnode *sr ) {
    if(sr)
    {
        inorder(sr->leftc);
        printf("%d ",sr->data);
        inorder(sr->rightc);
    }
}
