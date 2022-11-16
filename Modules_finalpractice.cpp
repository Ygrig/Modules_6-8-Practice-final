#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//Структура для 3й задачи
struct triangle {
	double a = 0;
	double b = 0;
	double c = 0;
};

//Заполнение массива случайными числами от бегин до энд
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

//Вывод массива в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Добавление нового элемента в конец массива
template <typename T>
void append(T*& arr, int length, T val) {
	T* tmp = new T[length + 1];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	tmp[length] = val;
	arr = tmp;//указатель арр направлен на ту же область памяти, что и tmp
}

template <typename T> 
void memory(T*&ptr,int length);

template <typename T>
T* pos_arr_concat(
	T arr1[], const int length1, 
	T arr2[], const int length2, 
	int& var);

double tr_area(triangle& T) {
	double halfp = (T.a + T.b + T.c) / 2.0;
	return sqrt(halfp * (halfp - T.a) * (halfp - T.b) * (halfp - T.c));
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 1.Выделение памяти (указатель и число)
	/*cout << "Задача 1.\nВведите количество элементов (длину) массива: ";
	cin >> n;
	int* pArr1 = nullptr; //направили указатель на нейтральную область памяти, чтобы избежать в дальнейшем ошибок

	try {
		memory(pArr1, n);
		cout << "Итоговый массив: \n";
		fill_arr(pArr1,n, 1, 11); //диапазон на свое усмотрение [1;10]!!!
		show_arr(pArr1, n);
		cout << '\n';
		delete[] pArr1;
	}
	catch (const out_of_range& ex) {
		cout << "Ошибка: " << ex.what() << "\n\n";
	}
	*/

	//Задача 2. Массив положительных элементов
	/*cout << "Задача 2.\n";
	const int size1 = 7;
	int arr1[size1];
	const int size2 = 10;
	int arr2[size2];
	fill_arr(arr1, size1,-10,11); //от -10 до 10 вкл-но, т.к. должны быть отрицательные элементы по условию задаччи
	fill_arr(arr2, size2, -11, 11);
	cout << "Массив 1:\n";
	show_arr(arr1, size1);
	cout << "Массив 2:\n";
	show_arr(arr2, size2);
	
	int* result_arr = pos_arr_concat(arr1, size1, arr2, size2, n);

	cout << "Итоговый массив: \n";
	show_arr(result_arr, n);
	cout << endl;
	delete[] result_arr;
	*/

	//Задача 3. Площадь треугольника
	cout << "Задача 3.\nСтороны треугольника: ";
	triangle ABC{ 5.5, 9.1, 10.0 };
	cout << ABC.a << ", " << ABC.b << ", " << ABC.c << '\n';
	cout << "Площадь треугольника = " << tr_area (ABC) << '\n';

	return 0;
}

//Задача 1
template <typename T>
void memory(T* &ptr, int length) {
	if (length < 0)
		throw /*std::*/out_of_range("длина массива не может быть отрицательной");
	ptr = new T[length];
}

//Задача 2
template <typename T>
T* pos_arr_concat(T arr1[], const int length1, T arr2[], const int length2, int& var) {
	//объявляем указатель на массив ,с которым будем работать на протяж.работы с этой ф-ци, динамический, тк мы заранее не знаем, какой длины будет массив
	T* tmp_Arr = new T[0];
	int tmp_size =0;

	for(int i=0;i<length1;i++)
		if (arr1[i] > 0) {
			append (tmp_Arr, tmp_size, arr1[i]);
			tmp_size++;
		}

	for (int i = 0; i < length2; i++) //все то же самое, но для второго массива
		if (arr2[i] > 0) {
			append (tmp_Arr, tmp_size, arr2[i]);
			tmp_size++;
		}

	var = tmp_size;
	return tmp_Arr;
} 