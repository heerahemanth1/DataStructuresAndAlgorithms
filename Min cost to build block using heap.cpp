#include"bits/stdc++.h"
using namespace std;
class minHeap{
public:
	int capacity;
	int *harr;
	int hsize;
	minHeap(int cap){
		capacity = cap;
		harr = new int[cap];
		hsize = 0;
	}

	int left(int i){
		return 2*i+1;
	}

	int right(int i){
		return 2*i+2;
	}

	int parent(int i){
		return (i-1)/2;
	}

	void insertkey(int key){
		if(hsize == capacity){
			cout<<"maximum limit reached";
			return;
		}
		hsize++;
		int i = hsize - 1;
		harr[i] = key;
		while(i != 0 && harr[parent(i)]>harr[i]){
			swap(harr[parent(i)],harr[i]);
			i = parent(i);
		}
	}

	void swap(int &a,int &b){
		int temp = a;
		a = b;
		b = temp;
	}

	void heapify(int i){
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if(l < hsize && harr[l] < harr[i])
			smallest = l;
		if(r < hsize && harr[r] < harr[smallest])
			smallest = r;
		if(smallest == i){
			return;
		}
		swap(harr[smallest],harr[i]);
		heapify(smallest);
	}

	int extractMin(){
		if(hsize == 0)
			return INT_MIN;
		else if(hsize == 1){
			int min = harr[0];
			hsize--;
			heapify(0);
			return min;
		}else{
			int min = harr[0];
			swap(harr[0],harr[hsize-1]);
			hsize--;
			heapify(0);
			return min;
		}
	}

	int reseval(){
		int min1,min2;
		int sum = 0;
		while(hsize != 1){
			min1 = extractMin();
			min2 = extractMin();
			sum+=min1+min2;
			insertkey(min1+min2);
		}
		return sum;

	}

	void printHeap(){
		for(int i = 0;i<hsize;i++){
			cout<<harr[i]<<" ";
		}
	}
};

int main(){
	
	int n;
	cin>>n;
	minHeap m(n);
	int item;
	for(int i = 0;i<n;i++){
		cin>>item;
		m.insertkey(item);
	}
	m.printHeap();
	cout<<endl<<m.reseval();
	return 0;

}
