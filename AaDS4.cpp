#include"Exercises.h"
int main()
{
	setlocale(0, "rus");
	int choice;
	do
	{
		cout << "1. Задание 1" << endl;
		cout << "2. Задание 2" << endl;
		cout << "3. Выход" << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Задание 1:" << endl;
			Exercise1();
			cout << endl;
			break;
		case 2:
			cout << "Задание 2: " << endl;
			Exercise2();
			cout << endl;
			break;
		case 3:
			break;
		default:
			cout << "Ошибка ввода" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cout << endl;
		}
	} while (choice != 3);
}