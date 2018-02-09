#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
using namespace std;

void unexp_handler()
{
	cout<<"\n-----Key length should not be greater than the Plain tect----\n";
	abort();
}

int main(int argc, char const *argv[])
{
	set_unexpected(unexp_handler);
	string plaintext, ciphertext;
	int key;

    if (argc==2) {
        plaintext = argv[1];
        cout<<"Key:\t";
        cin>>key;

    } else if (argc == 3) {
        plaintext = argv[1];
        key = stoi(argv[2]);
    } else {
        cout<<"Plain Text:\t";
        cin>>plaintext;
        cout<<"Key:\t";
        cin>>key;
    }

    int ptlen = plaintext.length();
    int klen = to_string(key).length();
    if (klen > ptlen)
    {
    	unexpected();
    }
    
    for (int i = klen; i > 0; i--)
    {
    	int c;
    	if (!(i == 1)) {
    		c = (key % int(pow(10, i)))/(pow(10, i-1));
    	} else {
    		c = key % 10;
    	}
    	int j = 0;
    	while (((c - 1) + j) < ptlen)
    	{
    		ciphertext.insert(ciphertext.end(), plaintext[(c - 1) + j]);
    		j += klen;
    	}
    }
    cout<<"Cipher Text:\t"<<ciphertext<<endl;

	return 0;
}