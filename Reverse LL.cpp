#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void reverse (struct node **);

int main(){
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
	printf("The elements in the reversed linked list are");
	reverse(&p);
	display(p);
	printf("\n");
	return 0;
}


void append ( struct node **q, int num ) {
	struct node *temp=*q;
	struct node *nn=NULL;
	nn=(struct node*)malloc(sizeof(struct node));
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

void reverse ( struct node **x ){
       struct node *temp1,*temp2,*temp3;
      temp1=temp2=temp3=*x;
       temp1=temp1->link->link;
       temp2=temp2->link;
       temp3->link=NULL;
       temp2->link=temp3;
       while(temp1!=NULL)
       {
           temp3=temp2;
           temp2=temp1;
           temp1=temp1->link;
           temp2->link=temp3;
       }
       *x=temp2;
}
