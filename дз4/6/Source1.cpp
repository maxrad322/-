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
	cout << "������� ������� �����:" << endl;
	cin >> romanValue;
	/*
	^M{0,3} - �� 0 �� 3 �������� M � ������ ������ ^
	(CM|CD|D?C{0,3})? - ���� ���� CM ��� ���� ���� CD, ��� D(�� �����������), �� ������� ���� �� 0 �� 3  C. ���� ���� �� ����������(����������)	
	*/
	regex regular("^M{0,3}(CM|CD|D?C{0,3})?(XC|XL|L?X{0,3})?(IX|IV|V?I{0,3})?");

	if (!(regex_match(romanValue, regular))) {
		cout << "������� ������������ �����";
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
			// ����� ������ ��������� 
			if (n0 > n1) {
				arabValue += n0;
				n0 = n1;
			}
			else if (n0 == 0)
				n0 = n1;
			// �����
			else if (n0 == n1) {
				arabValue += 2 * n1;
				n0 = 0;
			}
			// ������
			else {
				arabValue += n1 - n0;
				n0 = 0;
			}
		}
		cout << arabValue + n0;
	}
}