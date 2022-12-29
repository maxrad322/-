#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
// "Функция"
int main()
{
	setlocale(LC_ALL, "rus");
	double b, y, x;
	cout << "Введите произвольные b, x и y." << endl;
	cin >> b >> x >> y;
	if (((b - y) > 0) && ((b - x) >= 0))
		cout << log(b - y) * sqrt(b - x);
	else
		cout << "функция не определена";
}