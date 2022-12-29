#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <locale>

using namespace std;
//MMMCMXCIX - 3999

int main() {
	setlocale(LC_ALL, "rus");
	string romanValue;
	cout << "Введите римское число:" << endl;
	cin >> romanValue;
	/*
	^M{0,3} - От 0 до 3 символов M в начале строки ^
	(CM|CD|D?C{0,3})? - Одна пара CM или одна пара CD, или D(не обязательно), за которым идет от 0 до 3  C. Весь блок не обязателен(опционален)	
	*/
	regex regular("^M{0,3}(CM|CD|D?C{0,3})?(XC|XL|L?X{0,3})?(IX|IV|V?I{0,3})?");

	if (!(regex_match(romanValue, regular))) {
		cout << "введено некорректное число";
		exit(0);
	}

	else {
		map <char, int> numbers;
		numbers['I'] = 1;
		numbers['V'] = 5;
		numbers['X'] = 10;
		numbers['L'] = 50;
		numbers['C'] = 100;
		numbers['D'] = 500;
		numbers['M'] = 1000;

		int arabValue = 0, n0 = 0;

		for (char i : romanValue) {
			int n1 = numbers[i];
			// цифра больше следующей 
			if (n0 > n1) {
				arabValue += n0;
				n0 = n1;
			}
			else if (n0 == 0)
				n0 = n1;
			// равны
			else if (n0 == n1) {
				arabValue += 2 * n1;
				n0 = 0;
			}
			// меньше
			else {
				arabValue += n1 - n0;
				n0 = 0;
			}
		}
		cout << arabValue + n0;
	}
}