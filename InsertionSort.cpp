#include<bits/stdc++.h>

using namespace std;
void insertionSort(vector <int>  a,int n) {
	for(int i=0;i<=n-1;i++)
	{
		int j=i,temp=0;
		while(j>0 && a[j] < a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			for(int k=0;k<n;k++) {
				cout<<a[k]<<" ";
			}
			cout<<endl;
			a[j-1]=temp;
			j--;
        }
	}
	for(int k=0;k<n;k++) {
		cout<<a[k]<<" ";
	}
}
int main(void) {
    vector <int> ar;
    int ar_size;
    cin >> ar_size;
    for(int i=0;i<ar_size;i++) {
        int ar_tmp;
        cin >> ar_tmp;
        ar.push_back(ar_tmp);
    }

    insertionSort(ar,ar_size);
    return 0;
}

