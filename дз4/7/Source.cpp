#include <iostream>

using namespace std;

int i;
const int m = 64, a = 37, c = 3, s0 = 0;

int random(int i)
{
	if (i == 0)
		return s0;
	return (a * random(i - 1) + c) % m;
}

int main()
{
	cin >> i;
	cout << random(i + 1);
}
