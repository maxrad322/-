#include <iostream>
#include <locale>
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	double S, m, n, ans = 0, min_inaccuracy, p, r, m_new, inaccuracy;
	min_inaccuracy = pow(10, 9);
	do {
		cout << "¬ведите S, m и n" << endl;
		cin >> S >> m >> n;
	} while (S <= 0 and m <= 0 and n <= 0);

	for (p = 0; p <= 100000; p += 0.1)
	{
		r = p / 100;
		m_new = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		inaccuracy = abs(m_new - m);

		if (inaccuracy < min_inaccuracy)
		{
			min_inaccuracy = inaccuracy;
			ans = p;
		}
	}
	cout << "p = " << ans;
}