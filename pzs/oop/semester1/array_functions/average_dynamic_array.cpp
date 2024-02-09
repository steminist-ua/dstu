#include <iostream>

// Функція для обчислення середнього значення масиву чисел
// Параметри:
//   arr - вказівник на масив
//   size - розмір масиву
// Повертає:
//   Середнє значення масиву
double calculateAverage(const int* arr, int size) {
    if (size == 0) {
        return 0.0; // Якщо масив порожній, повертаємо 0.0
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Додавання значень елементів масиву
    }

    return static_cast<double>(sum) / size; // Повернення середнього значення
}

int main() {
    int arraySize;

    // Запит розміру масиву від користувача
    std::cout << "Введіть розмір масиву: ";
    std::cin >> arraySize;

    // Виділення динамічної пам'яті для масиву
    int* myArray = new int[arraySize];

    // Запит чисел від користувача та заповнення масиву
    std::cout << "Введіть " << arraySize << " чисел:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> myArray[i];
    }

    // Виклик функції для обчислення середнього значення масиву
    double average = calculateAverage(myArray, arraySize);

    // Виведення результату на консоль
    std::cout << "Середнє значення масиву: " << average << std::endl;

    // Звільнення виділеної пам'яті
    delete[] myArray;

    return 0;
}
