#include <iostream>
using namespace std;
//Функция линейного поиска
int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; //Возвращаем индекс, если элемент найден
        }
    }
    return -1; //Возврашаем -1, если элемент отсутствует в массиве
}

//Функция бинарного поиска
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

    return -1;  // Возврашаем -1, если элемент отсутствует в массиве
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 15};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int key1 = 77;

    int arr[] = { 5, 2, 9, 1, 5, 6, 8, 3, 7, 4 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 6;

    cout << binary_search(arr1, size1, key1) << endl; 
    cout << linear_search(arr, size, key);

    return 0;
}