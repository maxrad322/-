#define _USE_MATH_DEFINES
#include <iostream>
#include <locale>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

double �������_������������(double a, double b, double c)
{
	vector <int> vec(3);
	vec[0] = a;
	vec[1] = b;
	vec[2] = c;
	sort(vec.begin(), vec.begin() + 3);

	if (a <= 0 || b <= 0 || c <= 0 || (vec[0] + vec[1] <= vec[2]))
	{
		cout << "��������� ������ �����������";
		exit(0);
	}
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double �������_��������������(double a, double b)
{
	if (a <= 0 || b <= 0)
	{
		cout << "��������� ������ �����������";
		exit(0);
	}
	return a * b;
}

double �������_�������(double r)
{
	if (r <= 0)
	{
		cout << "��������� ������ �����������";
		exit(0);
	}
	return r * r * M_PI;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int geomf = 0;
	do {
		cout << "�������� ������: �����������(1), �������������(2), ����(3)" << endl;
		cin >> geomf;
	} while (not (geomf == 1 or geomf == 2 or geomf == 3));

	if (geomf == 1)
	{
		cout << "������� ������� ������������(a, b, c)" << endl;
		double a, b, c;
		cin >> a >> b >> c;
		cout << "s = " << �������_������������(a, b, c);
	}
	if (geomf == 2)
	{
		cout << "������� ������� ��������������(a, b)" << endl;
		double a, b;
		cin >> a >> b;
		cout << "s = " << �������_��������������(a, b);
	}
	if (geomf == 3)
	{
		cout << "������� ������ �����(r)" << endl;
		double r;
		cin >> r;
		cout << "s = " << �������_�������(r);
	}
}