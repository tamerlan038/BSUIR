#include <iostream>
#include <cstring>
#include <cstdlib>

int main() {
    int size1, size2, maxsize;

    std::cout << "size1: ";
    std::cin >> size1;
    std::cout << "elements: ";
    char* a = new char[size1 + 1];
    for(int i = 0; i < size1; i++) {
        std::cin >> a[i];
    }
    a[size1] = '\0';


    std::cout << "size2: ";
    std::cin >> size2;
    std::cout << "elements: ";
    char* b = new char[size2 + 1];
    for(int i = 0; i < size2; i++) {
        std::cin >> b[i];
    }
    b[size2] = '\0';

    maxsize = (size1 > size2) ? size1 : size2; 
    char* fin = new char[maxsize + 2];
    int carry = 0;
    int index = maxsize;
    fin[maxsize + 1] = '\0';
    int i = size1 - 1;
    int j = size2 - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (a[i] - '0') : 0;
        int digit2 = (j >= 0) ? (b[j] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        fin[index] = (sum % 10) + '0'; 
        carry = sum / 10;
        i--;
        j--;
        index--;
    }

    if (index == 0) {
        fin[0] = '1';
        std::cout << "Result: " << fin << std::endl;
    } else {
        std::cout << "Result: " << (fin + 1) << std::endl; 
    }

    delete[] a;
    delete[] b;
    delete[] fin;

    return 0;
}