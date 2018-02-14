#include <iostream>
#include <string>
#include <algorithm>
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
    string plaintext, key, ciphertext, alphabet, copy;
    char pfmatrix[5][5];
    if(argc == 2){
		plaintext = argv[1];
		cout<<"Key:\t";
		cin>>key;
    } else if(argc == 3) {
		plaintext = argv[1];
		key = argv[2];
    } else {
		cout<<"Plain Text:\t";
		cin>>plaintext;
		cout<<"Key:\t";
		cin>>key;
    }
    string s;
    for (int i = 0; i < key.length(); ++i)
    {
    	if (s.find(key[i]) == string::npos)
    	{
    		s.insert(s.end(), key[i]);
    	}
    }
    key = s;
    int ptlen = plaintext.length(), klen = key.length();
    if(klen > ptlen) {
		unexpected();
    }
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    for(int i=97; i<123; i++) {
    	if((char)i != 'j') {
    		alphabet.insert(alphabet.end(), (char)i);
    	}
    }
    for(int i=0; i<klen; i++) {
		if(copy.find(key[i]) == string::npos) {
		    copy.insert(copy.end(), key[i]);
		    pfmatrix[(int)(i/5)][(int)(i%5)] = key[i];
		}
    }
    klen = copy.length();
    int i=klen;
    int j=0;
    while(j<25) {
		if(copy.find(alphabet[j]) == string::npos) {
		    pfmatrix[(int)(i/5)][(int)(i%5)] = alphabet[j];
		    copy.insert(copy.end(), alphabet[j]);
		    i++;
		}
		j++;
    }
    for (int i = 0; i < 5; ++i)
    {
    	for (int j = 0; j < 5; ++j)
    	{
    		cout<<pfmatrix[i][j]<<" ";
    	}
    	cout<<endl;
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

    cout<<"\nCipher Text:\t"<<ciphertext<<endl<<endl;
    return 0;
}
