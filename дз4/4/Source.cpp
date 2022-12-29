#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 13; i++, cout << endl)
	{
		for (int j = 1; j < 50; j++)
		{
			if (i >= 1 and i <= 6 and j <= 8)
				cout << "*";
			else
				cout << "_";
		}
	}
}