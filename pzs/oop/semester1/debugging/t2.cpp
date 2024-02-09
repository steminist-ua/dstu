#include <iostream>
#include <list>
#include <string>

class Gift {
public:
    std::string name;
    int weight;

    Gift(const std::string& giftName, int giftWeight)
        : name(giftName), weight(giftWeight) {}
};

class Santa {
public:
    std::list<Gift> santaGifts;

    void addGift(const Gift& gift) {
        santaGifts.push_back(gift);
        std::cout << "Додано подарунок: " << gift.name << " (" << gift.weight << " грам)" << std::endl;
    }

    void removeGift(const std::string& giftName) {
        for (auto it = santaGifts.begin(); it != santaGifts.end(); ++it) {
            if (it->name == giftName) {
                std::cout << "Вилучено подарунок: " << it->name << " (" << it->weight << " грам)" << std::endl;
                santaGifts.erase(it);
                return;
            }
        }
        std::cout << "Подарунок з назвою '" << giftName << "' не знайдено." << std::endl;
    }

    void printTotalWeight() {
        int totalWeight = 0;
        for (const auto& gift : santaGifts) {
            totalWeight += gift.weight;
        }
        std::cout << "Дід Мороз приніс подарунки у загальній вазі: " << totalWeight << " грам" << std::endl;
    }
};

int main() {
    Santa santa;

    // Додавання та виведення подарунків
    santa.addGift(Gift("Лего", 500));
    santa.addGift(Gift("М'яч", 300));
    santa.addGift(Gift("Книга", 200));

    // Виведення ваги перед видаленням
    santa.printTotalWeight();

    // Видалення подарунка та виведення ваги після видалення
    santa.removeGift("М'яч");
    santa.printTotalWeight();

    return 0;
}
