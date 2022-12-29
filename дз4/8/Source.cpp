#include <iostream>
#include <locale>

using namespace std;

int max(float arr[], int n)
{
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[maxi])
			maxi = i;
	}
	return maxi + 1;
}

int min(float arr[], int n)
{
	int mini = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[mini])
			mini = i;
	}
	return mini + 1;
}

int main()
{
	float a[3][4] =
	{
		{ 5, 2, 0, 10 },
		{ 3, 5, 2, 5 },
		{ 20, 0, 0, 0 }
	};

	float b[4][2] =
	{
		{ 1.2, 0.5 },
		{ 2.8, 0.4 },
		{ 5.0, 1.0 },
		{ 2.0, 1.5 }
	};

	float c[3][2] =
	{
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 }
	};
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++)
				c[i][j] += a[i][k] * b[k][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	float s1[3] = { c[0][0], c[1][0], c[2][0] }, s2[3] = { c[0][1], c[1][1], c[2][1] };

	cout << "1) Продавец с наибольшей выручкой: " << max(s1,3) << ". С наименьшей: " << min(s1, 3) << endl;
	cout << "2) Продавец с наибольшими комиссионными: " << max(s2, 3) << ". С наименьшими: " << min(s2, 3) << endl;
	cout << "3) Общая выручка: " << c[0][0] + c[1][0] + c[2][0] << endl;
	cout << "4) Общие комиссионные: " << c[0][1] + c[1][1] + c[2][1] << endl;
	cout << "5) Общий оборот: " << c[0][1] + c[1][1] + c[2][1] + c[0][0] + c[1][0] + c[2][0];


}