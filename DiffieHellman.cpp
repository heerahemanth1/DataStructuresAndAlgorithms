#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int g, p, a, b, A, B;
	cout<<"The public known values of 'g' and 'p':"<<endl;
	cin>>g>>p;
	cout<<g<<"\t"<<p<<endl;
	a = 5;
	b = 6;
	cout<<"Values of 'a' and 'b': "<<a<<"\t"<<b<<endl;
	A = (int)(pow(g, a));
	cout<<A;
	A = (A%p);
	B = (int)(pow(g, b));
	cout<<B;
	B = (B%p);
	cout<<"Values of 'A' and 'B': "<<A<<"\t"<<B<<endl;
	cout<<"Key on Sender's side (pow(B, a)%p): "<<((int)(pow(B, a))%p)<<endl;
	cout<<"Key on Receiver's side (pow(A, b)%p): "<<((int)(pow(A, b))%p)<<endl;
	return 0;
}