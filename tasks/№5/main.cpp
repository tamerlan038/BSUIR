#include <iostream>
#include <cstring>
#include <cstdio>

struct Product {
    char name[20];
    float price;
};

struct Shop {
    char address[50];
    char phone[20];
};

struct Feedback {
    char author[20];
    char text[100];
};

const int MAX = 100;
const char* shopsFilename = "shops.dat";
const char* productsFilename = "products.dat";
const char* feedbacksFilename = "feedbacks.dat";

void addShop(Shop shops[], int& count);
void addProduct(Product products[], int& count);
void addFeedback(Feedback feedbacks[], int& count);
void showAll(Shop shops[], int shopCount, Product products[], int productCount, Feedback feedbacks[], int feedbackCount);
void showProducts(Product products[], int count);
void showShops(Shop shops[], int count);
void showFeedbacks(Feedback feedbacks[], int count);
void editRecords(Shop shops[], int& shopCount, Product products[], int& productCount, Feedback feedbacks[], int& feedbackCount);
void saveShopsToFile(Shop shops[], int count);
void saveProductsToFile(Product products[], int count);
void saveFeedbacksToFile(Feedback feedbacks[], int count);
void loadShopsFromFile(Shop shops[], int& count);
void loadProductsFromFile(Product products[], int& count);
void loadFeedbacksFromFile(Feedback feedbacks[], int& count);
void saveAllToFiles(Shop shops[], int shopCount, Product products[], int productCount, Feedback feedbacks[], int feedbackCount);
void loadAllFromFiles(Shop shops[], int& shopCount, Product products[], int& productCount, Feedback feedbacks[], int& feedbackCount);

int main() {
    Shop shops[MAX];
    Product products[MAX];
    Feedback feedbacks[MAX];
    
    int shopCount = 0;
    int productCount = 0;
    int feedbackCount = 0;
    
    int choice;
    
    loadAllFromFiles(shops, shopCount, products, productCount, feedbacks, feedbackCount);
    
    do {
        std::cout << "\n=== Магазин ===\n";
        std::cout << "1) Добавить магазин\n";
        std::cout << "2) Добавить товар\n";
        std::cout << "3) Добавить отзыв\n";
        std::cout << "4) Показать все записи\n";
        std::cout << "5) Показать товары\n";
        std::cout << "6) Показать магазины\n";
        std::cout << "7) Показать отзывы\n";
        std::cout << "8) Редактировать записи\n";
        std::cout << "9) Сохранить все данные в файлы\n";
        std::cout << "10) Загрузить все данные из файлов\n";
        std::cout << "11) Выход\n";
        std::cout << "Выберите вариант: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1:
                addShop(shops, shopCount);
                break;
            case 2:
                addProduct(products, productCount);
                break;
            case 3:
                addFeedback(feedbacks, feedbackCount);
                break;
            case 4:
                showAll(shops, shopCount, products, productCount, feedbacks, feedbackCount);
                break;
            case 5:
                showProducts(products, productCount);
                break;
            case 6:
                showShops(shops, shopCount);
                break;
            case 7:
                showFeedbacks(feedbacks, feedbackCount);
                break;
            case 8:
                editRecords(shops, shopCount, products, productCount, feedbacks, feedbackCount);
                break;
            case 9:
                saveAllToFiles(shops, shopCount, products, productCount, feedbacks, feedbackCount);
                break;
            case 10:
                loadAllFromFiles(shops, shopCount, products, productCount, feedbacks, feedbackCount);
                break;
            case 11:
                std::cout << "Выход...\n";
                break;
            default:
                std::cout << "Неверный выбор!\n";
        }
    } while (choice != 11);
    
    return 0;
}

void addShop(Shop shops[], int& count) {
    if (count >= MAX) {
        std::cout << "Достигнут максимум записей!\n";
        return;
    }
    
    std::cout << "\n=== Добавление магазина ===\n";
    std::cout << "Адрес: ";
    std::cin.getline(shops[count].address, 50);
    std::cout << "Телефон: ";
    std::cin.getline(shops[count].phone, 20);
    
    count++;
    std::cout << "Магазин добавлен!\n";
}

void addProduct(Product products[], int& count) {
    if (count >= MAX) {
        std::cout << "Достигнут максимум записей\n";
        return;
    }
    
    std::cout << "\n=== Добавление товара ===\n";
    std::cout << "Название: ";
    std::cin.getline(products[count].name, 20);
    std::cout << "Цена: ";
    std::cin >> products[count].price;
    std::cin.ignore();
    
    count++;
    std::cout << "Товар добавлен!\n";
}

void addFeedback(Feedback feedbacks[], int& count) {
    if (count >= MAX) {
        std::cout << "Достигнут максимум записей!\n";
        return;
    }
    
    std::cout << "\n=== Добавление отзыва ===\n";
    std::cout << "Ваше имя: ";
    std::cin.getline(feedbacks[count].author, 20);
    std::cout << "Отзыв: ";
    std::cin.getline(feedbacks[count].text, 100);
    
    count++;
    std::cout << "Отзыв добавлен!\n";
}

