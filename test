#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;


//int linear_search(int arr[], int size, int key) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == key) return i;
//    }
//    return -1;
//}
//
//int main() {
//    // Размер массива:
//    const int SIZE = 500;
//
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dist(1, 1000000);
//
//    int* arr = new int[SIZE];
//    for (int i = 0; i < SIZE; i++) {
//        arr[i] = dist(gen);
//    }
//    int key = arr[SIZE / 2];  // Ищем элемент из середины массива
//
//    // Измерение времени работы алгоритма
//    auto start = high_resolution_clock::now();
//    int result = linear_search(arr, SIZE, key);
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<nanoseconds>(end - start);
//
//    // Вывод времени работы алгоритма
//    cout << duration.count();
//
//    delete[] arr;
//    return 0;
//}


int binary_search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    // Размер массива:
    const int SIZE = 1000;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000000);

    int* arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = dist(gen);
    }

    // Бинарный поиск требует отсортированный массив
    sort(arr, arr + SIZE);

    // Ищем элемент из середины массива
    int key = arr[SIZE / 2];

    // Измерение времени работы алгоритма
    auto start = high_resolution_clock::now();
    int result = binary_search(arr, SIZE, key);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);

    // Вывод времени работы алгоритма
    cout << duration.count();

    delete[] arr;
    return 0;
}
