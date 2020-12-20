#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

using namespace std;

string toText(string);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char response{ 'y' };
	do {
		string number;
		cout << "Введите число: ";
		cin >> number;
		cout << "\n\tВаше число: " << toText(number) << endl;

		cout << "\nХотите продолжить?\nЕсли да, то введите - y\tЕсли нет, то введите - n: ";
		cin >> response;
		cout << endl;
	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}

string toText(string num_str)
{
	string result{ "" };
	int num_len{ static_cast<int>(num_str.length()) };

	long long num_int = { stoll(num_str) };
	if (num_len > 10 || num_int > ULONG_MAX)
	{
		cerr << "Ошибка: Введенное число больше диапазона unsigned long int!\n";
		system("pause");
		exit(1);
	}
	else if (num_int < 0)
	{
		cerr << "Ошибка: Введите число больше или равное 0!\n";
		system("pause");
		exit(2);
	}
	else if (num_int == 0)
		return "zero";

	if (num_len % 3 == 1) num_str.insert(0, 2, '0');
	else if (num_len % 3 == 2) num_str.insert(0, 1, '0');

	num_len = num_str.length();

	int triplet_count{ static_cast<int>(num_len / 3) };
	for (int i = triplet_count; i > 0; i--)
	{
		int x{ stoi(num_str.substr(num_len - 3 * i, 3)) };

		if (x == 0) continue;

		int hundreds_count{ x / 100 };
		int decades_count{ (x / 10) % 10 };
		int units_count{ x % 10 };
		if (decades_count < 2)
		{
			units_count += decades_count * 10;
			decades_count = 0;
		}

		switch (hundreds_count)
		{
		case 1:
			result += "one hundred ";
			break;
		case 2:
			result += "two hundred ";
			break;
		case 3:
			result += "three hundred ";
			break;
		case 4:
			result += "four hundred ";
			break;
		case 5:
			result += "five hundred ";
			break;
		case 6:
			result += "six hundred ";
			break;
		case 7:
			result += "seven hundred ";
			break;
		case 8:
			result += "eight hundred ";
			break;
		case 9:
			result += "nine hundred ";
			break;
		default:
			break;
		}

		switch (decades_count)
		{
		case 2:
			result += "twenty ";
			break;
		case 3:
			result += "thirty ";
			break;
		case 4:
			result += "fourty ";
			break;
		case 5:
			result += "fifty ";
			break;
		case 6:
			result += "sixty ";
			break;
		case 7:
			result += "seventy ";
			break;
		case 8:
			result += "eighty ";
			break;
		case 9:
			result += "ninety ";
			break;
		default:
			break;
		}

		switch (units_count)
		{
		case 1:
			result += "one ";
			break;
		case 2:
			result += "two ";
			break;
		case 3:
			result += "three ";
			break;
		case 4:
			result += "four ";
			break;
		case 5:
			result += "five ";
			break;
		case 6:
			result += "six ";
			break;
		case 7:
			result += "seven ";
			break;
		case 8:
			result += "eight ";
			break;
		case 9:
			result += "nine ";
			break;
		case 10:
			result += "ten ";
			break;
		case 11:
			result += "eleven ";
			break;
		case 12:
			result += "twelve ";
			break;
		case 13:
			result += "thirteen ";
			break;
		case 14:
			result += "fourteen ";
			break;
		case 15:
			result += "fifteen ";
			break;
		case 16:
			result += "sixteen ";
			break;
		case 17:
			result += "seventeen ";
			break;
		case 18:
			result += "eighteen ";
			break;
		case 19:
			result += "nineteen ";
			break;
		default:
			break;
		}

		switch (i)
		{
		case 4:
			result += "billion ";
			break;
		case 3:
			result += "million ";
			break;
		case 2:
			result += "thousand ";
			break;
		default:
			break;
		}
	}

	result.erase(result.length() - 1, 1);
	return result;
}