#include "iostream"

using namespace std;

int main()
{
	setlocale(0, "");
	cerr << "			Добро пожаловать!\n\n			Для получения информации о валюте\n			введите соответствующую клавишу\n\n			d - Доллар  e - Евро  g - Гривны\n			f - Фунты  b - Иены c - Кроны\n";
	char ent, dol, evr, griv, funt, b, cron;
	dol = 'd'; evr = 'e'; griv = 'g';
	cin >> ent;
	if (ent == dol) {
		cout << "\nДоллар - это... (типо подробная информация)\n\n";
	}
	if (ent == evr) {
		cout << "\nЕвро - это... (типо подробная информация)\n\n";
	}
	if (ent == griv) {
		cout << "\nГривны - это... (типо подробная информация)\n\n";
	}
	switch (ent)
	{
	case 'f':
		cout << "\nФунты - это... (типо подробная информация)\n\n";
	}
	switch (ent)
	{
	case 'b':
		cout << "\nИена - это... (типо подробная информация)\n\n";
	}
	switch (ent)
	{
	case 'c':
		cout << "\nКрона - это... (типо подробная информация)\n\n";
	}
	system("pause");
	return 0;
}