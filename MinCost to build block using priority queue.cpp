#include<bits/stdc++.h>
using namespace std;

int minCost(int arr[],int n){
	priority_queue<int,vector<int>,greater<int> >pq(arr,arr+n);
	int cost=0;
	while(pq.size()>1)
	{
		int min1=pq.top();
		pq.pop();
		int min2=pq.top();
		pq.pop();
		cost+=(min1+min2);
		pq.push(min1+min2);
	}
	return cost;
}

int main()
{
	int arr[]={3,5,9,7,4};
	cout<<minCost(arr,5);
	return 0;
}
