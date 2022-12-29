#include <iostream>
#include <locale>
#include <set>
#include <cmath>
using namespace std;
set <int> divs(int n) {
	set <int> d;
	for (int i = 2; i < round(sqrt(n) + 1); i++) {
		if (n % i == 0) {
			d.insert(i);
			d.insert(n / i);
		}
	}
	return d;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "¬ведите n: ";
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (divs(i).size() == 0)
			cout << i << " ";
	}
}
