#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    	int v;
	    list<int>*adj;
        Graph(int n) {
            v=n;
            adj=new list<int>[n];
        }
    
        void addedge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        void BFS(int s) {
           bool *visited=new bool[v];
            int distance[v+1]={0};
            list<int>q;
		   for(int i=0;i<v;i++){
			visited[i]=false;
            }
		   visited[s]=true;
		   q.push_back(s);
		   list<int>::iterator it;
		   while(!q.empty()){
		   int curr=q.front();
		   q.pop_front();
		    for(it=adj[curr].begin();it!=adj[curr].end();++it){
             if(!visited[*it]){
                 distance[*it]+=(distance[curr]+6);
               visited[*it]=true;
               q.push_back(*it);
             }
            }
           }
            for(int i=0;i<v;i++){
                if(i!=s){
                    if(distance[i]==0){
                        cout<<-1<<" ";
                    }
                    else{
                        cout<<distance[i]<<" ";
                    }
                }
            }
        }
    
    };

int main(){
    int q,n,m,u,v,s;
    cin>>q;
    while(q--){
      cin>>n;
      Graph g(n);
      cin>>m;
      for(int i=0;i<m;i++){
         cin>>u>>v;
         u--, v--;
         g.addedge(u,v);
      }
      cin>>s;
      s--;
      g.BFS(s);
      cout<<endl;
    }
    return 0;
}

