#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);

int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int index);

void pop_col_back(int** arr, const int rows, int& cols); 
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	cout << "DynamicMemory" << endl;
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FiilRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавлямяемое значений: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	Print(arr = pop_back(arr, n), n);

	Print(arr = pop_front(arr, n), n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	Print(arr = erase(arr, n, index), n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс строки для добавления: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс строки для удаления: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс столбца для добавления: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс столбца для удаления: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);

#endif // DYNAMIC_MEMORY_2
}

int** Allocate(const int rows, const int cols)
{

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* insert(int arr[], int& n, int value, int index)
{
	if (index > n)return arr;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = value;

	delete[] arr;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& n, int index)
{
	if (index >= n)return arr;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	return buffer;
}


int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int index)
{
	if (index > rows) return arr;

	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = new int[cols] {};
	delete[] arr;
	rows++;
	return buffer;
}


int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	if (rows <= 0) return arr;

	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	rows--;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	if (index >= rows) return arr;

	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr[index];
	delete[] arr;
	rows--;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, int index)
{
	if (index > cols) return;

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j < index ? j : j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	if (cols <= 0) return;

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int index)
{
	if (index >= cols) return;

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j < index ? j : j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
