#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������:" << endl;
	string str;
	cin >> str;
	TPolinom p1(str);
	cout << "��� �������: " << p1.ToString() << endl;
	cout << "������� �������:" << endl;
	string str2;
	cin >> str2;
	TPolinom p2(str2);
	cout << "��� �������: " << p2.ToString() << endl;
}