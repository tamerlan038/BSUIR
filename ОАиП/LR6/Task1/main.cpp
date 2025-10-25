#include <iostream>
#include <string>

int main() {
    std::string L;
    std::cout << "Введите строку:";
    getline(std::cin, L);
    int length = L.length();
    std::cout << "Длина: " << length << std::endl;;

    int counter = 0;
    if(length % 5 == 0){
        for(int i = 0; i < length; i++){
            if(L[i] == '[' || 
               L[i] == ']' || 
               L[i] == '(' || 
               L[i] == ')' || 
               L[i] == '{' || 
               L[i] == '}' || 
               L[i] == '<' || 
               L[i] == '>') {
                counter++;
            }
        }
        std::cout << "Количество скобок всех видов: " << counter;
    }
}