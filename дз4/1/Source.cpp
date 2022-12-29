#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "¬ведите 10 чисел" << endl;
	ofstream out("числа.txt");
	double numb1, numb2, sum = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> numb1;
		out << numb1 << endl;
	}
	out.close();
	ifstream in("числа.txt");
	while (in >> numb2)
		sum += numb2;
	cout << "сумма = " << sum;
}
