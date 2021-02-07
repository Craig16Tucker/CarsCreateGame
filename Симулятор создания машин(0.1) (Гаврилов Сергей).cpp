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
		cout << "\n������� ���� " << i + 1 << " ������:\n";
		cin >> userCars[i].color;
		cout << "\n������� ������ " << i + 1 << " ������:\n";
		cin >> userCars[i].model;
		cout << "\n������� ����� " << i + 1 << " ������(10000 - 99999):\n\n";
		cin >> userCars[i].number;
		if (userCars[i].number < 10000 || userCars[i].number > 99999)
		{
			cout << "\n����� ������������ �����, ���������� �����\n";
			userCars[i].number = 0;
			i = i - 1;
		}
	}
	return userCars;
}

void printOneCar(car* userCars)
{
	int index = 0;
	cout << "\n������� ����� ������, ������ ������� �� ������ ������� (1 - 5)\n";
	cin >> index;

	if (index > 0 || index <= 5)
	{
		cout << "\n���� ������:" << userCars[index - 1].color;
		cout << "\n������ ������:" << userCars[index - 1].model;
		cout << "\n����� ������:" << userCars[index - 1].number;
		cout << "\n\n";
	}
	else
	{
		cout << "\n������\n\n";

	}
}

car* changeCarStat(car* userCars)
{
	int index = 0;
	cout << "\n������� ����� ������, ������ ������� �� ������ ������������� (1 - 5)\n";
	cin >> index;

	if (index > 0 || index <= 5)
	{
		cout << "\n������� ���� " << index << " ������:\n";
		cin >> userCars[index - 1].color;
		cout << "\n������� ������" << index << " ������:\n";
		cin >> userCars[index - 1].model;
		cout << "\n������� �����" << index << " ������(10000 - 99999):\n\n";
		cin >> userCars[index - 1].number;
		if (userCars[index - 1].number < 10000 || userCars[index - 1].number > 99999)
		{
			cout << "\n������\n\n";
		}
		else
		{
			cout << "\n������\n\n";
		}

		return userCars;
	}
}

void printAllCars(car* userCars)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\n���� " << i + 1 << " ������:" << userCars[i].color;
		cout << "\n������ " << i + 1 << " ������:" << userCars[i].model;
		cout << "\n����� " << i + 1 << " ������:" << userCars[i].number;
		cout << "\n\n";
	}
}

void searchCar(car* userCars)
{
	int num = 0;
	cout << "\n������� ����� ��� ������\n";
	cin >> num;

	for (int i = 0; i < 5; i++)
	{
		if (num == userCars[i].number)
		{
			cout << "����� ������ �� ������ ������ �������, ��� ������ ��� ������� " << i + 1;
			cout << "\n���� ������:" << userCars[i].color;
			cout << "\n������ ������:" << userCars[i].model;
			cout << "\n����� ������:" << userCars[i].number;
		}
		else if (num != userCars[0].number & num != userCars[1].number & num != userCars[2].number & num != userCars[3].number & num != userCars[4].number)
		{
			cout << "������ � ����� ������� � ��� ����";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	car* userCars = new car[5];

	cout << "\n\t\t\t����� ���������� � ��������� �������� ����� ������\n";
	cout << "\n��� ������, ��� ����� ������� ���� ������:\n";

	createCar(userCars);


	for (int variant = 0; variant != 5;)
	{
		cout << "\n����� �������� �� ������ ���������?: \n" << "\n1 - ����������� ���������� ������\n" << "\n2 - ������������� ������\n" << "\n3 - ����������� ��� ������\n" << "\n4 - ����� ������ �� ������\n" << "\n5 - �����\n";
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
			cout << "\n������!\n";
			break;
		}
	}
	cout << "\n\t\t\t�������, ��� ������������ ������ 0.1\n";
	system("pause");
	return 0;
}
