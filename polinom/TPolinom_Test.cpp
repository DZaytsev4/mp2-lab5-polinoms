#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите полином:" << endl;
	string str;
	cin >> str;
	TPolinom p1(str);
	cout << "Ваш полином: " << p1.ToString() << endl;
	cout << "Введите полином:" << endl;
	string str2;
	cin >> str2;
	TPolinom p2(str2);
	cout << "Ваш полином: " << p2.ToString() << endl;
}