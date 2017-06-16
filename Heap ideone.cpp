#include<bits/stdc++.h>
using namespace std;
class maxHeap
{
public:
  int *harr;
  int cap;
  int hsize;
  maxHeap(int capacity)
  {
    harr = new int[capacity];
    hsize = 0;
    cap = capacity;
  }
  void maxHeapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < hsize && harr[l]> harr[i] )
    {
      largest = l;
    }
    if(r < hsize && harr[r]> harr[i] )
    {
      largest = r;
    }
    if(largest == i)
      return;
    swap(harr[largest],harr[i]);
    maxHeapify(largest);

  }
  void swap(int &a,int &b)
  {
    int temp =a;
        a = b;
        b = temp;
  }
  int left(int i)
  {
    return 2*i + 1;
  }
  int right(int i)
  {
    return 2*i+1;
  }
  int parent(int i)
  {
    return (i-1)/2;
  }
  void insertKey(int key)
  {
    if(hsize == cap)
    {
      cout<<"heap already filled"<<endl;
      return;
    }
    hsize++;
    int i = hsize - 1;
    harr[i] = key;
    while( i!= 0 && harr[parent(i)]<harr[i])
    {
      swap(harr[parent(i)],harr[i]);
      i = parent(i);
    }
  }
  void increaseKey(int i,int key)
  {
    harr[i] = key;
    while(i!=0 && harr[parent(i)] <parent(i))
    {
      swap(harr[parent(i)],harr[i]);
      i= parent(i);
    }
  }
  int extractMax()
  {
    if(hsize == 0)
      return INT_MIN;
    if(hsize == 1)
      {
        int root = harr[0];
        hsize--;
        return root;
      }
    int max = harr[0];
    swap(harr[0],harr[hsize-1]);
    hsize--;
    maxHeapify(0);
    return max;
  }
  void deleteKey(int i)
  {
    increaseKey(i,INT_MAX);
    extractMax();
  }
  void printHeapArray()
  {
    for(int i=0;i<hsize;i++)
    {
      cout<<harr[i]<<" ";
    }
  }
};
int main()
{
  maxHeap m_heap(10);
  m_heap.insertKey(11);
  m_heap.insertKey(5);
  m_heap.insertKey(9);
  m_heap.insertKey(3);
  m_heap.insertKey(2);
  m_heap.insertKey(8);
  m_heap.insertKey(7);
  m_heap.printHeapArray();
  return 0;
}