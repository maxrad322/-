#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	//  "���������" 
	double B, C;
	cout << "������� b � c ��� ��������� ���� bx + c = 0 \n";
	cin >> B >> C;
	if (B != 0)
		cout << "x = " << (-C) / B << endl;
	else if (C == 0)
		cout << "x - ����� �����" << endl;
	else
		cout << "������ ���" << endl;
}