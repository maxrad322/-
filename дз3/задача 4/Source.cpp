#include <iostream>
#include <locale>
#include <fstream>
using namespace std;

int main()
{
	ofstream out("filtr.txt");
	string s0 = "qwrg552qwe", s1 = "1234", s2 = "qw56e", s3 = "qweerweq2";
	out << s0 << s1 << s2 << s3 << endl;
	out.close();

	ifstream file("filtr.txt");
	string str, s;
	bool flag = 0;
	while (getline(file, str)) {
		for (char c : str) {
			if (isdigit(c)) {
				s += c;
				flag = 1;
			}
			else if (flag == 1) {
				s += " ";
				flag = 0;
			}	
		}
	}
	if (s.length() > 0)
		cout << s;
	else
		cout << "В файле нет чисел";
	file.close();
}