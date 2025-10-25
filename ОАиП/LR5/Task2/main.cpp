#include <iostream>
#include <iomanip>

int main(){
    double **a;
    int n, m;

    std::cout << "Введите количество строк (n) ";
    if(!(std::cin >> n)){
        std::cout << "Incorrect data input";

        return 1;
    };
    std::cout << "Введите количество столбцов (m) ";
    if(!(std::cin >> m)){
        std::cout << "Incorrect data input";

        return 1;
    };

    if(n != m){
        std::cout << "Incorrect data input";

        return 1;
    }

    a = new double*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new double[n];
    }

    std::cout << "Введите через пробел все элементы: ";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Введенная матрица:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << std::setw(5) << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

//     int sum = 0;
//     for(int i = 1; i < n; i++) {
//         for(int j = 0; j < i; j++) {
//             sum += a[i][j];
//         }
//     } 
//     std::cout << "Сумма элементов, лежащих ниже главной диогонали: " << sum << std::endl;

//     int multi = 1;
//     for(int i = 0; i < n - 1; i++) {
//         for(int j = 0; j < m - 1; j++) {
//             multi *= a[i][j];
//         }
//         m--;
//     } 
//     std::cout << "Произведение элементов, лежащих над побочной диогональю: " << multi;

//     for(int i = 0; i < n; i++) {
//         delete[] a[i];
//     }
//     delete[] a;
// }
//     double *x;
//     for(int i = 0; i < 1; i += 1) {
//         for(int j = 0; j < 1; j += 1) {
//             x = &a[0][0];
//             std::cout << *x;
//         }
//     }
// }

    double max_1 = a[0][0];
    std::cout << "Главная диагональ: ";
    for(int i = 0; i < n; i++) {
        std::cout << a[i][i] << " ";
        if(a[i][i] > max_1) {
            max_1 = a[i][i];
        }
    }
    std::cout << "\nНаибольший элемент главной диагонали: " << max_1 << std::endl;

    double max_2 = a[0][n-1];
    std::cout << "Побочная диагональ: ";
    for(int i = 0; i < n; i++) {
        std::cout << a[i][n - 1 - i] << " ";
        if(a[i][n - 1 - i] > max_2) {
            max_2 = a[i][n - 1 - i];
        }
    }
    std::cout << "\nНаибольший элемент побочной диагонали: " << max_2 << std::endl;
}