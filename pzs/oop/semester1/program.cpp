#include <iostream>
using namespace std;

// int main() {

//     // int b = 7;
//     // cout << b << '\n'; // виводимо значення змінної b
//     // cout << &b << '\n'; // виводимо адресу в пам'яті змінної b
//     // cout << *&b << '\n'; // виводимо значення комірки в пам'яті змінної b

//     // int *iPtr; // вказівник на значення типу int
//     // double *dPtr; // вказівник на значення типу double
    
//     // int* iPtr3; // коректний синтаксис (дозволено, але не бажано)
//     // int * iPtr4; // коректний синтаксис (не робіть так)
    
//     // int *iPtr5, *iPtr6; // оголошуємо два вказівники для змінних типу int

//     // int* iPtr3, iPtr4; // iPtr3 - це вказівник на значення типу int,                            а iPtr4 - це звичайна змінна типу int!


//     // int value = 5;
//     // int *ptr = &value; // ініціалізуємо ptr адресою значення змінної
 
//     // cout << &value << '\n'; // виводимо адресу значення змінної value
//     // cout << ptr << '\n'; // виводимо адресу, яку містить ptr



//     // int iValue = 7;
//     // double dValue = 9.0;
    
//     // int *iPtr = &iValue; // ок
//     // double *dPtr = &dValue; // ок
//     // iPtr = &dValue; // неправильно: вказівник типу int не може вказувати на адресу          змінної типу double
//     // dPtr = &iValue; // неправильно: вказівник типу double не може вказувати на адресу           змінної типу int

//     // int *ptr = 7;


//     // int value = 5;
// 	// cout << &value << endl; // виводимо адресу value
// 	// cout << value << endl; // виводимо вміст value
 
// 	// int *ptr = &value; // ptr вказує на value
// 	// cout << ptr << endl; // виводимо адресу, яка зберігається в ptr (тобто &value)
// 	// cout << *ptr << endl; // розіменовуємо ptr (отримуємо значення, на яке вказує ptr)
 


//     // int array[4] = { 5, 8, 6, 4 };
 
//     // // Виводимо на екран значення масиву (змінну array)
//     // cout << "The array has address: " << array << '\n';
 
//     // // Виводимо на екран адресу елемента масиву
//     // cout << "Element 0 has address: " << &array[0] << '\n';


//     // void printSize(int array[]);
//     // void printSize(int *array);


//     // int array[4] = { 5, 8, 6, 4 };
    
//     // // Розіменування масиву (змінної array) призведе до повернення першого елемента масиву (елементу під номером 0)
//     // cout << *array; // виведеться 5!
    
//     // char name[] = "John"; // рядок C-style (також масив)
//     // cout << *name; // виведеться 'J'



//     // int array[4] = { 5, 8, 6, 4 };
// 	// cout << *array; // виведеться 5
 
// 	// int *ptr = array;
// 	// cout << *ptr; // виведеться 5



//     // int array[4] = { 5, 8, 6, 4 };
 
// 	// cout << sizeof(array) << '\n'; // виведеться sizeof(int) * довжина array
 
//     // int *ptr = array;
//     // cout << sizeof(ptr) << '\n'; // виведеться розмір вказівника

//     // cout << sizeof(array)/sizeof(array[0]) << '\n'; 



//     return 0;

// }




// void printSize(int *array)
// {
//     // Тут масив розглядається як вказівник
//     cout << sizeof(array) << '\n'; // виведеться розмір вказівника, а не довжина масиву!
// }
 
// int main()
// {
//     int array[] = { 1, 2, 3, 4, 4, 9, 15, 25 };
//     cout << sizeof(array) << '\n'; // виведеться sizeof(int) * довжина масиву
 
//     printSize(array); // тут аргумент array розпадається у вказівник
 
//      return 0;
// }


// // C++ неявно конвертує array[] в *array
// void printSize(int array[])
// {
//     // Тут масив розглядається як вказівник, а не як фіксований масив
//     cout << sizeof(array) << '\n'; // виведеться розмір вказівника, а не розмір масиву!
// }
 
// int main()
// {
//     int array[] = { 1, 2, 3, 4, 4, 9, 15, 25 };
//     cout << sizeof(array) << '\n'; // виведеться sizeof(int) * довжина масиву array
 
//     printSize(array); // тут аргумент array розпадається у вказівник
 
//      return 0;
// }


// // Параметр ptr містить копію адреси масиву
// void changeArray(int *ptr)
// {
//     *ptr = 5; // тому зміна елемента масиву призведе до зміни фактичного масиву
// }
 
// int main()
// {
//     int array[] = { 1, 2, 3, 4, 4, 9, 15, 25 };
//     cout << "Element 0 has value: " << array[0] << '\n';
 
//     changeArray(array);
 
//     cout << "Element 0 has value: " << array[0] << '\n';
 
//      return 0;
// }


// int main()
// {
//     int array[] = { 7, 8, 2, 4, 5 };
 
//     cout << "Element 0 is at address: " << &array[0] << '\n';
//     cout << "Element 1 is at address: " << &array[1] << '\n';
//     cout << "Element 2 is at address: " << &array[2] << '\n';
//     cout << "Element 3 is at address: " << &array[3] << '\n';
 
//     return 0;
// }



// int main()
// {
//      int array [5] = { 7, 8, 2, 4, 5 };
 
//      std::cout << &array[1] << '\n'; // виведеться адреса в пам'яті елементу під індексом 1
//      std::cout << array+1 << '\n'; // виведеться адреса в пам'яті вказівника на масив + 1
 
//      std::cout << array[1] << '\n'; // виведеться 8
//      std::cout << *(array+1) << '\n'; // виведеться 8 (зверніть увагу на дужки, вони тут обов'язкові)
 
//     return 0;
// }



// /**
//  * The function calculates the average of an array of integers.
//  * 
//  * @param arr An array of integers
//  * @param size The size parameter represents the number of elements in the array.
//  * 
//  * @return the average value of the elements in the array as a double.
//  */
// double calculateAverage(int* arr, int size) {
//     if (size == 0) {
//         return 0.0; // Якщо масив порожній, повертаємо 0.0
//     }

//     double sum = 0;
//     for (int i = 0; i < size; i++) {
//         sum += arr[i]; // Додавання значень елементів масиву
//     }

//     return sum / size; // Повернення середнього значення
// }

// int main() {
//     const int arraySize = 5;
//     int myArray[arraySize] = {10, 20, 30, 40, 50};

//     // Виклик функції для обчислення середнього значення масиву
//     double average = calculateAverage(myArray, arraySize);

//     cout << "Середнє значення масиву: " << average << endl;

//     return 0;
// }


/**
 * The bubbleSort function sorts an array of integers in ascending order using the bubble sort
 * algorithm.
 * 
 * @param arr The parameter "arr" is a pointer to an integer array.
 * @param size The parameter "size" represents the number of elements in the array "arr".
 */
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмін значень, якщо поточний елемент більший за наступний
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int arraySize = 6;
    int myArray[arraySize] = {34, 12, 9, 56, 2, 67};

    // Виклик функції для сортування масиву
    bubbleSort(myArray, arraySize);

    // Виведення відсортованого масиву на консоль
    std::cout << "Відсортований масив: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << myArray[i];
        if (i < arraySize - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
