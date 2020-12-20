#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");
	int a, b;
	cout << "Посчитать a + b" << endl;
	cout << "Введите число a:" << endl;
	cin >> a;
	cout << "Введите число b:" << endl;
	cin >> b;
	int c = a + b;
	cout << "Ответ:" << c << endl;
	system("pause");
	return 0;
}
