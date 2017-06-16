#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
int search (struct node *, int);


int main() {
	struct node *p ;
	p=NULL;
	int n,ele;
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
	printf("Enter the element to be searched\n");
	scanf("%d",&ele);
	if(search(p,ele))
		printf("%d is present in the linked list\n",ele);
	else
		printf("%d is not present in the linked list\n",ele);
	return 0;
}


void append ( struct node **q, int num ) {
	struct node *temp;
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	temp=*q;
	nn->data=num;
	nn->link=NULL;
	if(*q==NULL)
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
int search ( struct node *q, int e ) {
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
