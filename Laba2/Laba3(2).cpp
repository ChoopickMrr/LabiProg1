#include "iostream"
#include "string"

using namespace std;

void showPrimeNumbers(unsigned int max)
{
	if (max < 1)
	{
		cerr << "������: ������� ����� ������ 0\n";
		system("pause");
		exit(2);
	}

	bool flg{ true };
	for (unsigned int i = 1; i <= max; i++)
	{
		flg = true;
		for (unsigned int k = 2; k < i; k++)
		{
			if (i % k == 0)
			{
				flg = false;
				break;
			}
		}
		if (flg == true) cout << i << endl;
	}
}

int main()
{
	setlocale(0, "");
	long int N, x;
	char ent, fact, pchi;
	fact = 'f', pchi = 'p';
	cout << "��������, ��� �� ������ ������� � ������, ���� ����� ��������������� �������\n\n		1. ���������� ��������� - f\n		2. ������� ��� ������� ����� �� 0 �� ��������� ����� - p";
	cin >> ent;
	if (ent == fact) {
		cout << "������� ����� ��� �������� ����������\n\n";
		cin >> N;
		x = 1;
		do
		{
			if (N > 1) x *= N--;
		} while (N > 1);
		cout << x << endl;
		cout << "\n\n";
		system("pause");
		return 0;
	}
	if (ent == pchi) {
		cout << "������� ����� ��� ������ ������� ����� �� 0 �� ���������";
		cin >> N;
		showPrimeNumbers(N);
		system("pause");
		return 0;
	}
}