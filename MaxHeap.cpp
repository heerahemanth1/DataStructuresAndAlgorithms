#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int temp = a;
	a = b;
	b = temp;
}

class Heap {
	
	public:
		int *harr, cap, hsize;
		Heap(int cap) {
			this.harr = new int[cap];
			this.cap = cap;
			this.hsize = 0;
		}
		
		void heapify(int i) {
			int l = 2*i+1;
			int r = 2*i+2;
			int largest;
			if(l<hsize && harr[l]>harr[i] && harr[l]>harr[r]) {
				largest = l;
				swap(harr[i],harr[l]);
				heapify(l);
			} else if(r<hsize && harr[r]>harr[i] && harr[r]>harr[l]) {
				largest = r;
				swap(&harr[i],&harr[r]);
				heapify(r);
			}
			return;
		}
		
		void insertKey(int x) {
			if(hsize==cap) {
				cout<<"Heap already filled"<<endl;
				return;
			}
			int i = hsize;
			hsize++;
			harr[i] = key;
			while(i!=0 && harr[((i-1)/2)]<harr[i]) {
				
			}
		}
		
		void increaseKey(int key, int val) {
			harr[key] = val;
			while(key!=0 && harr[((key-1)/2)]<harr[key]) {
				swap(&harr[key], &harr[((key-1)/2)]);
				key = (key-1)/2;
			}
		}
		
		void deleteKey(int key) {
			increaseKey(i,INT_MAX);
			extractMax();
		}
		
		int extractMax() {
			if(this.hsize==0) {
				return INT_MIN;
			} else if(hsize==1) {
				hsize = 0;
				return harr[0];
			}
			int max = harr[0];
			swap(&harr[0],&harr[hsize-1]);
			hsize -= 1;
			heapify(0);
			return max;
		}
		
		void printHeap() {
			for(int i=0;i<hsize;i++) {
				cout<<harr[i]<<" ";
			}
		}
};

int main() {
	Heap h(7);
	h.insertKey();
}
