#include <iostream>
using namespace std;

int main() {
    double N[20];
    double x;
    int n = 0;
    char choice;
    
    do {
        cout << "Введите число: ";
        cin >> x;
        N[n] = x;
        n++;
        
        if (n >= 20) {
            cout << "Достигнут максимум (20 чисел)" << endl;
            break;
        }
        
        cout << "Хотите ввести еще одно число? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');

    cout << "Введенные числа: ";
    for (int i = 0; i < n; i++) {
        cout << N[i] << " ";
    }
    cout << endl;

    int positiveIndex = -1;
    for (int i = 0; i < n; i++) {
        if (N[i] > 0) {
            positiveIndex = i;
            break;
        }
    }
    
    if (positiveIndex == -1) {
        cout << "Положительных чисел нет!" << endl;
    } else {
        double sum = 0;
        for (int i = positiveIndex + 1; i < n; i++) {
            sum += N[i];
        }
        cout << "Первое положительное число: " << N[positiveIndex] << endl;
        cout << "Сумма чисел после него: " << sum << endl;
    }
    
    return 0;
}