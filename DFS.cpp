#include<bits/stdc++.h>
using namespace std;

class graph{
	public:
	int v;
	list<int>*adj;
	graph(int num){
		v=num;
		adj=new list<int>[num];
	}
	void DFSUtil(int v,bool visited[]){
		visited[v]=true;
		cout<<v<<" ";
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i){
			if(!visited[*i]){
				DFSUtil(*i,visited);
			}
		}
	}
	void DFS(int v){
		bool *visited=new bool[v];
		for(int i=0;i<v;i++){
			visited[i]=false;
		}
		DFSUtil(v,visited);
	}
	void addEdge(int v,int w){
		adj[v].push_back(w);
	}
};

int main(){
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"DFS Traversal"<<endl;
	g.DFS(2);
	return 0;
}
