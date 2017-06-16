#include<bits/stdc++.h>
using namespace std;

int main() {
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int i,j;
	int m = s1.length();
	int n = s2.length();
	int r = n;
	int count=0;
	if(n==m/2){
		for(i=n-1;i>=0;i--) {
			if(s1[i]!=s2[i]) {
				count++;
			}
			if(s1[r]!=s2[i]) {
				count++;
			}
			r++;
		}
		cout<<count;
	}
	
}
