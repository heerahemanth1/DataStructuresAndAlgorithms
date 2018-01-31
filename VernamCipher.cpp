#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	string plaintext, key, ciphertext, alphabet;
    char buf[1];
    cout<<"Plain Text:\t";
    cin>>plaintext;
    cout<<"Key:\t";
    cin>>key;
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int ptlen = plaintext.length();
    int klen  = key.length();
    for(int i = 97; i < 123; ++i)
    {
        alphabet.insert(alphabet.end(), (char)i);
    }
    for(int i = 0; i < klen; ++i)
    {
    	ciphertext.insert(ciphertext.end(), alphabet[(alphabet.find(plaintext[i]) ^ alphabet.find(key[i]))%26]);
    }
    for (int i = klen; i < ptlen; ++i)
    {
    	ciphertext.insert(ciphertext.end(), alphabet[(alphabet.find(plaintext[i]) ^ alphabet.find(plaintext[i-klen]))%26]);
    }
    cout<<ciphertext;

	return 0;
}