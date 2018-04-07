#include <iostream>
#include <tr1/functional>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int g, p, a, b, A, B;
	double dA, dB;
	tr1::hash<string> str_hash;
	string inp, oup, t;
	
	stringstream ststream;

	cout<<"The public known values of 'g' and 'p':"<<endl;
	cin>>g>>p;
	cout<<g<<"\t"<<p<<endl;

	a = 5;
	b = 6;

	cout<<"Values of 'a' and 'b': "<<a<<"\t"<<b<<endl;

	dA = (pow(g, a));
	A = (int)fmod(dA,(double)p);
	dB = (pow(g, b));
	B = (int)fmod(dB,(double)p);

	int key = (int)fmod(pow(B, a),(double)p);

	cout<<"Values of 'A' and 'B': "<<A<<"\t"<<B<<endl;
	cout<<"\nKey (pow(B, a)%p): "<<key<<endl;
	
	cout<<"\nEnter plaintext: ";
	cin>>inp;
	
	//inp.append(to_string(str_hash(inp))); // inp.end(), 
	
	ststream << str_hash(inp);
	ststream >> t;
	cout<<"PlainText with Hash value:\t"<<inp<<t<<endl;
	inp.append(t);	
	
	for(int i=0; i<inp.length(); i++) {
		oup.insert(oup.end(), (char)((int)inp[i]+key));
	}
	
	cout<<"Authenticated: "<<oup<<endl;
	
	
	return 0;
 }
