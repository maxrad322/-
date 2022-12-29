#include <iostream>
#include <locale>
using namespace std;

int gcd_1(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

int gcd_2(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
		if (a >= b)
			a -= b;
		else
			b -= a;
	return (a == 0 ? b : a);
}

int main() {
	setlocale(LC_ALL, "rus");
	int a, b;
	do {
		cout << "Введите 2 числа (не равные 0):" << endl;
		cin >> a >> b;
	} while (a == 0 or b == 0);

	cout << "НОД: " << gcd_1(a, b) << endl;
	cout << "НОД: " << gcd_2(a, b);
}