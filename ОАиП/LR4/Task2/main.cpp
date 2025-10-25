// #include <iostream>
// #include <cstdlib>
// #include <math.h>

// int main(){
//     double arr[20];
//     double x;
//     int n = 0;
//     char yon;
//     int number;
    
//     std::cout << ("Ввести число самому - 1, рандомом - 2\n");
    
//     if(!(std::cin >> number)){
//         std::cout << ("Incorrect data input");
//         return 1;
//     }

    
//     if (number == 1){
//         std::cout << ("Введите число: \n");
        
//         if(!(std::cin >> x)){
//             std::cout << ("Incorrect data input");

//             return 1;
//         }
        
//         arr[n] = x;
//         n++;
        
//         if (n >= 20) {
//             std::cout << "Достигнут максимум (20 чисел)" << std::endl;
//         } else {
//             std::cout << ("Хотите ввести еще число?(y/n)");
            
//             if(!(std::cin >> yon)){
//                 std::cout << ("Incorrect data input");
                
//                 return 1;
//             }
            
//             while(yon == 'y'){
//                 if (n >= 20) {
//                     std::cout << "Достигнут максимум (20 чисел)" << std::endl;
//                     break;
//                 }
                
//                 std::cout << ("Введите число: \n");
                
//                 if(!(std::cin >> x)){
//                     std::cout << ("Incorrect data input");
//                     return 1;
//                 }
                
//                 arr[n] = x;
//                 n++;

//                 if (n >= 20) {
//                     std::cout << "Достигнут максимум (20 чисел)" << std::endl;
//                     break;
//                 } else {
//                     std::cout << ("Хотите ввести еще число?(y/n)");
//                     std::cin >> yon;
//                 }
//             }
//         }
//     }
//     else if (number == 2){
//         std::cout << ("Хотите я введу число?(y/n)");
//         std::cin >> yon;
        
//         while (yon == 'y'){
//             if (n >= 20) {
//                 std::cout << "Достигнут максимум (20 чисел)" << std::endl;
//                 break;
//             }
            
//             int randomNumber = (std::rand() % 201) - 100;
//             std::cout << "Случайное число: " << randomNumber;
//             arr[n] = randomNumber;
//             n++;
            
//             if (n >= 20) {
//                 std::cout << "Достигнут максимум (20 чисел)" << std::endl;
//                 break;
//             } else {
//                 std::cout << ("\nХотите ввести еще число?(y/n)");
//                 std::cin >> yon;
//             }
//         }
//     }

//     int pos = -1;
//     bool hasPositive = false;
//     for (int i = 0; i < n; i++){
        
//         if (arr[i] < 0){
//             pos = i;
//             std::cout <<"Position: "<< i << std::endl;
//             hasPositive = true;
//             break;
//         }
//     }
        
//     if(!hasPositive){
//         std::cout<< "No pos number found\n";

//         return 1;
//     }
    
//     double sum = 0;
//     if(pos%2 == 1){
//         pos += 1;
//     }
//     else{
//         pos += 2;
//     }
//     for (int i = pos; i < n; i += 2){
//         sum += fabs(arr[i]);
//     }

//     std::cout << "Sum: " << sum;
// }



#include <iostream>

int main(){
    int arr[10] = {1,2,3,5,6};
    double sum = 0;
    int n = 0;

    // for(int i = 0; i < 5; i++){
    //     if(arr[i] > 0){
    //         sum += arr[i];
    //         n++;
    //     }
    // } 
    // if(n > 0){
    //     std::cout << sum/n;
    // }
    for(int i = 4; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
}