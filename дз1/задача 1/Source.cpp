#include <iostream>
#include <locale>
using namespace std;
// ���
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ���" << endl;
	string name;
	cin >> name;
	cout << "������, " << name << "!";
}