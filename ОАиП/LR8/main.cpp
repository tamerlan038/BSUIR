#include <iostream>
#include <math.h>

double power(double base, double exp);
int brain(double x, int n);

double power(double base, double exp) {
    if (exp == 0) {
        return 1;
    }
    else {
        return base * power(base, exp - 1);
    }
}

int main() {
    double x;
    int n;
    double y;
    std::cout << "Введиите x: ";
    if (!(std::cin >> x)) {
        std::cout << "Incorrect data input";

        return 1;
    }
    std::cout << "Введиите n: ";
    if (!(std::cin >> n)) {
        std::cout << "Incorrect data input";

        return 1;
    }
    int t;

    if(n % 2 == 0){
        y = x * power(x, n - 1);
    }
    else{
        y = x * power(x, n - 1);
    }

    t = brain(x,n);


    std::cout << "Результат с рекурсией: " << y << std::endl;
    std::cout << "Результат без рекурсии: " << t << std::endl;

}

int brain(double x, int n){
    int t;
    if(n == 0){
        return 1;
    }
    else{
        if(n % 2 == 0){
            return t = pow(x, n);
        }
        else{
            return t = pow(x, n);
        }
    }
}

// #include <iostream>
// #include <math.h>

// int chek(double n, double m);

// int main(){
//     double x, y;
//     std::cout << "Введите x: ";
//     std::cin >> x;
//     std::cout << "Введите y: ";
//     std::cin >> y;
//     int t = chek(x, y);
// }

// int chek(double n, double m){
//     if(n > m){
//         std::cout << "Результат: x больше" << std::endl;
//         return 1;
//     }
//     else if (n < m){
//         std::cout << "Результат: y больше" << std::endl;
//         return -1;
//     }
//     else {
//         std::cout << "Результат: x и y равны" << std::endl;
//         return 0;
//     }
// }

// // double fac(double t){
// //     if(t <= 1){
// //         return 1;
// //     }
// //     else{
// //         return t * fac(t - 1);
// //     }
// // }

// // #include <iostream>
// // #include <math.h>
// // using namespace std;

// // double rec(int t) {
// //     if (t == 1) return 1;
// //     double x = pow((2.0 * t), 2) / pow((2.0 * t) - 1, 2);
// //     return x * rec(t - 1);
// // }

// // int main() {
// //     int n;
// //     cout << "n = ";
// //     cin >> n;
    
// //     double result = rec(n);
// //     cout << "Результат: " << result;
    
// //     return 0;
// // }