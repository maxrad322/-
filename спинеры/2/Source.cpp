#include <iostream>
#include <cmath>
#include <locale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ���-�� �������� (M): ";
	int n;
	cin >> n;
	if (n >= 3) {
		for (int i = 0; i <= n / 4; i++) {
			for (int j = 0; j <= n / 3; j++) {
				if (n == i * 4 + j * 3) {
					cout << "���-�� �������� � 3-�� ���������: "<< j << endl << "���-�� �������� � 4-�� ���������: " << i;
					exit(0);
				}
			}
		}
	}
	cout << "���-�� �������� � 3-�� ���������: " << 0 << endl << "���-�� �������� � 4-�� ���������: " << 0;
}