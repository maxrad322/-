#include <iostream>
#include <locale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	bool day, curtains, lamp;
	cout << "������ ����? (1,0). ����� ����������? (1,0) ����� �����? (1,0)";
	cin >> day >> curtains >> lamp;
	if (lamp) {
		cout << "Lightly";
	}
	else if (day & curtains) {
		cout << "Lightly";
	}
	else {
		cout << "Dark";
	}
	return 0;
}