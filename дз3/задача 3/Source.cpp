#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out("kaifarik.txt");
	string str0;
	cout << "¬ведите кол-во строк:" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "¬ведите строку " << i+1 << ":" << endl;
		cin >> str0;
		out << str0 << endl;
	}
	out.close();

	ifstream file("kaifarik.txt");
	string str;
	while (getline(file, str))
		cout << str << endl;
	file.close();
}