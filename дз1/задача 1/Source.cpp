#include <iostream>
#include <locale>
using namespace std;
// имя
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите имя" << endl;
	string name;
	cin >> name;
	cout << "Привет, " << name << "!";
}