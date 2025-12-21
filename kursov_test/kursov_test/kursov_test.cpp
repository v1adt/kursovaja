#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <vector>
#include <locale.h>

using namespace std;

// Функция линейного поиска
int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Возвращаем индекс, если элемент найден
        }
    }
    return -1; // Возвращаем -1, если элемент отсутствует в массиве
}

// Функция бинарного поиска
int binary_search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid;  // Возвращаем индекс, если элемент найден
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  // Возвращаем -1, если элемент отсутствует в массиве
}

// Тестирование алгоритмов
void run_tests() {
    // Размеры массивов для тестирования
    vector<int> sizes = { 10, 50, 100, 500, 1000, 5000, 10000 };
    const int NUM_TESTS = 10000; // Количество тестовых массивов

    // Настройка генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());

    cout << left << setw(25) << "Число элементов в массиве "
        << setw(25) << "Линейный поиск (мкс)"
        << setw(25) << "Бинарный поиск (мкс)"
        << setw(25) << "Встроенная функция (мкс)" << "\n";
    cout << string(100, '-') << "\n";

    for (int size : sizes) {
        double total_linear_time = 0.0;
        double total_binary_time = 0.0;
        double total_std_find_time = 0.0;

        for (int test = 0; test < NUM_TESTS; ++test) {
            // Создаем массив
            int* arr = new int[size];

            // Заполняем массив случайными числами
            uniform_int_distribution<> dist(1, size * 10);
            for (int i = 0; i < size; ++i) {
                arr[i] = dist(gen);
            }

            // Сортируем для бинарного поиска
            sort(arr, arr + size);

            int key = dist(gen);

            // Тест линейного поиска
            auto start = chrono::high_resolution_clock::now();
            linear_search(arr, size, key);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> linear_time = end - start; 
            total_linear_time += linear_time.count();

            // Тест бинарного поиска
            start = chrono::high_resolution_clock::now();
            binary_search(arr, size, key);
            end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> binary_time = end - start;
            total_binary_time += binary_time.count();

            // Тест встроенной функции std::find
            start = chrono::high_resolution_clock::now();
            find(arr, arr + size, key);
            end = chrono::high_resolution_clock::now();
            chrono::duration<double, micro> std_find_time = end - start; 
            total_std_find_time += std_find_time.count();

            // Освобождаем память
            delete[] arr;
        }

        // Вычисляем СРЕДНЕЕ время для одного теста (в микросекундах)
        double avg_linear_time = total_linear_time / NUM_TESTS;
        double avg_binary_time = total_binary_time / NUM_TESTS;
        double avg_std_find_time = total_std_find_time / NUM_TESTS;

        // Выводим результаты для текущего размера массива
        cout << left << setw(25) << size
            << setw(25) << fixed << setprecision(4) << avg_linear_time
            << setw(25) << avg_binary_time
            << setw(25) << avg_std_find_time << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Сравнение производительности алгоритмов поиска\n";
    cout << "Количество тестовых массивов: 10000\n";
    cout << string(100, '=') << "\n\n";

    // Запуск тестов производительности
    run_tests();


    return 0;
}