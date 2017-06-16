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
	void addEdge(int a,int b){
		adj[a].push_back(b);
	}
	void BFS(int s){
		bool *visited=new bool[v];
		for(int i=0;i<v;i++){
			visited[i]=false;
		}
		list<int>q;
		visited[s]=true;
		q.push_back(s);
		list<int>::iterator i;
		while(!q.empty()){
			s=q.front();
			cout<<s<<" ";
			q.pop_front();
			for(i=adj[s].begin();i!=adj[s].end();++i){
              if(!visited[*i]){
                visited[*i]=true;
                q.push_back(*i);
              }
            }
		}
	}
};

int main(){
	int x;
	cin>>x;
	graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,1);
	g.addEdge(1,4);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,0);
	g.addEdge(3,2);
	cout<<"BFS Traversal"<<endl;
	g.BFS(x);
	return 0;
}
