#include <iostream>

using namespace std;

void showMessage(int);

int main()
{
	for (int i = 1; i <= 15; i++)
	{
		switch (i)
		{
		case 1:
			showMessage(1);
			break;
		case 2:
			showMessage(2);
			break;
		case 3:
			showMessage(3);
			break;
		case 4:
			showMessage(4);
			break;
		case 5:
			showMessage(5);
			break;
		case 6:
			showMessage(6);
			break;
		case 7:
			showMessage(7);
			break;
		case 8:
			showMessage(8);
			break;
		case 9:
			showMessage(9);
			break;
		case 10:
			showMessage(10);
			break;
		case 11:
			showMessage(11);
			break;
		case 12:
			showMessage(12);
			break;
		case 13:
			showMessage(13);
			break;
		case 14:
			showMessage(14);
			break;
		case 15:
			showMessage(15);
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void showMessage(int i)
{
	cout << "Message # " << i << endl;
}