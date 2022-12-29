#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	//  "Уравнение" 
	double B, C;
	cout << "Введите b и c для уравнения вида bx + c = 0 \n";
	cin >> B >> C;
	if (B != 0)
		cout << "x = " << (-C) / B << endl;
	else if (C == 0)
		cout << "x - любое число" << endl;
	else
		cout << "Корней нет" << endl;
}