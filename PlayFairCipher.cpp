#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
	string plaintext, key, ciphertext, alphabet;
    char pfmatrix[5][5];

    if (argc==2) {
        plaintext = argv[1];
        cout<<"Key:\t";
        cin>>key;

    } else if (argc == 3) {
        plaintext = argv[1];
        key = argv[2];
    } else {
        cout<<"Plain Text:\t";
        cin>>plaintext;
        cout<<"Key:\t";
        cin>>key;
    }

    

    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int ptlen = plaintext.length();
    int klen  = key.length();
    if (klen > ptlen)
    {
        unexpected("\n--Key length is greater than PlainText length--\n");
    }

	return 0;
}