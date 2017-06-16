#include<iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

class Graph {
	public:
	int v;
	list<int> *adj;	
	Graph(int num) {
		v = num;
		adj = new list<int>[num];
	}
	
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	void removeEdge(int a, int b) {
		list<int>::iterator it = find(adj[a].begin(),adj[a].end(),b);
		if(it != adj[a].end()) {
			adj[a].erase(it);
		}
		list<int>::iterator it2 = find(adj[b].begin(),adj[b].end(),a);
		if(it2 != adj[b].end()) {
			adj[b].erase(it2);
		}
	}
	
	bool isEdge(int a, int b) {
		list<int>::iterator it = find(adj[a].begin(),adj[a].end(),b);
		if(it != adj[a].end()) {
			return true;
		}
		return false;
	}
	
	void printEdges(int x) {
		list<int>::iterator it;
		for(it=adj[x].begin(); it!=adj[x].end();++it) {
			cout<<*it<<" ";
		}
	}
	
	void printAdjList() {
		for(int i=0;i<v;i++) {
			printEdges(i);
			cout<<endl;
		}
	}
	
};

int main() {
	Graph g(5);
	g.addEdge(0,4);
	g.addEdge(1,3);
	g.addEdge(0,1);
	g.addEdge(3,2);
	g.addEdge(2,4);
	g.printAdjList();
}
