#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");
	int a, b;
	cout << "��������� a + b" << endl;
	cout << "������� ����� a:" << endl;
	cin >> a;
	cout << "������� ����� b:" << endl;
	cin >> b;
	int c = a + b;
	cout << "�����:" << c << endl;
	system("pause");
	return 0;
}
