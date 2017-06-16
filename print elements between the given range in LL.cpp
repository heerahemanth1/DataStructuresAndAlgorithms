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
void printlots( struct node *, int, int);

int main() {
	struct node *p ;
	p=NULL;
	int n,l,h;
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
	printf("Enter the range of elements to print\n");
	scanf("%d",&l);
	scanf("%d",&h);
	if(h>count(p))
		printf("Invalid Range\n");
	else {
		printf("The elements in the range %d to %d are \n",l,h);
		printlots(p,l,h);
		printf("\n");
	}
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

void printlots( struct node *q, int low, int high) {
	struct node *temp=q;
	int c=1;
	if(low<=high)
	{
	 while(temp!=NULL)
	 {
	    if((c>=low) && (c<=high))
	    {
	        printf("%d ",temp->data);
	    }
	    temp=temp->link;
	    c++;
	 }
	}
}
