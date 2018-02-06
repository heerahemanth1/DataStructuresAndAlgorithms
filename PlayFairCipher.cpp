#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
    string plaintext, key, ciphertext, alphabet, copy;
    int pfmatrix[5][5];
    if(argc == 2){
	plaintext = argv[1];
	cout<<"Key:\t";
	cin>>key;
    } else if(argc == 3) {
	plaintext = argv[1];
	key = argv[2]
    } else {
	cout<<"Plain Text:\t";
	cin>>plaintext;
	cout<<"Key:\t";
	cin>>key;
    }
    int ptlen = plaintext.length(), klen = key.length();
    if(klen > ptlen) {
	unexpected("\n-----Key length should not be greater than the Plain tect----\n");
    }
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    for(int i=97; i<123; i++) {
	alphabet.insert(alphabet.end(), (char)i);
    }
    for(int i=0; i<klen; i++) {
	if(copy.find(key[i]) == npos) {
	    copy.insert(copy.end(), key[i]);
	}
    }
    klen = copy.length();
    for(int i=0; i<klen; i++) {
	pfmatrix[(int)(i/5)][(int)(i%5)] = copy[i];
    }
    int i=klen;
    int j=0;
    while(j<25) {
	if(copy.find(alphabet[j]) == npos) {
	    pfmatrix[(int)(i/5)][(int)(i%5)] = alphabet[j];
	    copy.insert(copy.end(), alphabet[j]);
	    i++;
	}
	j++;
    }
    int k=0;
    while(k<ptlen) {
	int m = copy.find(plaintext[k]);
	int n;
	if(k+1<ptlen) {
	    n = copy.find(plaintext[k+1]);
	} else {
	    n = copy.find('x');
	}
	int mrow, mcol, nrow, ncol;
	mrow = m/5;
	mcol = m%5;
	nrow = n/5;
	ncol = n%5;
	if(mrow == nrow) {
	    ciphertext.insert(ciphertext.end(), pfmatrix[mrow][(mcol+1)%5]);
	    ciphertext.insert(ciphertext.end(), pfmatrix[mrow][(ncol+1)%5]);
	} else if(mcol == ncol) {
	    ciphertext.insert(ciphertext.end(), pfmatrix[(mrow+1)%5][mcol]);
	    ciphertext.insert(ciphertext.end(), pfmatrix[(nrow+1)%5][mcol]);
	} else {
	    ciphertext.insert(ciphertext.end(), pfmatrix[mrow][ncol]);
	    ciphertext.insert(ciphertext.end(), pfmatrix[nrow][mcol]);
	}
	k += 2;
    }

    cout<<"Cipher Text:\t"<<ciphertext<<endl;
    return 0;
}
