#include<iostream>
#include<string>
#include"menu.h"
#include"crypto.h"
#include"filehandler.h"
using namespace std;
int main(){
    Menu::showmenu();
    Crypto crypto_1, crypto_2;
    FileHandler file_1, file_2;
    int key1, key2,input;
    cout<<"请输入:";
    cin>>input;
    switch(input){
        case 1:{
            crypto_1.crypto();
            break;}
        case 2:{
            crypto_2.decrypto();
            break;}
        case 3:{
            cout<<"输入密钥";
            cin>>key1;
            file_1.encryptFile("/home/ssk/input.txt","encrypted.txt",key1);
            break;}
        case 4:{
            cout<<"输入密钥";
            cin>>key2;
            file_2.decryptFile("encrypted.txt","decrypted.txt",key2);
            break;}
        case 0:{
            cout<<"程序退出"<<endl;
            break;
        }
        default:{
            break;
    }}
    cout << "按回车键继续...";
    cin.ignore();
    cin.get();
    return 0;
}