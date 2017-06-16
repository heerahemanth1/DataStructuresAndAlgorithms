#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    int v;
    int *c;
    int *visited;
    list<int>*adj;
    graph(int num){
        v=num;
        adj=new list<int>[num+1];
        visited = new int[v+1];
        c = new int[v+1];
        for(int i=0;i<v+1;i++){
            visited[i]=0;
            c[i]=1;
        }
    }
    void addEdge(int a,int b){
	    adj[a].push_back(b);
    }
    void dfs2(int a){
        int curr=a;
        visited[curr]=1;
        list<int>::iterator it;
        for(it=adj[curr].begin();it!=adj[curr].end();++it){
            if(visited[*it]!=1){
                dfs2(*it);
                c[curr]=c[curr]+c[*it];
            }
        }
    }
    void dfs(){
        for(int i=1;i<v+1;i++){
            if(visited[i]!=1){
                dfs2(i);
            }
        }
    }
    
    void checkquery(int l,int r){
        long s=0;
        for(int i=l;i<=r;i++){
            s +=c[i];
        }
        cout<<s<<endl;
    }
};
int main() {
    int n,q;
    cin>>n>>q;
    graph g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.dfs();
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        g.checkquery(l,r);
    }
    return 0;
}
