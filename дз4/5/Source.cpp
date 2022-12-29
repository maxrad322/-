#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float epsilon = 0.05;
	for (float y = 1.0; y >= -1.1; y -= 0.2)
	{
		for (float x = -2 * M_PI; x <= 2 * M_PI; x += M_PI / 16) {
			if (abs(sin(x) - y) >= epsilon) {
				if (abs(y) < epsilon)
					cout << "-";
				else
					cout << " ";
			}
			else 
				cout << "*";
			if (abs(x) < epsilon)
				cout << "|";        
		}
		cout << endl;
	}
}

