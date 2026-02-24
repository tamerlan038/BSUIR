#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;
    
    int left = 0;
    int right = word.length() - 1;
    bool isPal = true;
    
    while (left < right) {
        if (word[left] != word[right]) {
            isPal = false;
            break;
        }
        left++;
        right--;
    }
    
    if (isPal) {
        std::cout << "ДА, это палиндром!" << std::endl;
    } else {
        std::cout << "НЕТ, это не палиндром" << std::endl;
    }
    
    return 0;
}