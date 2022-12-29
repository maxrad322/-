#include <iostream>
using namespace std;

int c = 0;

void perestanovki(int t, int n, int a[]) {
	if (t == n - 1) {
		for (int i = 0; i < n; ++i) {
			if (a[i] == i + 1) {
				c++;
				break;
			}
		}
	}
	else {
		for (int j = t; j < n; j++) {
			swap(a[t], a[j]);
			perestanovki(t + 1, n, a);
			swap(a[t], a[j]);
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, kol = 0;
	cout << "Введите n количество шариков:";
	cin >> n;
	int *a = new int[n];
	for (int el = 0; el < n; el++) {
		a[el] = el + 1;
	}
	perestanovki(0, n, a);
	cout << c;
}
