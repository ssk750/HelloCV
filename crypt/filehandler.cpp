#include <iostream>
#include <fstream>
#include <string>
#include "filehandler.h"
using namespace std;
FileHandler::FileHandler() {
    currentFile = "";
}


bool FileHandler::encryptFile(const string& inputFile,const string& outputFile,int key){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if (!inFile) {
        cout << "打不开文件 " << inputFile << endl;
        return false;
    }
    char ch;
    while (inFile.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'a' && ch <= 'z') {
                outFile.put('a' + (ch - 'a' + key) % 26);
            } else {
                outFile.put('A' + (ch - 'A' + key) % 26);
            }
        } else {
            outFile.put(ch);
        }
    }
    inFile.close();
    outFile.close();
    cout << "加密文件: " << outputFile << endl;
    return true;
}


bool FileHandler::decryptFile(const string& inputFile, const string& outputFile, int key){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if (!inFile) {
        cout << "错误：打不开文件 " <<inputFile << endl;
        return false;
    }
    char ch;
     while (inFile.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'a' && ch <= 'z') {
                outFile.put('a' + (ch - 'a' - key + 26) % 26); 
            } else {
                outFile.put('A' + (ch - 'A' - key + 26) % 26);
            }
        } else {
            outFile.put(ch);
        }
    }
    inFile.close();
    outFile.close();
    cout << "解密文件: " << outputFile << endl;
    return true;
}
