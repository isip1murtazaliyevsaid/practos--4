#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale>

std::string reverse(const std::string& word) {
    std::string reversed_word = word;
    std::reverse(reversed_word.begin(), reversed_word.end());
    return reversed_word;
}

std::string removeVowels(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (!std::string("aeiouAEIOU").find(c) != std::string::npos)
            result += c;
    }
    return result;
}

std::string removeConsonants(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (std::string("aeiouAEIOU").find(c) != std::string::npos)
            result += c;
    }
    return result;
}

std::string shuffle(const std::string& word) {
    std::string shuffled_word = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled_word.begin(), shuffled_word.end(), g);
    return shuffled_word;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;
    std::cout << "Выберите действие:\n"
        << "1. Слово выводится задом наперед.\n"
        << "2. Вывести слово без гласных.\n"
        << "3. Вывести слово без согласных.\n"
        << "4. Рандомно раскидывать буквы заданного слова.\n"
        << "Ваш выбор: ";
    std::cin >> choice;

    std::string result;
    switch (choice) {
    case 1:
        result = reverse(word);
        break;
    case 2:
        result = removeVowels(word);
        break;
    case 3:
        result = removeConsonants(word);
        break;
    case 4:
        result = shuffle(word);
        break;
    default:
        std::cout << "Неверный выбор.\n";
        return 1;
    }

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
