#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while(1) {
        int temp = (a%b);
        if(temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int main(int argc, char const *argv[])
{
    int a, b;
    cout<<"Values of 'a' & 'b':\t";
    cin>>a>>b;
    int GCD = gcd(a, b);
    cout<<"GCD(a, b):\t"<<gcd(a, b)<<endl;
    int t1,t2,t3,a1=1,a2=0,a3=a,b1=0,b2=1,b3=b;
    while (1) {
        if (b3 == 0) {
            cout<<"No Inverse"<<endl;
            break;
        }
        if (b3 == 1) {
            cout<<"Inverse(b mod a):\t"<<b2;
            break;
        }
        int q = a3/b3;
        t1=a1-q*b1,t2=a2-q*b2,t3=a3-q*b3;
        a1=b1,a2=b2,a3=b3;
        b1=t1,b2=t2,b3=t3;
    }
    return 0;
}