#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// 1
int main()
{
	string s;
	vector<string> lines;
	char symb;
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");

	cout << "¬ведите текст (дл€ прекращени€ записи текста введите \"0\" с новой строки):" << endl;
	string text;

	ofstream file("File.txt");
	while (file.is_open())
	{
		getline(cin, text);
		if (text == "0")
			break;
		file << text << endl;
	}
	file.close();

	ifstream file1("File.txt");
	while (!file1.eof())
	{
		getline(file1, s);
		lines.push_back(s);
	}

	cout << "¬ведите символ дл€ замены пробела: " << endl;
	cin >> symb;
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[i].size(); j++)
		{
			if (lines[i][j] == ' ')
			{
				lines[i][j] = symb;
			}
		}
	}

	for (int i = 0; i < lines.size(); i++)
	{
		cout << lines[i] << endl;
	}

	ofstream out("File.txt");
	out.clear();
	for (int i = 0; i < lines.size(); i++)
	{
		out << lines[i] << endl;
	}
}