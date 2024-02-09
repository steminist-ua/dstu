#include <iostream>
#include <list>
#include <string>
#include <iomanip>

class Joke {
public:
    Joke(std::string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        std::cout << "Жарт: " << text << std::endl;
        std::cout << "Оцінка: " << std::fixed << std::setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << std::endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        } else {
            std::cout << "Оцінка повинна бути від 1 до 5!" << std::endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    std::string text;
    int votes;
    int totalRating;
};

int main() {
    std::list<Joke> jokeList;

    // Додавання жартів до списку
    jokeList.push_back(Joke("Чому програмісти так погано сплять?"));
    jokeList.push_back(Joke("Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Що робить програміст після розставання?"));
    jokeList.push_back(Joke("Переходить на інший репозиторій!"));

    std::cout << "Ласкаво просимо до програми для оцінювання жартів!" << std::endl;

    // Оцінювання жартів
    for (auto& joke : jokeList) {
        joke.tellJoke();

        int userRating;
        std::cout << "Ваша оцінка (1-5): ";
        std::cin >> userRating;

        joke.rateJoke(userRating);
    }

    std::cout << "\nЖарти з високим рейтингом:" << std::endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}
