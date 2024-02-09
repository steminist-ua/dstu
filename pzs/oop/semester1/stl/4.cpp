#include <iostream>
#include <map>
#include <string>

int main() {
    // Створення словника для зберігання середніх балів студентів
    std::map<std::string, double> studentGrades;

    // Додавання даних до словника
    studentGrades["Анна"] = 4.5;
    studentGrades["Борис"] = 3.8;
    studentGrades["Катерина"] = 4.2;
    studentGrades["Дмитро"] = 4.0;

    // Вивід даних про студентів
    std::cout << "Інформація про студентів:" << std::endl;
    for (const auto& student : studentGrades) {
        std::cout << student.first << ": " << student.second << std::endl;
    }

    // Пошук і вивід середнього балу для певного студента
    std::string searchStudent;
    std::cout << "\nВведіть ім'я студента для пошуку середнього балу: ";
    std::cin >> searchStudent;

    auto it = studentGrades.find(searchStudent);
    if (it != studentGrades.end()) {
        std::cout << "Середній бал студента " << searchStudent << ": " << it->second << std::endl;
    } else {
        std::cout << "Студент з іменем " << searchStudent << " не знайдений." << std::endl;
    }

    return 0;
}
