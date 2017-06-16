#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;
vector<bool>visited;

class graph
{
	public:
	int v;
	list< pair<int, int> > *adj;
	graph(int num)
	{
		v=num;
		adj=new list<ipair>[num];
	}
	    
	void addEdge(int a,int b,int w)
	{
	   adj[a].push_back(make_pair(b,w));
	   adj[b].push_back(make_pair(a,w));
	}

	void Dijkstra(int s)
	{
		vector<bool>visited(v,false);
		vector<int>distance(v,INT_MAX);
		distance[s]=0;
		priority_queue< ipair , vector<ipair>,greater<ipair> >pq;
		pq.push(make_pair(distance[s],s));
		while(!pq.empty())
		{
			int u=pq.top().second;
			pq.pop();
			list<ipair>::iterator it;
			for(it=adj[u].begin();it!=adj[u].end();++it)
			{
				int t=(*it).first;
				int w=(*it).second;
				if( (distance[t]) > (distance[u]+w) )
				{
					distance[t]=distance[u]+w;
					pq.push(make_pair(distance[t],t));
				}
			}
		}
		
		for(int i=0;i<v;i++)
		{
			if(distance[i]!=0)
            {
                if(distance[i]==INT_MAX)
                    cout<<"-1"<<" ";
                else
                    cout<<distance[i]<<" ";
            }
		}
	}
    
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {	
	int n,m;
	cin>>n>>m;
	graph g(n);
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
        x--;y--;
		g.addEdge(x,y,w);
    }
	int c;
	cin>>c;
       c--;
	g.Dijkstra(c);
       cout<<endl;
   }
	return 0;
}
