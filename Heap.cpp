#include<bits/stdc++.h>
using namespace std;
class MaxHeap
{
	public:
	int *harr;
	int cap;
	int hSize;
	MaxHeap(int capacity)
	{
		harr=new int[capacity];
		hSize=0;
		cap=capacity;
	}
	void swap(int &a,int &b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	int left(int i)
	{
		return 2*i+1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	void MaxHeapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int largest=i;
		if(l<hSize && harr[l]>harr[i])
		{
			largest=l;
		}
		if(r<hSize && harr[r]>harr[i])
		{
			largest=r;
		}
		if(largest==i)
		return;
		swap(harr[largest],harr[i]);
		MaxHeapify(largest);
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	void insertkey(int key)
	{
		if(hSize==cap){
		cout<<"Heap full"<<endl;
		return;
		}
		hSize++;
		int i=hSize-1;
		harr[i]=key;
		while(i!=0 && (harr[parent(i)]<harr[i]))
		{
			swap(harr[parent(i)],harr[i]);
			i=parent(i);
		}
	}
	void increasekey(int i,int new_val)
	{
		harr[i]=new_val;
		while(i!=0 && (harr[parent(i)]<harr[i]))
		{
			swap(harr[parent(i)],harr[i]);
			i=parent(i);
		}
	}
	int extractMax()
	{
		if(hSize==0)
		return INT_MIN;
		if(hSize==1)
	    {
		int root=harr[0];
		hSize--;
		return root;
	    }
		swap(harr[0],harr[hSize-1]);
		int root=harr[hSize-1];
		hSize--;
		MaxHeapify(0);
		return root;
	}
	void deleteKey(int i)
	{
		increasekey(i,INT_MAX);
		extractMax();
	}
	void printheap()
	{
		int i;
		for(i=0;i<hSize;i++)
		{
			cout<<harr[i]<<" ";
		}
	}
};
int main()
{
MaxHeap h(11);
h.insertkey(3);
h.insertkey(2);
h.deleteKey(1);
h.insertkey(15);
h.insertkey(5);
h.insertkey(4);
h.insertkey(45);
h.printheap();
	return 0;
}
