#include <iostream>
#include <vector>
#include <map>
#include <string>

class ChristmasMarket {
public:
    std::map<std::string, std::vector<std::string>> giftCategories;

    void addGift(const std::string& category, const std::string& gift) {
        giftCategories[category].push_back(gift);
        std::cout << "Додано подарунок '" << gift << "' до категорії '" << category << "'" << std::endl;
    }

    void printGiftsInCategory(const std::string& category) {
        const auto& gifts = giftCategories[category];
        std::cout << "Подарунки в категорії '" << category << "':" << std::endl;
        for (const auto& gift : gifts) {
            std::cout << " - " << gift << std::endl;
        }
    }
};

int main() {
    ChristmasMarket market;

    // Додавання подарунків
    market.addGift("Іграшки", "Лего");
    market.addGift("Їжа", "Солодощі");
    market.addGift("Іграшки", "Книга");
    market.addGift("Їжа", "Фрукти");

    // Виведення подарунків в категоріях
    market.printGiftsInCategory("Іграшки");
    market.printGiftsInCategory("Їжа");

    return 0;
}
