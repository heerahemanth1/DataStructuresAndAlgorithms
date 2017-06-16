#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void delete (struct node **, int);

int main() {
	struct node *p ;
	p=NULL;
	int n;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	printf("Enter the element to be deleted\n");
	scanf("%d",&n);
	delete(&p,n);
	printf("The elements in the linked list after deleting the element are");
	display(p);
	printf("\n");
	return 0;
}

void append ( struct node **q, int num ) {
	struct node *temp=*q;
	struct node *nn=NULL;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	nn->link=NULL;
	if(temp==NULL)
	{
	    *q=nn;
	}
	else
	{
	    while(temp->link!=NULL)
	    {
	     temp=temp->link;
	    }
	    temp->link=nn;
	}
}

void display ( struct node *q ) {
	struct node *temp=q;
	while(temp!=NULL)
	{
	    printf(" %d",temp->data);
	    temp=temp->link;
	}
}
int search(struct node *q,int e)
{
    struct node *temp;
    temp=q;
    int f=0;
    while(temp!=NULL)
    {
        if(temp->data==e)
        {
            f++;
            break;
        }
        temp=temp->link;
    }
    if(f==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void delete ( struct node **q, int num ) {
    if((*q)->link==NULL)
	{
	  exit(-1);
	}
	else
	{
	  int fd=search(*q,num);
	  if(fd==0)
	  {
        printf ( "Element %d not found\n", num ) ;
	  }
	  else
	  {
	    struct node *temp=*q;
	    struct node *temp1;
	    if(temp!=NULL && temp->data==num)
	    {
	        *q=temp->link;
	        free(temp);
	        return;
	    }
	    while((temp->link!=NULL) && (temp->data!=num))
	    {
	        temp1=temp;
	        temp=temp->link;
	    }
	    if(temp->data==num)
	    {
	        temp1->link=temp->link;
	        free(temp);
	    }
	  }
	}
}

