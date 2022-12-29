#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 13
int main() {

	setlocale(LC_ALL, "rus");
	cout << "Введите количество целых чисел n: ";
	int n;
	cin >> n;
	vector<int> numbers;
	ofstream file("file-5-1.txt");
	while (file.is_open()) {
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			file << x << endl;
			numbers.push_back(x);
		}
		file.close();
	}

	ofstream file1("file-5-2.txt");
	if (n == 1) {
		file1 << numbers[0];
		file1.close();
	}
	else {
		int maxcount = 0, count = 1;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 1; i++) {
			if (numbers[i] == numbers[i + 1]) {
				count += 1;
				if (count > maxcount)
					maxcount = count;
			}
			else
				count = 1;
		}
		count = 1;
		for (int i = 0; i < numbers.size() - 1; i++) {
			if (numbers[i] == numbers[i + 1]) {
				count += 1;
				if (count == maxcount)
					file1 << numbers[i] << endl;
			}
			else
				count = 1;
		}
	}

	ifstream f;
	f.open("file-5-1.txt");
	string str;
	cout << "Вывод первого файла: " << endl;
	while (!f.eof()) {
		str = "";
		getline(f, str);
		cout << str << endl;
	}

	ifstream f1;
	f1.open("file-5-2.txt");
	cout << "Вывод второго файла: " << endl;
	while (!f1.eof()) {
		str = "";
		getline(f1, str);
		cout << str << endl;
	}
	
	
	
}
	 