#include <iostream>
#include <vector>
#include <string>

// Клас, що представляє заклинання
class Spell {
public:
    std::string spellName;         // Назва заклинання
    int difficultyLevel;           // Рівень складності
    std::string applicationMethod; // Спосіб застосування

    // Конструктор для ініціалізації властивостей заклинання
    Spell(const std::string& name, int level, const std::string& method)
        : spellName(name), difficultyLevel(level), applicationMethod(method) {}

    // Метод для виведення інформації про заклинання
    void printInfo() const{
        std::cout << "Заклинання: " << spellName << ", Рівень складності: " << difficultyLevel
                  << ", Спосіб застосування: " << applicationMethod << std::endl;
    }
};

// Клас, що представляє чарівника
class Wizard {
public:
    std::string name;               // Ім'я чарівника
    int magicLevel;                 // Рівень магії
    std::vector<Spell> learnedSpells; // Список вивчених заклинань

    // Конструктор для ініціалізації властивостей чарівника
    Wizard(const std::string& wizardName, int level)
        : name(wizardName), magicLevel(level) {}

    // Метод для вивчення нового заклинання
    void learnSpell(const Spell& spell) {
        learnedSpells.push_back(spell);
    }

    // Метод для застосування заклинань
    void castSpell() {
        std::cout << name << " застосовує заклинання:" << std::endl;
        for (const auto& spell : learnedSpells) {
            spell.printInfo();
        }
    }

    // Метод для виведення інформації про чарівника
    void printInfo() {
        std::cout << "Чарівник: " << name << ", Рівень магії: " << magicLevel << std::endl;
    }
};

int main() {
    // Створення заклинань
    Spell levitation("Левітація", 2, "Махання Палицею");
    Spell invisibility("Невидимість", 3, "Вимова заклинання");

    // Створення чарівника і вивчення заклинань
    Wizard harryPotter("Гаррі Поттер", 10);
    harryPotter.learnSpell(levitation);
    harryPotter.learnSpell(invisibility);

system("clear");
    // Виведення інформації про чарівника та застосування заклинань
    harryPotter.printInfo();
    harryPotter.castSpell();

    return 0;
}
