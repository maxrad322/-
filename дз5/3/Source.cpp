#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;

// 13
int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	cout << "������� ����� (��� ����������� ������ ������ ������� \"0\" � ����� ������):" << endl;
	string text;

	ofstream file("text.txt");
	while (file.is_open())
	{
		getline(cin, text);
		if (text == "0")
			exit(0);
		file << text << endl;
	}
}