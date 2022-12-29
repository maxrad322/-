#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

double denominator(int m) {
	int count = 0;
	for (int i = 1; i < m; i++)
		count += i;
	int sum = 0;
	for (int i = count + 1; i <= count + m; i++)
		sum += i;
	return sqrt(sum);
}
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
int numerator(int m, int n) {
	int sign;
	if (m % 2 == 0)
		sign = -1;
	else
		sign = 1;
	return sign * fact(n - (m - 1));
}

// 12
int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите число n: ";
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		cout << numerator(i, n) / denominator(i) << " ";
		sum += numerator(i, n) / denominator(i);
	}
	cout << endl;
	cout << "Cумма из n-слагаемых: " << sum;
}