#include<iostream>
#include<string>
#include"crypto.h"
using namespace std;
void Crypto::crypto(){
    string a; 
    int b;
    cout << "输入文本: ";
    cin.ignore();
    getline(cin, a);
    cout<<"输入密钥:";
    cin >> b;
    cout << "加密后的文本: ";
    for(int i=0;i<a.length();i++) {
        char ch = a[i];
        char encrypted_char;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'a' && ch <= 'z') {
                encrypted_char = 'a' + (ch - 'a' + b) % 26;
            } 
            else {
                encrypted_char = 'A' + (ch - 'A' + b) % 26;
            }
        }
        else {
            encrypted_char = ch;
        }
        cout << encrypted_char;
    }
    cout<<endl;
}
void Crypto::decrypto(){
    string a;
    int b;
    cout<<"输⼊加密后的⽂本";
    cin.ignore();
    getline(cin, a);
    cout<<"输⼊密钥";
    cin>>b;
    for(int i=0;i<a.length();i++) {
        char ch = a[i];
        char decrypted_char;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'a' && ch <= 'z') {
                decrypted_char = 'a' + (ch - 'a' - b + 26) % 26;
            }
            else {
                decrypted_char = 'A' + (ch - 'A' - b + 26) % 26;
            }
        }
        else {
            decrypted_char = ch;
        }
        cout << decrypted_char;
    }
    cout<<endl;
}

    
