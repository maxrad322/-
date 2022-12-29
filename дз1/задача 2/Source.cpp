#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	// "Арифметика"
	float x, y;
	cout << "Введите x и y" << endl;
	cin >> x >> y;
	cout << "Сумма: " << x + y << endl;
	cout << "Разность: " << x - y << endl;
	cout << "Произведение: " << x * y << endl;
	if (y != 0)
	{
		cout << "Частное: " << x / y << endl;
	}
	else
		cout << "Деление невозможно \n";
}