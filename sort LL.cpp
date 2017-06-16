#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void insert ( struct node **, int ) ;
void display ( struct node * ) ;
void sort(struct node *);
int count(struct node *);

int main() {
	struct node *p ;
	p=NULL;
	int n;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		insert(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	return 0;
}


void insert ( struct node **q, int num ) {
	struct node *temp=*q;
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	nn->link=NULL;
	if(temp==NULL)
	{
	    *q=nn;
	}
	else
	{
	    while(temp!=NULL)
	    {
	        temp=temp->link;
	    }
	    temp->link=nn;
	}
}
int count(struct node *q)
{
    int ct=0;
    struct node *temp=q;
    while(temp!=NULL)
    {
        ct++;
        temp=temp->link;
    }
    return ct;
}

void sort(struct node *q)
{
    struct node *temp=q;
    int i,j,a,n=count(q);
    while(temp!=NULL)
    {
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if( (temp->data) > (temp->link->data) )
                {
                    a=temp->data;
                    temp->data=temp->link->data;
                    temp->link->data=a;
                }
            }
        }
    }
}

void display ( struct node *q ) {
	struct node *temp=q;
	while(temp!=NULL)
	{
	    printf(" %d",temp->data);
	}
	temp=temp->link;
}
