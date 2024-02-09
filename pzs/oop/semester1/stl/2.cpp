#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> favoriteFruits;

    std::cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << std::endl;
    std::cout << "Введіть свої улюблені фрукти (введіть 'кінець', щоб завершити введення):" << std::endl;

    std::string fruit;
    while (true) {
        std::cout << "Фрукт: ";
        std::cin >> fruit;

        // Перевірка на вихід з гри
        if (fruit == "кінець") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }

    // Сортування фруктів за алфавітом
    std::sort(favoriteFruits.begin(), favoriteFruits.end());

    std::cout << "\nВаші улюблені фрукти в алфавітному порядку:" << std::endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        std::cout << favoriteFruit << std::endl;
    }

    std::cout << "Гра завершена. Дякуємо за участь!" << std::endl;

    return 0;
}
