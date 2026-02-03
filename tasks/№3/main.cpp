#include <iostream>
#include <cstdlib>
#include <ctime>

int maxcash(int cash1, int count, int levels){
    int cash2;
    while(levels > 0){
        cash2 = cash1 + 10*count;
        cash1 = cash2;
        count++;
        levels--;
    }

    return cash2;
}

int main() {
    int s;
    std::cout << "Do you want to play? Yes - 1; No - 0\n";
    std::cin >> s;

    while(s == 1){
        int cash;
        std::cout << "Enter your cash (min 40): ";
        std::cin >> cash;
        while(cash < 40){
            std::cout << "Unavailable amount!\n";
            std::cout << "Enter your cash (min 40): ";
            std::cin >> cash;
        }
        int cash_0 = cash;
        int amounts_of_levels = 1;
        int user_number;
        int t = 1;
        int k = 3;

        std::cout << "=====Welcome to CASINO!=====";
        std::cout << "\n";
        std::cout << "Enter how many levels you want: ";
        std::cin >> amounts_of_levels;
        int amounts_of_levels_1 = amounts_of_levels;
        std::cout << "Nice, let's start!";
        std::cout << "\n";

        while(amounts_of_levels > 0){
            std::cout << "Enter your number from 1 to " << k + 1 << ": ";
            std::cin >> user_number;

            std::srand(std::time(nullptr));
            int randomIndex = std::rand() % k + 1;
        
            if(randomIndex == user_number){
                std::cout << "You are lucky!";
                std::cout << "\n";
                std::cout << "Your balance is: " << cash + 10*t;
                cash += 10*t;
                std::cout << "\n";
            }
            else{
                std::cout << "You failed!";
                std::cout << "\n";
                std::cout << "Your balance is: " << cash - 10*t;
                cash -= 10*t;
                std::cout << "\n";
            }
            k *= 2;
            amounts_of_levels--;
            t++;
            std::cout << "\n";
            if(cash < 0){
                std::cout << "Your money is out!" << "\n";

                break;
            }
        }

        int newcash = maxcash(cash_0, t - 1, amounts_of_levels_1);

        if(cash == newcash){
            std::cout << "You got a JACKPOT!\n";
            cash *= 100;
            std::cout << "Your cash is " << cash;
        }
        else if(cash > cash_0 && cash < newcash){
            std::cout << "So close! Keep going!";
        }
        else if (cash == cash_0){
            std::cout << "You didn't lose anything! Try it again!";
        }
        else if(cash < cash_0){
            std::cout << "Try to win back! I believe in you!";
        }
        std::cout << "\n";

        std::cout << "Do you want to play again? Yes - 1; No - 0\n";
        std::cin >> s;
    }
}