#include <iostream>

using namespace std;

int* fib(const int);
void show_fib(int*, const int);

int main()
{
	setlocale(LC_ALL, "Rus");

	char response{ 'y' };
	int* fib_arr{ NULL };
	int N{ 0 };
	do
	{
		cout << "Введите количество элементов последовательности Фибоначчи: ";
		cin >> N;
		fib_arr = fib(N);
		show_fib(fib_arr, N);
		delete[] fib_arr;
		fib_arr = NULL;

		cout << "\nХотите продолжить?\nЕсли да, то введите - y\tЕсли нет, то введите - n: ";
		cin >> response;
		cout << endl;
	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}

int* fib(const int N)
{
	if (N < 2)
	{
		cerr << "Ошибка: введите число больше 1.\n";
		system("pause");
		exit(1);
	}

	int* arr = new int[N];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < N; i++)
		arr[i] = arr[i - 2] + arr[i - 1];
	return arr;
}

void show_fib(int* fib_arr, const int N)
{
	cout << "\n\tfib(" << N << "): -> ";
	for (int i = 0; i < N; i++)
		cout << fib_arr[i] << ',';
	cout << endl;
}