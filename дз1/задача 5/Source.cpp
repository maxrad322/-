#include <iostream>
#include <locale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	bool day, curtains, lamp;
	cout << "Сейчас день? (1,0). Шторы раздвинуты? (1,0) Лампа горит? (1,0)";
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