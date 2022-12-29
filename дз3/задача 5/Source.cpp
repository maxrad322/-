#include <locale>
#include <iostream>

using namespace std;

int main() {
	string sourceString;
	cin >> sourceString;
	string ans;
	char min = sourceString[0];
	int mini = 0;
	int arraySize = sourceString.length();
	for (char j : sourceString) {
		for (int i = 0; i < arraySize; ++i) {
			if (sourceString[i] < min) {
				min = sourceString[i];
				mini = i;
			}
		}
		ans += min;
		sourceString.erase(mini, 1);
		mini = 0;
		min = sourceString[0];
		arraySize = sourceString.length();
	}
	cout << ans;
}