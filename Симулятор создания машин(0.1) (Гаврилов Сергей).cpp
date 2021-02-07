#include <iostream>

using std::cout;
using std::cin;
using std::string;

struct car
{
	string color;
	string model;
	int number = 0;
};

car* createCar(car* userCars)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\nВведите цвет " << i + 1 << " машины:\n";
		cin >> userCars[i].color;
		cout << "\nВведите модель " << i + 1 << " машины:\n";
		cin >> userCars[i].model;
		cout << "\nВведите номер " << i + 1 << " машины(10000 - 99999):\n\n";
		cin >> userCars[i].number;
		if (userCars[i].number < 10000 || userCars[i].number > 99999)
		{
			cout << "\nВведён некорректный номер, попробуйте снова\n";
			userCars[i].number = 0;
			i = i - 1;
		}
	}
	return userCars;
}

void printOneCar(car* userCars)
{
	int index = 0;
	cout << "\nВведите номер машины, данные которой вы хотите увидеть (1 - 5)\n";
	cin >> index;

	if (index > 0 || index <= 5)
	{
		cout << "\nЦвет машины:" << userCars[index - 1].color;
		cout << "\nМодель машины:" << userCars[index - 1].model;
		cout << "\nНомер машины:" << userCars[index - 1].number;
		cout << "\n\n";
	}
	else
	{
		cout << "\nОшибка\n\n";

	}
}

car* changeCarStat(car* userCars)
{
	int index = 0;
	cout << "\nВведите номер машины, данные которой вы хотите редактировать (1 - 5)\n";
	cin >> index;

	if (index > 0 || index <= 5)
	{
		cout << "\nВведите цвет " << index << " машины:\n";
		cin >> userCars[index - 1].color;
		cout << "\nВведите модель" << index << " машины:\n";
		cin >> userCars[index - 1].model;
		cout << "\nВведите номер" << index << " машины(10000 - 99999):\n\n";
		cin >> userCars[index - 1].number;
		if (userCars[index - 1].number < 10000 || userCars[index - 1].number > 99999)
		{
			cout << "\nОшибка\n\n";
		}
		else
		{
			cout << "\nОшибка\n\n";
		}

		return userCars;
	}
}

void printAllCars(car* userCars)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\nЦвет " << i + 1 << " машины:" << userCars[i].color;
		cout << "\nМодель " << i + 1 << " машины:" << userCars[i].model;
		cout << "\nНомер " << i + 1 << " машины:" << userCars[i].number;
		cout << "\n\n";
	}
}

void searchCar(car* userCars)
{
	int num = 0;
	cout << "\nВведите номер для поиска\n";
	cin >> num;

	for (int i = 0; i < 5; i++)
	{
		if (num == userCars[i].number)
		{
			cout << "Поиск машины по номеру прошел успешно, это машина под номером " << i + 1;
			cout << "\nЦвет машины:" << userCars[i].color;
			cout << "\nМодель машины:" << userCars[i].model;
			cout << "\nНомер машины:" << userCars[i].number;
		}
		else if (num != userCars[0].number & num != userCars[1].number & num != userCars[2].number & num != userCars[3].number & num != userCars[4].number)
		{
			cout << "Машины с таким номером у вас нету";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	car* userCars = new car[5];

	cout << "\n\t\t\tДобро пожаловать в симулятор создания своей машины\n";
	cout << "\nДля начала, вам нужно создать свои машины:\n";

	createCar(userCars);


	for (int variant = 0; variant != 5;)
	{
		cout << "\nКакое действие вы хотите выполнить?: \n" << "\n1 - Просмотреть конкретную машину\n" << "\n2 - Редактировать машину\n" << "\n3 - Просмотреть все машини\n" << "\n4 - Найти машину по номеру\n" << "\n5 - Выйти\n";
		cin >> variant;
		switch (variant)
		{
		case 1:
			printOneCar(userCars);
			break;
		case 2:
			changeCarStat(userCars);
			break;
		case 3:
			printAllCars(userCars);
			break;
		case 4:
			searchCar(userCars);
			break;
		case 5:
			break;
		default:
			cout << "\nОшибка!\n";
			break;
		}
	}
	cout << "\n\t\t\tСпасибо, что использовали версию 0.1\n";
	system("pause");
	return 0;
}
