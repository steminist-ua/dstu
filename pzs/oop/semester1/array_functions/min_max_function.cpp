#include <iostream>

// Функція для знаходження найменшого елемента у масиві
// Параметри:
//   arr - вказівник на масив
//   size - розмір масиву
// Повертає:
//   Найменше значення у масиві
int findMin(const int* arr, int size) {
    int min = arr[0]; // Припускаємо, що перший елемент - мінімальний

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; // Знайдено менший елемент
        }
    }

    return min;
}

// Функція для знаходження найбільшого елемента у масиві
// Параметри:
//   arr - вказівник на масив
//   size - розмір масиву
// Повертає:
//   Найбільше значення у масиві
int findMax(const int* arr, int size) {
    int max = arr[0]; // Припускаємо, що перший елемент - найбільший

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Знайдено більший елемент
        }
    }

    return max;
}

int main() {
    const int arraySize = 6;
    int myArray[arraySize] = {34, 12, 9, 56, 2, 67};

    // Виклик функцій для знаходження найменшого та найбільшого елементів масиву
    int minValue = findMin(myArray, arraySize);
    int maxValue = findMax(myArray, arraySize);

    // Виведення результатів на консоль
    std::cout << "Масив чисел: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << myArray[i];
        if (i < arraySize - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "Найменший елемент: " << minValue << std::endl;
    std::cout << "Найбільший елемент: " << maxValue << std::endl;

    return 0;
}
