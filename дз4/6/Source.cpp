#include <iostream>
#include <map>
#include <regex>

using namespace std;

bool IsValidRoman(string s)
{
	regex rgx("^M{0,3}(CM|CD|D?C{0,3})?(XC|XL|L?X{0,3})?(IX|IV|V?I{0,3})?");
	return regex_match(s, rgx);
}

int FromRoman(string s)
{
	if (!IsValidRoman(s))
	{
		cout << "Incorrect number!";
		exit(0);
	}

	map <char, int> numbers;
	numbers['I'] = 1;
	numbers['V'] = 5;
	numbers['X'] = 10;
	numbers['L'] = 50;
	numbers['C'] = 100;
	numbers['D'] = 500;
	numbers['M'] = 1000;

	int res = 0;
	int temp = 0;

	for (char c : s)
	{
		int n = numbers[c];

		if (n < temp) // Меньшая цифра стоит после большей
		{
			res += temp;
			temp = n;
		}
		else if (n > temp)
		{
			if (temp == 0) // Все цифры до этой обработаны / это первая считанная цифра
			{
				temp = n;
			}
			else // Меньшая цифра стоит перед большей
			{
				res += n - temp;
				temp = 0;
			}
		}
		else // Две одинаковые цифры подряд
		{
			res += temp + n;
			temp = 0;
		}
	}

	return res + temp; // В temp могла остаться необработанная цифра
}

int main()
{
	string n;
	cin >> n;
	cout << FromRoman(n);
	return 0;
}