#include <iostream>

using namespace std;

int sign(double x)
{
	if (x > 0)
		return 1;
	else if (x == 0) 
		return 0;
	else
		return -1;
}

int main()
{
	double x;
	cin >> x;
	cout << sign(x);
	return 0;
}
