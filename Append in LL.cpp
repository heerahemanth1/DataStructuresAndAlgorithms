#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;

int main() {
	struct node *p=NULL;
	int n;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are");
	display(p);
	printf("\n");
	printf("The number of elements in the linked list is %d\n",count(p));
	return 0;
}

void append ( struct node **q, int num )
{
	struct node *curr=*q;
	struct node *nn=NULL;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=num;
	nn->link=NULL;
	if(curr==NULL)
	{
	    *q=nn;
	}
	else
	{
	    while(curr->link!=NULL)
	    {
	        curr=curr->link;
	    }
	    curr->link=nn;
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

int count ( struct node * q ) {
    int count=0;
	struct node *temp=q;
	while(temp!=NULL)
	{
	    count++;
	    temp=temp->link;
	}
	return count;
}
