#include <iostream>
#include <locale>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите кол-во свободных мест в вагоне: ";
	int n;
	cin >> n;
	vector <int> a(54);
	for (int i = 0; i < 54; i++)
		a[i] = 0;

	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		a[in-1] = 1;
	}

	int k = 0, count = 0;
	for (int i = 0; i < 36; i += 4) {
		bool kupe = true;
		for (int j = 0; j < 4; j++) {
			kupe = kupe and a[i + j];
		}
		if (kupe and a[54 - 2 * k - 1] and a[54 - 2 * k - 2]) count++;
		k++;
	}
	cout << "—вободных купе: " << count;
	return 0;
}