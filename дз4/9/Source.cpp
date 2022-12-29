#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <locale>

using namespace std;

int main() {

	// ввод
	string x;
	int s1, s2;
	setlocale(LC_ALL, "rus");
	cout << "Введите число:" << endl;
	cin >> x;
	bool sin = 1;
	if (x[0] == '-') {
		x = x.substr(1,x.length() -1);
		sin = 0;
	}
	cout << "Введите его систему счисления:" << endl;
	cin >> s1;
	cout << "Введите новую систему счисления:" << endl;
	cin >> s2;

	// проверка длины и СС
	int n =  x.length();
	if (n > 20 or s2 < 2 or s1 < 2 or s2 > 16 or s1 > 16) {
		cout << "incorrect";
		exit(0);
	}

	// создание массива с цифрами числа в десятичном виде
	map <char, int> numbers;
	numbers['A'] = 10;
	numbers['B'] = 11;
	numbers['C'] = 12;
	numbers['D'] = 13;
	numbers['E'] = 14;
	numbers['F'] = 15;
	vector <int> a;
	for (char i : x) {
		int n1 = 0;
		n1 = numbers[i];
		if (n1 != 0)
			a.push_back(n1);
		else if (!(i - '0' >= 0 and i - '0' <= 9)) {
			cout << "incorrect";
			exit(0);
		}
		else 
			a.push_back(i - '0');
	}

	// проверка соответствия цифр изначальной СС
	for (int i : a) {
		if (i >= s1) {
			cout << "incorrect";
			exit(0);
		}
	}

	// перевод изначального числа в десятичное
	int x10 = 0, digitx = n-1, i = 0;
	while (digitx >= 0) {
		x10 += a[i] * pow(s1, digitx);
		i += 1;
		digitx -= 1;
	}

	// создание массива цифр числа, переведенного в новую СС
	map <int, char> numbers1;
	numbers1[10] = 'A';
	numbers1[11] = 'B';
	numbers1[12] = 'C';
	numbers1[13] = 'D';
	numbers1[14] = 'E';
	numbers1[15] = 'F';

	vector <int> a1;
	while (x10 > 0)
	{
		char n2;
		if (x10 % s2 < 0 or x10 % s2 > 9)
			n2 = numbers1[x10 % s2];
		else 
			n2 = '0' + (x10 % s2);
		a1.push_back(n2);
		x10 /= s2;
	}

	// проверка знака
	if (sin == 0)
		a1.push_back('-');

	// число в новой СС
	string ans;
	for (char i : a1) 
		ans = i + ans;

	// вывод
	cout << "Число " << x << " в системе счисления " << s2 << ": " << ans;
}
