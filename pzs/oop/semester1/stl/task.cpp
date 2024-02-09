// 9. Фільми та Жанри:
//     - Базовий клас: `Фільм`
//         - Похідний клас: `Драма`
//             - Похідний клас: `Трагедія`
//         - Похідний клас: `Комедія`
//             - Похідний клас: `ЧорнаКомедія`
//                 - Похідний клас: `ЧорнаКомедіяЗАбсурдом`



#include <iostream>
#include <string>

// Базовий клас: Фільм
class Film {
public:
    Film(const std::string& title) : title(title) {}

    void play() const {
        std::cout << "Відтворюється фільм: " << title << std::endl;
    }

private:
    std::string title;
};

// Похідний клас: Драма
class Drama : public Film {
public:
    Drama(const std::string& title, const std::string& mainCharacter)
        : Film(title), mainCharacter(mainCharacter) {}

    void displayMainCharacter() const {
        std::cout << "Головний герой драми: " << mainCharacter << std::endl;
    }

private:
    std::string mainCharacter;
};

// Похідний клас: Трагедія
class Tragedy : public Drama {
public:
    Tragedy(const std::string& title, const std::string& mainCharacter, const std::string& tragicEvent)
        : Drama(title, mainCharacter), tragicEvent(tragicEvent) {}

    void displayTragicEvent() const {
        std::cout << "Трагічна подія у фільмі: " << tragicEvent << std::endl;
    }

private:
    std::string tragicEvent;
};

// Похідний клас: Комедія
class Comedy : public Film {
public:
    Comedy(const std::string& title, int laughterCount)
        : Film(title), laughterCount(laughterCount) {}

    void displayLaughterCount() const {
        std::cout << "Кількість сміху у комедії: " << laughterCount << std::endl;
    }

private:
    int laughterCount;
};

// Похідний клас: Чорна Комедія
class DarkComedy : public Comedy {
public:
    DarkComedy(const std::string& title, int laughterCount, const std::string& darkHumor)
        : Comedy(title, laughterCount), darkHumor(darkHumor) {}

    void displayDarkHumor() const {
        std::cout << "Чорний гумор у фільмі: " << darkHumor << std::endl;
    }

private:
    std::string darkHumor;
};

// Похідний клас: Чорна Комедія з Абсурдом
class AbsurdDarkComedy : public DarkComedy {
public:
    AbsurdDarkComedy(const std::string& title, int laughterCount, const std::string& darkHumor, const std::string& absurdity)
        : DarkComedy(title, laughterCount, darkHumor), absurdity(absurdity) {}

    void displayAbsurdity() const {
        std::cout << "Абсурд у фільмі: " << absurdity << std::endl;
    }

private:
    std::string absurdity;
};

int main() {
    // Приклад використання:
    Tragedy tragicFilm("Трагедія: Втрата", "Юлія", "Смерть коханої особи");
    tragicFilm.play();
    tragicFilm.displayMainCharacter();
    tragicFilm.displayTragicEvent();

    AbsurdDarkComedy absurdComedy("Чорна комедія з абсурдом", 100, "Чорний гумор на всі теми", "Абсурдні ситуації");
    absurdComedy.play();
    absurdComedy.displayLaughterCount();
    absurdComedy.displayDarkHumor();
    absurdComedy.displayAbsurdity();

    return 0;
}
