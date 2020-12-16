#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число которое хотите умножить на 2:\n\n";
	int a;
	cin >> a;
	cout << "\n";
	cout << "Ответ: " << a * 2 << endl;
	return 0;
}
