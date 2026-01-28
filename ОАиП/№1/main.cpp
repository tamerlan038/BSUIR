#include <iostream>
#include <iomanip>

int main(){
    double **a;
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    a = new double *[n];
    for(int i = 0; i < n; i++){
        a[i] = new double [n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << std::setw(5) << a[i][j];
        }
        std::cout << "\n";
    }

    int size = (n*(n + 2))/2;
    double *b = new double[size];
    double sum = 0;
    int count  = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = i; j < n - i; j++){
            sum += a[i][j];
            b[count] = a[i][j];
            count++;
        }
    }

    for(int i = n - 1; i >= n/2; i--){
        for(int j = n - i - 1; j <= i; j++){
            sum += a[i][j];
            b[count] = a[i][j];
            count++;
        }
    }



    for(int i = 0; i < size; i++){
        std::cout << b[i] << " ";
    }
    std::cout << "\n";

    
    double min;
    double max;
    for(int i = 0; i < size; i++){
        min = b[i];
        max = b[i];
        for(int j = 0; j < size; j++ ){
            if(b[j] <= min){
                min = b[j];
            }
            else{
                if(b[j] > max){
                    max = b[j];
                }
            }
        }
    }

    std::cout << "Max: " << max << "\n";
    std::cout << "Min: " << min << "\n";

    std::cout << "\n";

    std::cout << "Sum is: " << sum << "\n";

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}