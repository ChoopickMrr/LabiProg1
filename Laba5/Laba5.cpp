#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
using namespace std;

enum class veh_type { sportcar, motorcycle, truck };

class Vehicle
{
protected:
	veh_type type{ veh_type::sportcar };
	string brand{ "NONE" }; 
	string model{ "NONE" }; 
	float price{ 0.0F }; 
public:
	Vehicle() : type(veh_type::sportcar), brand("NONE"), model("NONE"), price(0.0F)
	{ }
	Vehicle(veh_type t) : type(t), brand("NONE"), model("NONE"), price(0.0F)
	{ }
	Vehicle(veh_type t, string brnd, string mdl, float prc) : type(t), brand(brnd), model(mdl), price(prc)
	{ }

	virtual void showInfo() const = 0;
};

class SportCar : public Vehicle
{
public:
	SportCar() : Vehicle(veh_type::sportcar)
	{ }
	SportCar(string brnd, string mdl, float prc) : Vehicle(veh_type::sportcar, brnd, mdl, prc)
	{ }

	void showInfo() const
	{
		cout << "Спорткар\tМарка: " << brand << "\tМодель: " << model << "\tЦена: " << price << "руб." << "\tНа складе: " << rand() % 10 << endl;
	}
};

class Motorcycle : public Vehicle
{
public:
	Motorcycle() : Vehicle(veh_type::motorcycle)
	{ }
	Motorcycle(string brnd, string mdl, float prc) : Vehicle(veh_type::motorcycle, brnd, mdl, prc)
	{ }

	void showInfo() const
	{
		cout << "Мотоцикл\tМарка: " << brand << "\tМодель: " << model << "\tЦена: " << price << "руб." << "\tНа складе: " << rand() % 10 << endl;
	}
};

class Truck : public Vehicle
{
public:
	Truck() : Vehicle(veh_type::truck)
	{ }
	Truck(string brnd, string mdl, float prc) : Vehicle(veh_type::truck, brnd, mdl, prc)
	{ }

	void showInfo() const
	{
		cout << "Грузовик\tМарка: " << brand << "\tМодель: " << model << "\tЦена: " << price << "руб." << "\tНа складе: " << rand() % 10 << endl;

	}
};

class Market
{
private:
	Vehicle** veh{ NULL };
	int veh_count{ 0 };
	int sportcar_count{ 0 };
	int moto_count{ 0 };
	int truck_count{ 0 };
public:
	Market() : veh(NULL), veh_count(5), sportcar_count(2), truck_count(1), moto_count(2)
	{
		veh = new Vehicle * [veh_count];
		veh[0] = new SportCar("Nissan", "GT-R", 8000000);
		veh[1] = new Motorcycle("BMW", "HP4 RACE", 5500000);
		veh[2] = new Truck("Peterbilt", "379", 3000000);
		veh[3] = new SportCar("Mercedes-Benz", "SLR McLaren", 80000000);
		veh[4] = new Motorcycle("Yamaha", "YZF-R1M", 1600000);
	}
	~Market()
	{
		for (int i = 0; i < veh_count; i++)
			delete veh[i];
		delete[] veh;
	}

	void showInfo() const
	{
		cout << "Всего в магазине " << veh_count << " автомобилей:" << "\nСпорткаров: " << sportcar_count << "\nГрузовых автомобилей: " << truck_count << "\nМотоциклов: " << moto_count << endl;
	}
	void showStorage() const
	{
		cout << "Магазин:\n" << fixed << setprecision(2);
		for (int i = 0; i < veh_count; i++)
			veh[i]->showInfo();
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Market CarsAndMoto;
	CarsAndMoto.showInfo();
	cout << endl;
	CarsAndMoto.showStorage();

	system("pause");
	return 0;
}
