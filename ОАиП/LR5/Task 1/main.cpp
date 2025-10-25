#include <iostream>
#include <iomanip>

int main(){
    double **a;
    int n, m;

    std::cout << "Введите количество строк (n) ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m) ";
    std::cin >> m;

    a = new double*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new double[m];
    }

    std::cout << "Введите через пробел все элементы";

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

    int pos = -1;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] > 0){
                pos = i;
                flag = true;
                std::cout << "Первая из строк, содержащяя хотябы один положительный элемент находится по номером " << i + 1;
                
                break;
            }
        }

        if (flag){
            break;
        }
    } 

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}