#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int N, X, move;
	cout << "Введите число N: " << endl;
	cin >> N;
	if (N < 1)
	{
		cerr << "Число N не может быть меньше 1!" << endl;
		return 1;
	}
	if (N == 1)
	{
		cout << "Ваше число - 1!" << endl;
		return 0;
	}
	int  max_steps = ceil(log2(N));
	int max = N + 1, min = 0;
	cout << "Максимальное количество шагов в игре: " << max_steps <<endl;
	while(min != max)
	{
		X = (min + max) / 2;
		if (X == min || X == max)
		{
			cerr << "Ошибка со стороны пользователя!" << endl;
			return 1;
		}
		cout << "Число - " << X << "?" << endl;
		cout << "1 - мало, 2 - много 3 - угадал. " << endl;
		cin >> move;
		switch (move)
		{
		case 1:
		{
			min = X;
			break;
		}
		case 2:
		{
			max = X;
			break;
		}
		case 3:
		{
			cout << "Ваше число - " << X << "." << "Спасибо за игру." << endl;
			return 0;
		}
		default: 
			cout << "Ошибка ввода! " << endl;
			break;
		}
	}
	cout << "Ошибка со стороны пользователя" << endl;
	return 1;

}
