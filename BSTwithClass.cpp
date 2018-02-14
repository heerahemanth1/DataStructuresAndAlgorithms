#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Node
{
public:
	int data;
	Node *lf;
	Node *rt;
	Node(int value)
	{
		data = value;
	}	
};

Node *root = NULL;
Node *temp, *pre;

void insert()
{
	int value;
	cout<<"Enter value:\t";
	cin>>value;
	Node *cur;
	cur = new Node(value);
	if(root == NULL) {
		root = cur;
	} else {
		temp = root;
		pre = root;
		while(temp != NULL) {
			pre = temp;
			if(temp->data > value) {
				temp = temp->lf;
			} else if(temp->data < value) {
				temp = temp->rt;
			}
		}
		if (pre->data < value) {
			pre->rt = cur;
		} else {
			pre->lf = cur;
		}
	}
	
}

void preorder(Node *t)
{
	if(t == NULL) {
		return;
	} else {
		cout<<t->data<<"\t";
		preorder(t->lf);
		preorder(t->rt);
	}
}

void postorder(Node *t)
{
	if(t == NULL) {
		return;
	} else {
		preorder(t->lf);
		preorder(t->rt);
		cout<<t->data<<"\t";
	}
}

void inorder(Node *t)
{
	if(t == NULL) {
		return;
	} else {
		preorder(t->lf);
		cout<<t->data<<"\t";
		preorder(t->rt);
	}
}

int main(int argc, char const *argv[])
{
	int ch;
	do {
		cout<<"\nChoice:\n1)Insertion\n2)PreOrder\n3)PostOrder\n4)InOrder\n5)Exit"<<endl;
		cin>>ch;
		switch(ch) {
			case 1:
				insert();
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				inorder(root);
				break;
			case 5:
				exit(0);
			default:
				cout<<"---Sorry! Wrong Choice";
		}
	} while(ch != 5);
	return 0;
}