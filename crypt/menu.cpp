#include<iostream>
#include<string>
#include"menu.h"
using namespace std;
void Menu::showmenu()
{
	cout << string(33, '*') << endl;
    cout << string(33, '*') << endl;
	cout << string(8, '*') << " 0.退出程序      " << string(8, '*') << endl;
	cout << string(8, '*') << " 1.⽂本加密      " << string(8, '*') << endl;
	cout << string(8, '*') << " 2.⽂本解密      " << string(8, '*') << endl;
	cout << string(8, '*') << " 3.⽂件加密保存  " << string(8, '*') << endl;
	cout << string(8, '*') << " 4.⽂件解密保存  " << string(8, '*') << endl;
	cout << string(33, '*') << endl;
	cout << string(33, '*') << endl;
}