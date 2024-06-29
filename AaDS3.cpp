#include<iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
void quicksort(int* mas, int first, int last) {
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; 		
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l)
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f <= l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}

int main()
{
	setlocale(0, "rus");
	int N;

	cout << "Введите N: " << endl;
	cin >> N;
	if (N < 1)
	{
		cerr << "Ошибка ввода N" << endl;
		return 1;
	}
	if (N == 1)
	{
		cerr << "Массив с одним элементом не можте быть отсортирован." << endl;
		return 1;
	}
	int* A = new int[N];
	int* B = A;
	int* C = A;
	int* D = A;
	int* E = A;
	cout << "Массив А: ";
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 30;
		cout << A[i] << ", ";
	}
	cout << endl;
	high_resolution_clock::time_point start = high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (B[j] > B[j + 1])
				swap(B[j], B[j + 1]);
		}
	}
	high_resolution_clock::time_point end = high_resolution_clock::now();
	cout << "Массив В, отсортированный пузырьковым методом: ";
	for (int i = 0; i < N; i++)
		cout << B[i] << ", ";
	cout << endl;
	duration<double> time_elapsed = duration_cast<duration<double>>(end - start);
	cout << "Время выполнения пузырьковой сортировки: " << time_elapsed.count() << "мс" << endl;
	int j, buff;
	start = high_resolution_clock::now();
	for (int i = 1; i < N; i++) {
		buff = C[i];
		for (j = i - 1; j >= 0 && C[j] > buff; j--)
			C[j + 1] = C[j];
		C[j + 1] = buff;
	}
	end = high_resolution_clock::now();
	time_elapsed = duration_cast<duration<double>>(end - start);
	cout << "Массив C, отсортированный вставками: ";
	for (int i = 0; i < N; i++)
	{
		cout << C[i] << ", ";
	}
	cout << endl;
	cout << "Время выполнения сортировки вставками: " << time_elapsed.count() << "мс" << endl;
	int min, buf;
	start = high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (D[j] < D[min]) ? j : min;

		if (i != min) {
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
	end = high_resolution_clock::now();
	time_elapsed = duration_cast<duration<double>>(end - start);
	cout << "Массив D, отсортированный методом выбора: ";
	for (int i = 0; i < N; i++)
		cout << D[i] << ", ";
	cout << endl;
	cout << "Время выполнения сортировки выбором: " << time_elapsed.count() << "мс" << endl;
	start = high_resolution_clock::now();
	quicksort(E, 0, N - 1);
	end = high_resolution_clock::now();
	time_elapsed = duration_cast<duration<double>>(end - start);
	cout << "Массив E, отсортированный быстрой сортировкой: ";
	for (int i = 0; i < N; i++)
	{
		cout << E[i] << ", ";
	}
	cout << endl;
	cout << "Время выполнения быстрой сортировки: " << time_elapsed.count() << "мс" << endl;
	delete[] A;
	
}