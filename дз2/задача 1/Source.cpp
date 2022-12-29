#define _USE_MATH_DEFINES
#include <iostream>
#include <locale>
#include <math.h>
#include <cmath>
using namespace std;
// "Конус"
int main()
{
	setlocale(LC_ALL, "rus");
	double V, S, R = -999, r = -999, h = -999, l;

	while ((R < 0) || (r < 0) || (h <= 0))
	{
		cout << "Введите данные для вычисления объема и площади конуса (R, r, h)." << endl;
		cin >> R >> r >> h;
	}
	l = sqrt(h*h + (R - r) * (R - r));
	V = (M_PI * h * (R * R + R * r + r * r)) / 3.0;
	S = M_PI * (R * R + (R + r) * l + r * r);
	cout << "V = " << V << endl << "S = " << S;
}