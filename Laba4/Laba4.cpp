#include <iostream>
#include <Windows.h>
using namespace std;

class Person
{
private:
	int id{ -1 };
	string name{ "NONE" };
	int age{ -1 };
	float height{ -1 };
public:
	Person() : id(-1), name("NONE"), age(-1), height(-1)
	{ }

	int getID() const { return id; }
	string getName() const { return name; }
	int getAge() const { return age; }
	float getHeight() const { return height; }
	void showInfo() const
	{
		cout << "ID: " << id << "\tИмя: " << name << "\tВозраст: " << age << "\tРост: " << height << endl;
	}

	void setID()
	{
		cout << "Введите ID: ";
		cin >> id;
	}
	void setName()
	{
		cout << "Введите имя: ";
		cin >> name;
	}
	void setAge()
	{
		cout << "Введите возраст: ";
		cin >> age;
	}
	void setHeight()
	{
		cout << "Введите рост: ";
		cin >> height;
	}
	void setInfo();
};

void Person::setInfo()
{
	setID();
	setName();
	setAge();
	setHeight();
}

Person* findByID(Person*, const int N, const int id);

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	int people_count{ 0 };
	cout << "Введите количество людей: ";
	cin >> people_count;
	if (people_count < 1)
	{
		cerr << "Введите кол-во больше 0\n";
		system("pause");
		return 1;
	}
	Person* people = new Person[people_count];

	for (int i = 0; i < people_count; i++)
	{
		cout << "\nВвод информации о " << i + 1 << " человеке:\n";
		people[i].setInfo();
	}

	
	int decision{ 0 };
	bool flg = true;
	int id{ -1 };
	Person* prsn{ NULL };
	do
	{
		cout << "\nВыберите действие:\n\n\t0 - завершить работу\n\t1 - посмотреть список имен и их ID\n\t2 - посмотреть всю информацию о человеке которого вы выберите\n\t3 - изменить конкретную информацию о человеке которого вы выберите\n"
			<< "\nВведите цифру действия которое хотите выполнить: ";
		cin >> decision;

		switch (decision)
		{
		case 0:
			flg = false;
			break;
		case 1:
			cout << "\n\tID\tИмя\n";
			for (int i = 0; i < people_count; i++)
				cout << "\n\t" << people[i].getID() << '\t' << people[i].getName() << endl;
			break;
		case 2:
			cout << "\nВведите ID человека: ";
			cin >> id;
			cout << "\n\t";
			prsn = findByID(people, people_count, id);
			if (prsn != NULL) prsn->showInfo();
			else cout << "Человека с таким ID не найдено\n";
			prsn = NULL;
			break;
		case 3:
			cout << "\nВведите ID человека: ";
			cin >> id;
			cout << "\n\t";
			prsn = findByID(people, people_count, id);
			if (prsn != NULL)
			{
				cout << "Введите измененную информацию:\n\n";
				prsn->setInfo();
			}
			else cout << "Человека с таким ID не найдено\n";
			prsn = NULL;
			break;
		default:
			cout << "\nВведите цифру из предложенных\n";
			break;
		}
	} while (flg);

	delete[] people;
	people = NULL;
	system("pause");
	return 0;
}

Person* findByID(Person* people, const int N, const int id)
{
	for (int i = 0; i < N; i++)
	{
		if (id == people[i].getID())
		{
			return &people[i];
			break;
		}
	}
	return NULL;
}