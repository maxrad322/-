#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
// "�������"
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� N" << endl;
	double N;
	cin >> N;
	if (N < 1)
		N = 1;
	else
		N = int(N) + 1;
	for (int i = 0; i < 10; i++)
		cout << N + i << " ";
}