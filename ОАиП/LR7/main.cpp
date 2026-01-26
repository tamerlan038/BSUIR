#include <iostream>
#include <cstring>
#include <cstdio>

struct Student {
    char surname[100];
    int group;
    int physics;
    int math;
    int informatics;
    double average;
};

int studentCount = 0;
int studentCapacity = 10;
Student* students = new Student[studentCapacity];
const char* filename = "students.txt";

void calculateAverage(Student& student) {
    student.average = (student.physics + student.math + student.informatics) / 3.0;
}

void cleanRecords() {
    delete[] students;
    students = new Student[10];
    studentCapacity = 10;
    studentCount = 0;
    std::cout << "База данных очищена. Готово для создания новых записей\n";
}

void addRecord() {
    if (studentCount >= studentCapacity) {
        Student* newStudents = new Student[studentCapacity * 2];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
        studentCapacity *= 2;
    }

    Student student;
    std::cout << "Введите фамилию: ";
    std::cin >> student.surname;
    std::cout << "Введите номер группы: ";
    std::cin >> student.group;
    std::cout << "Введите оценку по физике: ";
    std::cin >> student.physics;
    std::cout << "Введите оценку по математике: ";
    std::cin >> student.math;
    std::cout << "Введите оценку по информатике: ";
    std::cin >> student.informatics;

    calculateAverage(student);

    students[studentCount] = student;
    studentCount++;

    std::cout << "Запись добавлена\n";
}

void viewRecords() {
    if (studentCount == 0) {
        std::cout << "Нет записей для просмотра\n";
        return;
    }

    std::cout << "\nСписок всех студентов:\n";
    std::cout << "-------------------------\n";
    
    for (int i = 0; i < studentCount; i++) {
        std::cout << "Студент #" << (i + 1) << ":\n";
        std::cout << "Фамилия: " << students[i].surname << std::endl;
        std::cout << "Группа: " << students[i].group << std::endl;
        std::cout << "Физика: " << students[i].physics << std::endl;
        std::cout << "Математика: " << students[i].math << std::endl;
        std::cout << "Информатика: " << students[i].informatics << std::endl;
        std::cout << "Средний балл: " << students[i].average << std::endl;
        std::cout << "------------------------\n";
    }
    std::cout << "Всего студентов: " << studentCount << std::endl;
}

void solveIndividualTask() {
    if (studentCount == 0) {
        std::cout << "Нет записей для анализа\n";
        return;
    }

    int count = 0;

    std::cout << "\nСтуденты с оценкой 7 или 8 по физике и 9 или 10 по математике:\n";
    std::cout << "----------------------------------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        bool physicsCondition = (students[i].physics == 7 || students[i].physics == 8);
        bool mathCondition = (students[i].math == 9 || students[i].math == 10);
        
        if (physicsCondition && mathCondition) {
            count++;
            std::cout << "Студент #" << count << ":\n";
            std::cout << "Фамилия: " << students[i].surname << std::endl;
            std::cout << "Группа: " << students[i].group << std::endl;
            std::cout << "Физика: " << students[i].physics << std::endl;
            std::cout << "Математика: " << students[i].math << std::endl;
            std::cout << "Информатика: " << students[i].informatics << std::endl;
            std::cout << "Средний балл: " << students[i].average << std::endl;
            std::cout << "------------------------\n";
        }
    }

    if (count > 0) {
        std::cout << "Найдено студентов: " << count << std::endl;
    } else {
        std::cout << "Студенты с указанными оценками не найдены\n";
    }
}

