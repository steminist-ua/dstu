#include <iostream>
#include <vector>
#include <algorithm>

class Book {
public:
    Book(std::string title, std::string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() const {
        std::cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year << std::endl;
    }

    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }

private:
    std::string title;
    std::string author;
    int year;
};

int main() {
    std::vector<Book> library;

    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    std::cout << "Інформація про книги в бібліотеці:" << std::endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    // Використовуємо std::sort для сортування за назвою книги
    std::sort(library.begin(), library.end());

    std::cout << "\nБібліотека після сортування за назвою книги:" << std::endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    return 0;
}
