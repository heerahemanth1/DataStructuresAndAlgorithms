#include<bits/stdc++.h>
using namespace std;

struct node {
	node *l;
	int data;
	node *r;
};

node *root = NULL;

void insert() {
	node *t = root;
	node *n = new node;
	cin>>n->data;
	n->r = NULL;
	n->l = NULL;
	if(t==NULL) {
		root = n;
	} else {
		node *prev = root;
		while(t!=NULL) {
			prev = t;
			if(t->data<n->data) {
				t = t->r;
			} else {
				t = t->l;
			}
		}
		prev = n;
	}
}

void del() {
	int x;
	cin>>x;
	node *t = root;
	if(t==NULL) {
		cout<<"Tree Empty"<<endl;
	} else {
		node *par = root;
		while(t!=NULL || t->data!=x) {
			par = t;
			if(t->data<x) {
				t = t->r;
			} else {
				t = t->l;
			}
		}
		if(t==NULL) {
			cout<<x<<" not found."<<endl;
		} else {
			if(t->l!=NULL && t->r==NULL) {
				
			} else if(t->l==NULL && t->r!=NULL) {
				
			} else if(t->l!=NULL && t->r!=NULL) {
				
			} else {
				
			}
		}
	}
}

int main() {
	return 0;
}
