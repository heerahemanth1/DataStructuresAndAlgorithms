#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

/*
bool areCoPrimes(long p, long q) {
  if(p%2==0 && q%2==0) {
    return false;
  } else if()
}
*/

long gcd(long a, long b) {
  while(1) {
    int temp = (a%b);
    if(temp == 0) {
	return b;
    }
    a = b;
    b = temp;
  }
}

long calculate_E(long st, long phi) {
  long i = st;
  while(i < phi) {
    if(gcd(i, phi) == 1) {
	return i;
    }
    i++;
  }
  return 1;
}

long calculate_D(long e, long phi) {
  long temp = 2;
  while(temp < 10000) {
    if((temp*e)%phi == 1) {
	return temp;
    }
    temp++;
  }
  return 1;
}

int main(int argc, const char *argv[]) {
  long p, q;
  cout<<"Enter two co-primes 'p' and 'q' separated by a space:\n";
  cin>>p>>q;
  /*
  if(!(areCoPrimes(p, q))) {
    cout<<"Please enter Prime numbers."<<endl;
    unexpected();
  }
  */
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
  return 0;
}
