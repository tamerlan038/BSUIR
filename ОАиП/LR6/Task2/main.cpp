#include <iostream>
#include <string>

int main() {
    std::string S;
    int k;
    std::cout << "Введите строку: ";
    getline(std::cin, S);
    int length = S.length();
    
    std::cout << "Введите позицию k: ";
    std::cin >> k;

    if (k < 0 || k >= length) {
        std::cout << "Позиция k за пределами строки" << std::endl;

        return 0;
    }
    
    int wordCount = 0;      // счетчик слов
    bool inWord = false;    // флаг нахождения внутри слова
    int currentWord = 0;    // номер текущего слова
    
    for (int i = 0; i < length; i++) {
        if (S[i] == ' ') {
            inWord = false;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        }
        
        if (i == k) {
            currentWord = wordCount;
        }
    }

    if (S[k] == ' ') {
        if (currentWord > 0) {
            std::cout << "Номер предыдущего слова: " << currentWord << std::endl;
        } else {
            std::cout << "Нет предыдущего слова" << std::endl;
        }
    } else {
        std::cout << "Номер слова: " << currentWord << std::endl;
    }
    
    return 0;
}