void deleteRecord() {
    if (studentCount == 0) {
        std::cout << "Нет записей для удаления\n";
        return;
    }

    int recordNumber;
    std::cout << "Введите номер записи для удаления (1-" << studentCount << "): ";
    std::cin >> recordNumber;

    if (recordNumber < 1 || recordNumber > studentCount) {
        std::cout << "Неверный номер записи\n";
        return;
    }

    for (int i = recordNumber - 1; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;
    std::cout << "Запись #" << recordNumber << " удалена\n";
}

void editRecord() {
    if (studentCount == 0) {
        std::cout << "Нет записей для редактирования\n";
        return;
    }

    int recordNumber;
    std::cout << "Введите номер записи для редактирования (1-" << studentCount << "): ";
    std::cin >> recordNumber;

    if (recordNumber < 1 || recordNumber > studentCount) {
        std::cout << "Неверный номер записи\n";
        return;
    }

    Student& student = students[recordNumber - 1];

    std::cout << "Текущие данные записи #" << recordNumber << ":\n";
    std::cout << "Фамилия: " << student.surname << std::endl;
    std::cout << "Группа: " << student.group << std::endl;
    std::cout << "Физика: " << student.physics << std::endl;
    std::cout << "Математика: " << student.math << std::endl;
    std::cout << "Информатика: " << student.informatics << std::endl;

    std::cout << "\nВведите новые данные:\n";
    std::cout << "Введите фамилию: ";
    std::cin >> student.surname;
    std::cout << "Введите номер группы: ";
    std::cin >> student.group;
    std::cout << "Введите оценку по физике: ";
    std::cin >> student.physics;
    std::cout << "Введите оценку по математике: ";
    std::cin >> student.math;
    std::cout << "Введите оценку по информатике: ";
    std::cin >> student.informatics;

    calculateAverage(student);
    std::cout << "Запись отредактирована\n";
}

void sortRecords() {
    if (studentCount == 0) {
        std::cout << "Нет записей для сортировки\n";
        return;
    }

    int sortChoice;
    std::cout << "\nВыберите тип сортировки:\n";
    std::cout << "1. По фамилии (по возрастанию)\n";
    std::cout << "2. По фамилии (по убыванию)\n";
    std::cout << "3. По среднему баллу (по возрастанию)\n";
    std::cout << "4. По среднему баллу (по убыванию)\n";
    std::cout << "Ваш выбор: ";
    std::cin >> sortChoice;

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            bool swap = false;
            
            if (sortChoice == 1) {
                if (strcmp(students[j].surname, students[j+1].surname) > 0) swap = true;
            } else if (sortChoice == 2) {
                if (strcmp(students[j].surname, students[j+1].surname) < 0) swap = true;
            } else if (sortChoice == 3) {
                if (students[j].average > students[j+1].average) swap = true;
            } else if (sortChoice == 4) {
                if (students[j].average < students[j+1].average) swap = true;
            } else {
                std::cout << "Неверный выбор!\n";
                return;
            }
            
            if (swap) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    if (sortChoice == 1) std::cout << "Записи отсортированы по фамилии (по возрастанию)\n";
    else if (sortChoice == 2) std::cout << "Записи отсортированы по фамилии (по убыванию)\n";
    else if (sortChoice == 3) std::cout << "Записи отсортированы по среднему баллу (по возрастанию)\n";
    else if (sortChoice == 4) std::cout << "Записи отсортированы по среднему баллу (по убыванию)\n";
}

void saveToFile() {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        std::cout << "Ошибка открытия файла для записи\n";
        return;
    }
    
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    
    fclose(file);
    std::cout << "Данные сохранены в файл\n";
}

void loadFromFile() {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cout << "Ошибка открытия файла для чтения\n";
        return;
    }
    
    int count;
    fread(&count, sizeof(int), 1, file);
    
    if (count > studentCapacity) {
        delete[] students;
        studentCapacity = count * 2;
        students = new Student[studentCapacity];
    }
    
    studentCount = count;
    fread(students, sizeof(Student), studentCount, file);
    
    fclose(file);
    std::cout << "Данные загружены из файла\n";
}

int main() {
    int choice;
    loadFromFile();
    do {
        std::cout << "\n Меню управления базой данных студентов\n";
        std::cout << "1. Создание базы данных (очистка всех записей)\n";
        std::cout << "2. Просмотр всех записей\n";
        std::cout << "3. Добавление записи\n";
        std::cout << "4. Удаление записи\n";
        std::cout << "5. Редактирование записи\n";
        std::cout << "6. Сортировка записей\n";
        std::cout << "7. Решение индивидуального задания\n";
        std::cout << "8. Сохранить данные в файл\n";
        std::cout << "9. Загрузить данные из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cleanRecords();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                addRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                editRecord();
                break;
            case 6:
                sortRecords();
                break;
            case 7:
                solveIndividualTask();
                break;
            case 8:
                saveToFile();
                break;
            case 9:
                loadFromFile();
                break;
            case 0:
                std::cout << "Выход из программы\n";
                break;
            default:
                std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    delete[] students;
    return 0;
}