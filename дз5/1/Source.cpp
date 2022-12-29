#include <iostream>
#include <locale>
using namespace std;
int gcd_1(int num1, int num2) {
	num1 = abs(num1);
	num2 = abs(num2);
	while (num1 != 0 && num2 != 0) {
		if (num1 > num2) {
			num1 %= num2;
		}
		else {
			num2 %= num1;
		}
	}
	return num1 + num2;
}

//�������� �������. ���������
int gcd_2(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
		if (a >= b)
			a -= b;
		else
			b -= a;
	return a | b;
}

//������� �������

int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� 2 �����:" << endl;
	int a, b;
	cin >> a >> b;
	cout << "���: " << gcd_1(a, b) << endl;
	cout << "���: " << gcd_2(a, b);
}