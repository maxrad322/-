#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
// "������������"
int main()
{
	setlocale(LC_ALL, "rus");
	float a, x;
	cout << "������� ������������ a � x." << endl;
	cin >> a >> x;
	if ((abs(x) < 1) && (x != 0))
		cout << a * log(abs(x));
	else if ((abs(x) >= 1) && ((a - x * x) >= 0))
		cout << sqrt(a - x * x);
	else
		cout << "������� �� ����������";
}