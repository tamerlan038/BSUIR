#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int numberofelemnt;
    int s;
    std::cout << "Do you want to play? Yes - 1; No - 0\n";
    std::cin >> s;
    std::cout << "\n";

    while(s == 1){
        int x = std::rand() % 100 + 1;

        std::cout << "Array's size: " << x;

        int a[x];
        for(int i = 0; i < x; i++){
            int y = std::rand() % 101; 
            a[i] = y;
        }
        std::cout << "\n";

        std::cout << "Elements: ";
        for(int i = 0; i < x; i++){
            std::cout << a[i] << " ";
        }
        std::cout << "\n";

        std::cout << "Enter element number (1 to " << x << "): ";
        std::cin >> numberofelemnt;

        while(numberofelemnt < 1 || numberofelemnt > x){
            std::cout << "Incorrect data input!";
            std::cout << "\n";
            std::cout << "Enter element number (1 to " << x << "): ";
            std::cin >> numberofelemnt;
        }

        int *t = &a[numberofelemnt - 1];

        std::cout << "Element on position " << numberofelemnt << ": " << *t;

        

        std::cout << "\n";
        std::cout << "Do you want to play again? Yes - 1; No - 0\n";
        std::cin >> s;
    }
}