#include <cmath>

// Функция вычисления среднего значения
double mean(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return (double) sum/size;
}

// Функция вычисления дисперсии
double variance(int* arr, int size) {
	double avg = mean(arr, size);
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += pow((arr[i] - avg), 2);
	}
	return (double) sum/size;
}

// Функция вычисления среднеквадратичного отклонения
double stdDeviation(int* arr, int size) {
	return (double) sqrt(variance(arr, size));
}


