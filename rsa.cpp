#include<iostream>
#include<string>
#include<stdexcept>
#include<cmath>

using namespace std;

/*bool arePrimes(long p, long q) {
	int i = 2;
  while(i < 10) {
  	if(p%i == 0 || q%i == 0)
  		return false;
  	i++;
  }
  return true;
}*/

long gcd(long a, long b) {
  while(1) {
    int temp = (a%b);
    if(temp == 0)
			return b;
    a = b;
    b = temp;
  }
}

long calculate_E(long st, long phi) {
  long i = st;
  while(i < phi) {
    if(gcd(i, phi) == 1)
			return i;
    i++;
  }
  return 1;
}

long calculate_D(long e, long phi) {
  long temp = 2;
  while(temp < phi) {
    if((temp*e)%phi == 1)
			return temp;
    temp++;
  }
  return 1;
}

string encrypt(const string &pt, long e, long n) {
	string ct;
	char ins;
	double t;
	for(int i=0; i<pt.length(); i++) {
		double p = pow((double)pt[i], (double)e);
		t = fmod(p, (double)n);
		ins = (char)t;
		ct.insert(ct.end(), ins);
	}
	return ct;
}

string authenticate(string ct, long e) {
	string at;
	for(int i=0; i<ct.length(); i++)
		at.insert(at.end(), ((char)((int)ct[i]+(int)e)));
	return at;
}

int main(int argc, const char *argv[]) {
  long p, q;
  cout<<"Enter two Prime numbers 'p' and 'q' separated by a space:\n";
  cin>>p>>q;
  
  /*if(!(arePrimes(p, q))) {
    cout<<"Please enter Prime numbers."<<endl;
    unexpected();
  }*/
  
  long n, phi;
  n = p*q;
  phi = (p-1)*(q-1);
  long e, d, st = 2;
  do {
    e = calculate_E(st, phi);
    d = calculate_D(e, phi);
    st++;
  } while(d == 1 && st < phi);
  cout<<e<<"\t"<<d<<endl;
  
  string pt, ct;
  cout<<"Enter the PlainText:\t";
  cin>>pt;
  ct = encrypt(pt, e, n);
  cout<<"Ciphertext:\t"<<ct<<endl;
  cout<<"Authenticated:\t"<<authenticate(ct, e)<<endl;
  
  return 0;
}
