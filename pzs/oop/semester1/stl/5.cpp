#include <iostream>
#include <stack>
#include <deque>

bool isBalanced(const std::string& expression, std::deque<int>& errorPositions) {
    std::stack<char> bracketStack;

    for (int i = 0; i < expression.size(); ++i) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            // Відкрита дужка: додаємо її до стеку
            bracketStack.push(currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            // Закрита дужка: перевіряємо відповідність з відкритою дужкою
            if (bracketStack.empty()) {
                // Немає відкритої дужки, додаємо позицію помилки до деку
                errorPositions.push_back(i);
            } else {
                char openBracket = bracketStack.top();
                bracketStack.pop();

                if ((currentChar == ')' && openBracket != '(') ||
                    (currentChar == ']' && openBracket != '[') ||
                    (currentChar == '}' && openBracket != '{')) {
                    // Невідповідність, додаємо позиції помилок до деку
                    errorPositions.push_back(i);
                    errorPositions.push_back(expression.find(openBracket));
                }
            }
        }
    }

    // Додаємо залишкові відкриті дужки до деку
    while (!bracketStack.empty()) {
        errorPositions.push_back(expression.find(bracketStack.top()));
        bracketStack.pop();
    }

    return errorPositions.empty();
}

int main() {
    std::string expression;
    std::cout << "Введіть вираз з дужками: ";
    std::getline(std::cin, expression);

    std::deque<int> errorPositions;

    if (isBalanced(expression, errorPositions)) {
        std::cout << "Баланс дужок виразу збережений." << std::endl;
    } else {
        std::cout << "Невірний баланс дужок. Позиції помилок:" << std::endl;
        for (int position : errorPositions) {
            std::cout << position << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}