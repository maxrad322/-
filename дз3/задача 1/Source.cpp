#include <iostream>
#include <locale>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	double r, p, S, n, m;
	do {
		cout << "¬ведите S, p и n" << endl;
		cin >> S >> p >> n;
	} while (S <= 0 and p <= 0 and n <= 0);
	r = p / 100;
	m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
	cout << "m = " << m;
}