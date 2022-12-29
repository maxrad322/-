#include <iostream>
#include <cmath>
#include <locale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите кол-во лопастей (M): ";
	int n;
	cin >> n;
	if (n >= 3) {
		for (int i = 0; i <= n / 4; i++) {
			for (int j = 0; j <= n / 3; j++) {
				if (n == i * 4 + j * 3) {
					cout << "кол-во спинеров с 3-мя лопастями: "<< j << endl << "кол-во спинеров с 4-мя лопастями: " << i;
					exit(0);
				}
			}
		}
	}
	cout << "кол-во спинеров с 3-мя лопастями: " << 0 << endl << "кол-во спинеров с 4-мя лопастями: " << 0;
}