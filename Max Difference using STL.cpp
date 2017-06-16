#include<bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
  
  vector< pair <int,int> > vect;
   int n=A.size();
   for(int i=0;i<n;i++)
    {
         vect.push_back( make_pair(A[i],i));
    }
    sort(vect.begin(), vect.end());
    
     int max_diff =vect[1].second - vect[0].second;
  int min_element =vect[0].second;
  int i;
  for(i = 1; i < n; i++)
  {       
    if (vect[i].second - min_element > max_diff)                               
      max_diff =vect[i].second - min_element;
    if (vect[i].second < min_element)
         min_element = vect[i].second;                     
  }
  if(max_diff>0)
  return max_diff;
  else
  return 0;

}

int main(){
	int n,item;
	cin>>n;
	vector <int>a;
	for(int i=0;i<n;i++){
		cin>>item;
		a.push_back(item);
	}
	cout<<maximumGap(a);
	return 0;
}
