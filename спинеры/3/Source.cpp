#include <iostream>
#include <locale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ���������� ����� (N x M): ";
	int m, n;
	cin >> m >> n;
	cout << "���-�� ��������������: ";
	cout << (n*(n + 1) / 2)*(m*(m + 1) / 2);
}