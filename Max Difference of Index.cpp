#include<bits/stdc++.h>
using namespace std;
int li[100];
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int *a,int l,int h){
	int pivot=a[h];
    int i=l-1;
 
    for(int j=l;j<=h-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
            swap(&li[i],&li[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    swap(&li[i+1],&li[h]);
    return(i+1);
}

void quicksort(int *a,int l,int h){
	if(l<h){
	int pi=partition(a,l,h);
	quicksort(a,l,pi-1);
	quicksort(a,pi+1,h);
    }
}

int maxDiff(int *arr,int n){
    int max_diff=arr[1]-arr[0];
    int min_element=arr[0];
    int i;
    for(i=1;i<n;i++){       
      if (arr[i]-min_element > max_diff)                               
         max_diff=arr[i]-min_element;
      if (arr[i] < min_element)
         min_element=arr[i];                     
    }
  return max_diff;
}

int main(){
	int i,n,max=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
		li[i]=i;
	}
    quicksort(a,0,n-1);
	cout<<maxDiff(li,n);
	return 0;
}
