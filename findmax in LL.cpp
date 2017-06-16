#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int findmax (struct node *);

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
	printf("The maximum element in the linked list is %d\n", findmax(p));
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

int findmax ( struct node *q ) {
	int max=0;
	struct node *temp;
	temp=q;
	while(temp!=NULL)
	{
	    if((temp->data)>max)
	    {
	        max=temp->data;
	    }
	    temp=temp->link;
	}
	return max;
}
