#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
// "�������"
int main()
{
	setlocale(LC_ALL, "rus");
	double b, y, x;
	cout << "������� ������������ b, x � y." << endl;
	cin >> b >> x >> y;
	if (((b - y) > 0) && ((b - x) >= 0))
		cout << log(b - y) * sqrt(b - x);
	else
		cout << "������� �� ����������";
}