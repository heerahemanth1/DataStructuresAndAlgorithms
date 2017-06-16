#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void insert ( struct node **, int ) ;
void display ( struct node * ) ;

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
	if((*q)==NULL || (*q)->data >= nn->data)
	{
	    nn->link=(*q);
	    (*q)=nn;
	    return;
	}
	else
	{
	    temp=*q;
	    while(temp->link!=NULL && temp->link->data < nn->data)
	    {
	        temp=temp->link;
	    }
	    nn->link=temp->link;
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
