#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	// "��� ���������"
	double a, b, c, D;
	cout << "������� a, b � c ��� ��������� ���� ax^2 + bx + c = 0 \n";
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b != 0)
			cout << "x = " << (-c) / b << endl;
		else if (c == 0)
			cout << "x - ����� �����" << endl;
		else
			cout << "������ ���" << endl;
	}
	else
	{
		D = b * b - 4 * a*c;
		if (D == 0)
			cout << "x = " << (-b) / (2 * a) << endl;
		if (D < 0)
			cout << "������ ���" << endl;
		if (D > 0)
		{
			cout << "x1 = " << ((-b) + sqrt(D)) / (2 * a) << endl;
			cout << "x2 = " << ((-b) - sqrt(D)) / (2 * a) << endl;
		}
	}
}