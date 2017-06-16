#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int count ( struct node *);
int findmid (struct node *);


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
	printf("The middle element in the linked list is %d\n", findmid(p));
	return 0;
}

void append ( struct node **q, int num ) {
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

int count ( struct node *q ) {
	struct node *temp=q;
	int count=0;
	while(temp!=NULL)
	{
	    count++;
	    temp=temp->link;
	}
	return count;
}

int findmid ( struct node *q) {
    struct node *temp=q;
  	int x=count(q);
  	int y;
  	if(x%2==0)
  	{
  	    y=x/2;
  	}
  	else
  	{
  	    y=x/2+1;
  	}
  	int ct=0;
  	    while( temp!=NULL )
  	    {
  	        ct++;
  	        if(ct==y)
  	        {
  	            return temp->data;
  	        }
  	        temp=temp->link;
  	    }
  	return 0;;
}
