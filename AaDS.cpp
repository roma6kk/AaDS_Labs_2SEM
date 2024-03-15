#include<iostream>
#include<ctime>
using namespace std;
unsigned int fib(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return fib(n - 2) + fib(n - 1);
}
int main()
{
	setlocale(0, "rus");
	int n;
	cout << "Введите число N: " << endl;
	cin >> n;
	unsigned int* fibb = new unsigned int[n];
	fibb[0] = 0;
	fibb[1] = 1;
	unsigned int start_time = clock();
	for (int i = 2; i < n; i++)
	{
		fibb[i] = fibb[i - 2] + fibb[i - 1];
	}
	cout << "Число Фиббаначи с номером N через цикл: " << fibb[n-1] << endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Расчетное время циклом " << search_time / 1000 / 60 << " минут " << search_time / 1000 % 60 << " секунд." << endl;
	unsigned int start_time2 = clock();
	cout << "Число Фиббаначи с номером N через рекурсию: " << fib(n) << endl;
	unsigned int end_time2 = clock();
	unsigned int search_time2 = end_time2 - start_time2;
	cout << "Расчетное время рекурсией " << search_time2 / 1000 / 60 << " минут " << search_time2 / 1000 % 60 << " секунд." << endl;

} 
