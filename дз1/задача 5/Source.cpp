#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	// "Еще уравнение"
	double a, b, c, D;
	cout << "Введите a, b и c для уравнения вида ax^2 + bx + c = 0 \n";
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b != 0)
			cout << "x = " << (-c) / b << endl;
		else if (c == 0)
			cout << "x - любое число" << endl;
		else
			cout << "Корней нет" << endl;
	}
	else
	{
		D = b * b - 4 * a*c;
		if (D == 0)
			cout << "x = " << (-b) / (2 * a) << endl;
		if (D < 0)
			cout << "Корней нет" << endl;
		if (D > 0)
		{
			cout << "x1 = " << ((-b) + sqrt(D)) / (2 * a) << endl;
			cout << "x2 = " << ((-b) - sqrt(D)) / (2 * a) << endl;
		}
	}
}