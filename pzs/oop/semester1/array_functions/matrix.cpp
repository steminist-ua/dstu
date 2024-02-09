#include <iostream>

// Функція для виведення матриці на консоль
// Параметри:
//   matrix - вказівник на двовимірний масив
//   rows - кількість рядків у матриці
//   cols - кількість стовпців у матриці
void printMatrix(const int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t"; // Виведення елементу матриці
        }
        std::cout << std::endl; // Перехід на новий рядок
    }
}

int main() {
    const int numRows = 3;
    const int numCols = 3;
    int matrix[numRows][numCols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Створення вказівника на матрицю
    const int* matrixPtr[numRows];
    for (int i = 0; i < numRows; i++) {
        matrixPtr[i] = matrix[i];
    }

    // Виведення матриці на консоль за допомогою вказівника
    std::cout << "Матриця:" << std::endl;
    printMatrix(matrixPtr, numRows, numCols);

    return 0;
}
