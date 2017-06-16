#include<iostream>
#include<string.h>
using namespace std;

struct Node {
	string data;
	Node *ne;
};
Node *h = NULL;
void newnode() {
	Node *n = new Node;
	cin>>n->data;
	n->ne = h;
	h = n;
}

int main() {
	return 0;
}