void showAll(Shop shops[], int shopCount, Product products[], int productCount, Feedback feedbacks[], int feedbackCount) {
    std::cout << "\n=== ВСЕ ЗАПИСИ ===\n";
    
    std::cout << "\n--- Магазины (" << shopCount << ") ---\n";
    if (shopCount == 0) {
        std::cout << "Нет магазинов\n";
    } else {
        for (int i = 0; i < shopCount; i++) {
            std::cout << i+1 << ". " << shops[i].address << " | " << shops[i].phone << std::endl;
        }
    }
    
    std::cout << "\n--- Товары (" << productCount << ") ---\n";
    if (productCount == 0) {
        std::cout << "Нет товаров\n";
    } else {
        for (int i = 0; i < productCount; i++) {
            std::cout << i+1 << ". " << products[i].name << " | " << products[i].price << std::endl;
        }
    }
    
    std::cout << "\n--- Отзывы (" << feedbackCount << ") ---\n";
    if (feedbackCount == 0) {
        std::cout << "Нет отзывов\n";
    } else {
        for (int i = 0; i < feedbackCount; i++) {
            std::cout << i+1 << ". " << feedbacks[i].author << ": " 
                 << feedbacks[i].text << std::endl;
        }
    }
}

void showProducts(Product products[], int count) {
    std::cout << "\n=== ТОВАРЫ (" << count << ") ===\n";
    if (count == 0) {
        std::cout << "Нет товаров\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        std::cout << i+1 << ". Название: " << products[i].name << std::endl;
        std::cout << "   Цена: " << products[i].price << "\n";
    }
}

void showShops(Shop shops[], int count) {
    std::cout << "\n=== МАГАЗИНЫ (" << count << ") ===\n";
    if (count == 0) {
        std::cout << "Нет магазинов\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        std::cout << i+1 << ". Адрес: " << shops[i].address << std::endl;
        std::cout << "   Телефон: " << shops[i].phone << "\n\n";
    }
}

void showFeedbacks(Feedback feedbacks[], int count) {
    std::cout << "\n=== ОТЗЫВЫ (" << count << ") ===\n";
    if (count == 0) {
        std::cout << "Нет отзывов\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        std::cout << i+1 << ". " << feedbacks[i].author << ":\n";
        std::cout << "   \"" << feedbacks[i].text << "\"\n\n";
    }
}

void editRecords(Shop shops[], int& shopCount, Product products[], int& productCount, Feedback feedbacks[], int& feedbackCount) {
    int typeChoice;
    
    do {
        std::cout << "\n=== РЕДАКТИРОВАНИЕ ЗАПИСЕЙ ===\n";
        std::cout << "1) Редактировать магазины\n";
        std::cout << "2) Редактировать товары\n";
        std::cout << "3) Редактировать отзывы\n";
        std::cout << "0) Вернуться в главное меню\n";
        std::cout << "Выберите тип записей: ";
        std::cin >> typeChoice;
        std::cin.ignore();
        
        if (typeChoice == 0) return;
        
        if (typeChoice < 1 || typeChoice > 3) {
            std::cout << "Неверный выбор!\n";
            continue;
        }
        
        if (typeChoice == 1) {
            if (shopCount == 0) {
                std::cout << "Нет магазинов для редактирования\n";
                continue;
            }
            
            showShops(shops, shopCount);
            int shopNumber;
            std::cout << "Введите номер магазина для редактирования (1-" << shopCount << "): ";
            std::cin >> shopNumber;
            std::cin.ignore();
            
            if (shopNumber < 1 || shopNumber > shopCount) {
                std::cout << "Неверный номер!\n";
                continue;
            }
            
            Shop& shop = shops[shopNumber - 1];
            std::cout << "\nТекущие данные магазина" << shopNumber << ":\n";
            std::cout << "Адрес: " << shop.address << std::endl;
            std::cout << "Телефон: " << shop.phone << std::endl;
            
            std::cout << "\nВведите новые данные:\n";
            std::cout << "Новый адрес: ";
            std::cin.getline(shop.address, 50);
            std::cout << "Новый телефон: ";
            std::cin.getline(shop.phone, 20);
            
            std::cout << "Магазин отредактирован!\n";
        }
        else if (typeChoice == 2) {
            if (productCount == 0) {
                std::cout << "Нет товаров для редактирования\n";
                continue;
            }
            
            showProducts(products, productCount);
            int productNumber;
            std::cout << "Введите номер товара для редактирования (1-" << productCount << "): ";
            std::cin >> productNumber;
            std::cin.ignore();
            
            if (productNumber < 1 || productNumber > productCount) {
                std::cout << "Неверный номер!\n";
                continue;
            }
            
            Product& product = products[productNumber - 1];
            std::cout << "\nТекущие данные товара #" << productNumber << ":\n";
            std::cout << "Название: " << product.name << std::endl;
            std::cout << "Цена: " << product.price << std::endl;
            
            std::cout << "\nВведите новые данные:\n";
            std::cout << "Новое название: ";
            std::cin.getline(product.name, 20);
            std::cout << "Новая цена: ";
            std::cin >> product.price;
            std::cin.ignore();
            
            std::cout << "Товар отредактирован!\n";
        }
        else if (typeChoice == 3) {
            if (feedbackCount == 0) {
                std::cout << "Нет отзывов для редактирования\n";
                continue;
            }
            
            showFeedbacks(feedbacks, feedbackCount);
            int feedbackNumber;
            std::cout << "Введите номер отзыва для редактирования (1-" << feedbackCount << "): ";
            std::cin >> feedbackNumber;
            std::cin.ignore();
            
            if (feedbackNumber < 1 || feedbackNumber > feedbackCount) {
                std::cout << "Неверный номер!\n";
                continue;
            }
            
            Feedback& feedback = feedbacks[feedbackNumber - 1];
            std::cout << "\nТекущие данные отзыва #" << feedbackNumber << ":\n";
            std::cout << "Автор: " << feedback.author << std::endl;
            std::cout << "Текст: " << feedback.text << std::endl;
            
            std::cout << "\nВведите новые данные:\n";
            std::cout << "Новый автор: ";
            std::cin.getline(feedback.author, 20);
            std::cout << "Новый текст: ";
            std::cin.getline(feedback.text, 100);
            
            std::cout << "Отзыв отредактирован!\n";
        }
        
        char continueChoice;
        std::cout << "\nПродолжить редактирование? (y/n): ";
        std::cin >> continueChoice;
        std::cin.ignore();
        
        if (continueChoice != 'y' && continueChoice != 'Y') {
            break;
        }
        
    } while (true);
}

