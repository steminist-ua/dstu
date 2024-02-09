// Ось простий приклад рішення гри "Монстри та герої" на C++. У цій грі є базовий клас Character, який представляє персонажів гри, і два похідні класи Hero та Monster. Герої та монстри мають властивості, такі як ім'я, здоров'я та сила, і можуть атакувати один одного. Гра завершується, коли всі монстри вбиті або всі герої повалені.

// Герої та монстри випадковим чином вибирають один одного для атаки.
// Один герой атакує одного монстра 
// Потім рандомні монстри атакують всіх живих героїв 

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Character {
protected:
    std::string name;
    int health;
    int power;

public:
    Character(const std::string& n, int h, int p) : name(n), health(h), power(p) {}

    const std::string& getName() const {
        return name;
    }

    int getHealth() {
        return health;
    }

    bool isAlive() {
        return health > 0;
    }

    void attack(Character& target) {
        int damage = rand() % power + 1;
        target.takeDamage(damage);
        // Герой 1 атакує Монстра 1, завдаючи 10 шкоди.
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage." << std::endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }
};

class Hero : public Character {
public:
    Hero(const std::string& n, int h, int p) : Character(n, h, p) {}

    void heroAttack(Character& target) {
        attack(target);
        // кричить героїчний бойовий клич!
        std::cout << name << " shouts a heroic battle cry!" << std::endl;
    }
};

class Monster : public Character {
public:
    Monster(const std::string& n, int h, int p) : Character(n, h, p) {}

    void monsterAttack(Character& target) {
        attack(target);
        // грізно гарчить!
        std::cout << name << " growls menacingly!" << std::endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::vector<Hero> heroes;
    heroes.push_back(Hero("Hero 1", 100, 20));
    heroes.push_back(Hero("Hero 2", 120, 18));
    heroes.push_back(Hero("Hero 3", 80, 25));

    std::vector<Monster> monsters;
    monsters.push_back(Monster("Monster 1", 80, 15));
    monsters.push_back(Monster("Monster 2", 100, 50));
    monsters.push_back(Monster("Monster 3", 120, 10));

    // Гра продовжується, доки є як живі герої, так і монстри
    while (!heroes.empty() && !monsters.empty()) {
        for (int i = 0; i < heroes.size(); i++) {
            if (!monsters.empty()) {
                int monsterIndex = rand() % monsters.size();
                heroes[i].heroAttack(monsters[monsterIndex]);

                if (!monsters[monsterIndex].isAlive()) {
                    std::cout << monsters[monsterIndex].getName() << " is defeated!" << std::endl;
                    monsters.erase(monsters.begin() + monsterIndex);
                }
            }
        }

        for (int i = 0; i < monsters.size(); i++) {
            if (!heroes.empty() && heroes[i].isAlive()) {
                int heroIndex = rand() % heroes.size();
                monsters[i].monsterAttack(heroes[heroIndex]);

                if (!heroes[heroIndex].isAlive()) {
                    std::cout << heroes[heroIndex].getName() << " is defeated!" << std::endl;
                    heroes.erase(heroes.begin() + heroIndex);
                }
            }
        }
    }

    if (heroes.empty()) {
        std::cout << "Monsters win!" << std::endl;
    } else {
        std::cout << "Heroes win!" << std::endl;
    }

    return 0;
}
