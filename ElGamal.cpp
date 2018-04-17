#include <iostream>
#include <string>
#include <tr1/functional>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	int p, g, ya, xa, yb, xb, m, s, r, x;
	tr1::hash<int> in_hash;
	cout<<"'p':\t";
	cin>>p;
	cout<<"'g':\t";
	cin>>g;
	// private key of A
	xa = 127;
	// public key of A
	ya = (int)fmod(pow((double)g, (double)xa), (double)p);
	// value of message
	cout<<"'m':\t";
	cin>>m;
	// value of x for current signature
	x = 213;
	// calculating values of r & s
	r = (int)fmod(pow((double)g, (double)x), (double)p);
	s = (int)fmod((double)((in_hash(m) -(xa * r))/x), (double)(p-1));
	
	cout<<"'r':   "<<r<<",\t's':   "<<s<<"."<<endl;
	return 0;
}
