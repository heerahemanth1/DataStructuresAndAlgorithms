#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll q;
	cin>>q;
	while(q--)
	{
		ll x;
		priority_queue<ll>pq;
		ll c,k;
		cin>>c>>k;
		for(ll i=0;i<c;i++)
		{
			cin>>x;
			pq.push(x);
		}
		ll e=0;
		while(k--)
		{
			x=pq.top();
			e=e+x;
			pq.pop();
			pq.push(x/2);
		}
		cout<<e<<endl;
	}
	return 0;
}
