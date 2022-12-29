#include <iostream>
#include <locale>
using namespace std;
int main() {
	int a, b, c, res = 0, n = 0;
	setlocale(LC_ALL,"rus");
	cout << "¬ведите стоимость основани€ спинера, cтоимость лопасти и максимальную стоимость спинера (a, b, c): " << endl;
	cin >> a >> b >> c;
	while ((a + b * n) <= c) {
		res = n;
		n++;
	}
	cout << "ћаксимальное кол-во лопастей: " << res;
}