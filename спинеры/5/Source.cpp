#include <iostream>
#include <vector>
#include <locale>
using namespace std;

int main() {
	int n, k;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите кол-во зрительских мест (n) и школьников (k): " << endl;
	cin >> n >> k;
	vector <int> a = {n};
	for (int i = 1; i <= k; i++) {
		int max = 0, d;
		for (int j = 0; j < size(a); j++) {
			if (a[j] > max) {
				max = a[j];
				d = j;
			}
		}
		a[d] = 0;
		a.push_back(max / 2);
		a.push_back(max - max / 2 - 1);
	}
	cout << " оличество свободных мест от последнего школьника: " << endl;
	cout << a[size(a) - 1] << endl << a[size(a) - 2];
}