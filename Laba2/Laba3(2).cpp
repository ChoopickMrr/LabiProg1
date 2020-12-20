#include "iostream"
#include "string"

using namespace std;

void showPrimeNumbers(unsigned int max)
{
	if (max < 1)
	{
		cerr << "ОШИБКА: введите число больше 0\n";
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
	cout << "Выберите, что вы хотите сделать с числом, путём ввода соответствующей клавиши\n\n		1. Подсчитать факториал - f\n		2. Вывести все простые числа до 0 до введённого числа - p";
	cin >> ent;
	if (ent == fact) {
		cout << "Введите число для подсчёта факториала\n\n";
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
		cout << "Введите число для вывода простых чисел от 0 до введённого";
		cin >> N;
		showPrimeNumbers(N);
		system("pause");
		return 0;
	}
}