void saveShopsToFile(Shop shops[], int count) {
    FILE* file = fopen(shopsFilename, "wb");
    if (!file) {
        std::cout << "Ошибка открытия файла магазинов для записи\n";
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(shops, sizeof(Shop), count, file);
    
    fclose(file);
    std::cout << "Магазины сохранены в файл\n";
}

void saveProductsToFile(Product products[], int count) {
    FILE* file = fopen(productsFilename, "wb");
    if (!file) {
        std::cout << "Ошибка открытия файла товаров для записи\n";
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(products, sizeof(Product), count, file);
    
    fclose(file);
    std::cout << "Товары сохранены в файл\n";
}

void saveFeedbacksToFile(Feedback feedbacks[], int count) {
    FILE* file = fopen(feedbacksFilename, "wb");
    if (!file) {
        std::cout << "Ошибка открытия файла отзывов для записи\n";
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(feedbacks, sizeof(Feedback), count, file);
    
    fclose(file);
    std::cout << "Отзывы сохранены в файл\n";
}

void loadShopsFromFile(Shop shops[], int& count) {
    FILE* file = fopen(shopsFilename, "rb");
    if (!file) {
        return;
    }
    
    fread(&count, sizeof(int), 1, file);
    fread(shops, sizeof(Shop), count, file);
    
    fclose(file);
    std::cout << "Магазины загружены из файла\n";
}

void loadProductsFromFile(Product products[], int& count) {
    FILE* file = fopen(productsFilename, "rb");
    if (!file) {
        return;
    }
    
    fread(&count, sizeof(int), 1, file);
    fread(products, sizeof(Product), count, file);
    
    fclose(file);
    std::cout << "Товары загружены из файла\n";
}

void loadFeedbacksFromFile(Feedback feedbacks[], int& count) {
    FILE* file = fopen(feedbacksFilename, "rb");
    if (!file) {
        return;
    }
    
    fread(&count, sizeof(int), 1, file);
    fread(feedbacks, sizeof(Feedback), count, file);
    
    fclose(file);
    std::cout << "Отзывы загружены из файла\n";
}

void saveAllToFiles(Shop shops[], int shopCount, Product products[], int productCount, Feedback feedbacks[], int feedbackCount) {
    saveShopsToFile(shops, shopCount);
    saveProductsToFile(products, productCount);
    saveFeedbacksToFile(feedbacks, feedbackCount);
    std::cout << "\nВсе данные сохранены в файлы!\n";
}

void loadAllFromFiles(Shop shops[], int& shopCount, Product products[], int& productCount, Feedback feedbacks[], int& feedbackCount) {
    loadShopsFromFile(shops, shopCount);
    loadProductsFromFile(products, productCount);
    loadFeedbacksFromFile(feedbacks, feedbackCount);
    std::cout << "\nВсе данные загружены из файлов!\n";
}