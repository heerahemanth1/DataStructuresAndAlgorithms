#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

main(){
    string plaintext, key, ciphertext, alphabet;
    
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
    
    for (int i = 97; i < 123; i++) {
        alphabet.insert(alphabet.end(), (char)i);
    }
    for(int i = 0; i < klen; i++){
        ciphertext.insert(ciphertext.end(), alphabet[((alphabet.find(plaintext[i])+alphabet.find(key[i]))%26)]);
    }
    for(int i = klen; i < ptlen; i++){
        ciphertext.insert(ciphertext.end(), alphabet[((alphabet.find(plaintext[i]+alphabet.find(plaintext[(i-klen)])))%26)]);
    }
    cout<<"Cipher Text:\t"<<ciphertext<<endl;

    return 0;
}