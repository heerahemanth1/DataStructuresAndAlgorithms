#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void push(struct node**,int);
void display(struct node*);
int count(struct node*);
void pop(struct node **);

int main()
{
	struct node *p=NULL;
	int choice;
	printf("Choice 1 : To push data\n");
	printf("Choice 2 : To pop data\n");
	printf("Choice 3 : To display\n");
	printf("Choice 4 : To count\n");
	printf("\n");
	do{
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice){
	    case 1:printf("Enter the data to be pushed\n");
	           int d;
	           scanf("%d",&d);
	           push(&p,d);
	           break;
	    case 2:pop(&p);
	           break;
	    case 3:printf("Linked List Contents\n");
	            if(p){
	                display(p);
	                }
	            printf("\n");
	           break;
	    case 4:printf("Number of elements in the linked list is %d\n",count(p));
	            break;
	   default:printf("END\n");
	            return 0;
	                
	}
	}while(1);
	return 0;
}

void push(struct node **p,int ele){
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=ele;
    if(*p==NULL)
    {
        q->link=NULL;
        *p=q;
    }
    else
    {
        q->link=*p;
        *p=q;
    }
}

void display(struct node *p){
    struct node *q;
    q=p;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->link;
    }
}

int count(struct node *p){
   struct node *q;
   int count=0;
   q=p;
   while(q!=NULL)
   {
       count++;
       q=q->link;
   }
   return count;
}
void pop(struct node **p){
   if(*p==NULL)
   {
       printf("No element in the stack\n");
   }
   else
   {
       struct node *q;
       int item;
       q=*p;
       item=q->data;
       *p=(*p)->link;
       free(q);
       printf("Element Popped is %d\n",item);
   }
}
