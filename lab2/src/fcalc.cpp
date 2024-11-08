#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include "opslib.h"

using namespace std;

const int MAX_ARR_SIZE = 100;
const string HELP_PAGE =
"Использование: файл [--операция]\n\
\n\
--help   данная справочная страница\n\
--mean   вычисление среднего\n\
--var    вычисление дисперсии\n\
--dev    вычисление среднеквадратичного отклонения\n";

int main(int argc, char** argv) {
	// Переход с Code Page 866 на 65001 (UTF-8), для корректной работы вывода русских символов
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	if (argc == 1 || argc > 3) {
		cout << "Использование: файл [--операция]" << endl;
		return 1;
	} else if((argc == 2 && (strcmp(argv[1], "--help") == 0)) || (argc == 3 && (strcmp(argv[2], "--help") == 0))) {
		cout << HELP_PAGE;
	} else {
		int numbers[MAX_ARR_SIZE];
		int size = 0;
		ifstream numbers_file;
		string line;
		bool invalid_symbol_was_caught = false;

		// Открываем файл
		numbers_file.open(argv[1]);

		// Проверка открытия файла
		if (!numbers_file.is_open()) {
			cerr << "Не удалось открыть файл." << endl;
			numbers_file.close();
			return 2;
		}

		// Считыванием числа из файла
		while (getline(numbers_file, line)) {
			if (size == MAX_ARR_SIZE) {
				cout << "Достигнуто максимальное количество чисел (" << MAX_ARR_SIZE << "), дальнейшие числа были пропущены." << '\n';
				break;
			}

			try {
				numbers[size] = stoi(line);
				size++;
			}
			catch(...) {
				if (!invalid_symbol_was_caught) {
					cerr << "Файл содержал символ(-ы) кроме цифр, они были пропущены." << '\n';
					invalid_symbol_was_caught = true;
				}
			}
		}
		numbers_file.close();

		// Проверяем введенный ключ операции
		if (strcmp(argv[2], "--mean") == 0) {
			cout << mean(numbers, size) << endl;
		} else if (strcmp(argv[2], "--var") == 0) {
			cout << variance(numbers, size) << endl;
		} else if (strcmp(argv[2], "--dev") == 0) {
			cout << stdDeviation(numbers, size) << endl;
		} else {
			cout << "Неверный аргумент. Используйте --help для справки.";
		}
	}
	return 0;	
}