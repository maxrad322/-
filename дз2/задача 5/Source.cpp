#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	for (float i = (-4); i <= 4; i += 0.5)
	{
		if (i == 1)
		{
			cout << "x = 1 " << "	деление на ноль" << endl;
			continue;
		}
		cout << fixed;
		cout << setprecision(2);
		cout << "x = " << i << " y = " << (i*i - 2 * i + 2) / (i - 1) << endl;
	}
}