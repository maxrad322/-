#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	// "����������"
	float x, y;
	cout << "������� x � y" << endl;
	cin >> x >> y;
	cout << "�����: " << x + y << endl;
	cout << "��������: " << x - y << endl;
	cout << "������������: " << x * y << endl;
	if (y != 0)
	{
		cout << "�������: " << x / y << endl;
	}
	else
		cout << "������� ���������� \n";
}