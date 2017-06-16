#include <bits/stdc++.h>
using namespace std;

int whoGetsTheCatch(int n, int x, vector <int> X, vector <int> V){
    int time[n],catcher=0,i,j;
    for(i=0;i<n;i++){
        time[i]=abs((X[i]-x)/V[i]);
    }
    int small=time[0];
	for(i=0;i<n;i++){
		if(time[i]<=small){
			small=time[i];
            catcher=i;
		}
	}
    for(i=0;i<n;i++){
        if(time[i]==small && i!=catcher){
            return -1;
        }
      }
    return catcher;
}

int main() {
    int n;
    int x;
    cin>>n>>x;
    vector<int> X(n);
    for(int X_i=0;X_i<n;X_i++){
       cin>>X[X_i];
    }
    vector<int> V(n);
    for(int V_i = 0; V_i < n; V_i++){
       cin >> V[V_i];
    }
    int result=whoGetsTheCatch(n, x, X, V);
    cout<<result<<endl;
    return 0;
}

