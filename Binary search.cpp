#include<bits/stdc++.h>
using namespace std;

int BS(int *a,int start,int end,int key){
		int mid=(end+start)/2;
		if(start>end){
			return -1;
		}
		else if(a[mid]==key){
			return mid+1;
		}
		else if(a[mid]>key){
			BS(a,start,mid-1,key);
		}
		else{
			BS(a,mid+1,end,key);
		}
	}
	
int main(){
	int i,j,mid,key,n,temp=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	cout<<"Resulting Sequence = ";
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cin>>key;
	cout<<"Location of "<<key<<" = "<<BS(a,0,n,key);
	return 0;
}
