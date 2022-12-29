#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

double denominator(int k) {
	
	double sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += 1 / (double)i;
	}
	
	return pow(sum,k);
}

// 13
int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите число n: ";
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		cout << fact(i) / denominator(i) << " ";
		sum += fact(i) / denominator(i);
	}
	cout << endl;
	cout << "Cумма: " << sum;
}