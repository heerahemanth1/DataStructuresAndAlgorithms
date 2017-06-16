#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int findSqrt(ll n){
	ll start=0,end=n,mid,res;
	if(n==0 || n==1){
		return n;
	}
	while(start<=end){
		mid=(start+end)/2;
		if(mid*mid==n){
			return mid;
		}
		if(mid*mid<n){
			start=mid+1;
			res=mid;
		}
		else{
			end=mid-1;
		}
	}
	return res;
	
}

int main(){
	ll x;
	cin>>x;
	cout<<"Square root of "<<x<<" = "<<findSqrt(x);
	return 0;
}
