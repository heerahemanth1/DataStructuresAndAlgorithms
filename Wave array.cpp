#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int main(){
	int n,flag=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(flag==0){
		    if(a[i]<a[i+1]){
		  	    swap(&a[i],&a[i+1]);
		    }
		    flag=1;
	    }
	    else{
	    	if(a[i]>a[i+1]){
	    		swap(&a[i],&a[i+1]);
			}
			flag=0;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
