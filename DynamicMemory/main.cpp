#include <iostream>

using namespace std;

#define tab "\t"

void FiilRand(int arr[], const int n);

void Print(int arr[], const int n);

int* push_back(int arr[], const int n, int value);

void main()
{
	setlocale(LC_ALL, "");
	cout << "DynamicMemory" << endl;
	int n = 5;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	//for (int i = 0; i < n; i++)
	{
		//cout << *(arr+i)  << tab;
		//cout << arr[i] << tab;

	}
	cout << endl;
	FiilRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€м€емое значений: "; cin >> value;

	arr[n] = value;

	n++;

	arr = push_back(arr, n, value);
	Print(arr, n);
    delete[] arr;
}




void FiilRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
}

int* push_back(int arr[], const int n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < 0; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;

	return arr;
}