#include <iostream>

using namespace std;

void clearArray(bool**, int);
void showArray(bool**, int);

int main()
{
	setlocale(LC_ALL, "Rus");

	int N{};
	cout << "Введите размер квадратной матрицы: ";
	cin >> N;
	bool** arr = new bool* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new bool[N];

	clearArray(arr, N);

	cout << endl;
	showArray(arr, N);
	cout << endl;

	char action{};
	do
	{
		cout << "Выберете действие:\n\n0 - завершить работу\n1 - заполнить по диагонали\n2 - заполнить по обратной диагонали\n"
			<< "3 - заполнить зигзагом\n4 - заполнить все, кроме диагоналей\n\nВаш выбор: ";
		cin >> action;
		cout << endl;

		switch (action)
		{
		case '0':
			break;
		case '1': // Заполнение по главной диагонали
			for (int i = 0; i < N; i++)
				arr[i][i] = 1;
			showArray(arr, N);
			clearArray(arr, N);
			break;
		case '2': // Заполнение по обратной диагонали
			for (int i = N - 1; i >= 0; i--)
				arr[N - i - 1][i] = 1;
			showArray(arr, N);
			clearArray(arr, N);
			break;
		case '3': // Заполнение зигзагом
			for (int i = 0; i < N; i++)
				arr[0][i] = 1;
			for (int i = 1; i < N - 1; i++)
				arr[i][i] = 1;
			for (int i = 0; i < N; i++)
				arr[N - 1][i] = 1;
			showArray(arr, N);
			clearArray(arr, N);
			break;
		case '4': // Заполнение кроме диагоналей
			for (int i = 0; i < N; i++)
				for (int k = 0; k < N; k++)
					if (i != k && i != N - k - 1) arr[i][k] = 1;
			showArray(arr, N);
			clearArray(arr, N);
			break;
		default:
			cout << "Введите цифру из предложенных:";
			break;
		}

		cout << endl;
	} while (action != '0');

	system("pause");
	return 0;
}

void clearArray(bool** arr, int N)
{
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			arr[i][k] = 0;
}

void showArray(bool** arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
			cout << arr[i][k] << ' ';
		cout << endl;
	}
}