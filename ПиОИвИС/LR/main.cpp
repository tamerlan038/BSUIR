#include <iostream>
#include <cstring>
#include <cstdio>

struct Student {
    char surname[100];
};

struct Speciality {
    char name[100];
    Student* students;
    int studentCount;
    int studentCapacity;
};

struct Faculty {
    char name[100];
    Speciality* specialities;
    int specialityCount;
    int specialityCapacity;
};

struct University {
    char name[100];
    Faculty* faculties;
    int facultyCount;
    int facultyCapacity;
};

University university;
const char* filename = "university.txt";

// Инициализация университета
void initUniversity() {
    std::cout << "Введите название университета: ";
    std::cin.ignore(); // Очищаем буфер
    std::cin.getline(university.name, 100);
    
    university.facultyCapacity = 5;
    university.facultyCount = 0;
    university.faculties = new Faculty[university.facultyCapacity];
    
    std::cout << "Университет '" << university.name << "' создан.\n";
}

// Функции для управления факультетами
void addFaculty() {
    if (university.facultyCount >= university.facultyCapacity) {
        Faculty* newFaculties = new Faculty[university.facultyCapacity * 2];
        for (int i = 0; i < university.facultyCount; i++) {
            newFaculties[i] = university.faculties[i];
        }
        delete[] university.faculties;
        university.faculties = newFaculties;
        university.facultyCapacity *= 2;
    }

    Faculty& faculty = university.faculties[university.facultyCount];
    
    std::cout << "Введите название факультета: ";
    std::cin.ignore();
    std::cin.getline(faculty.name, 100);
    
    faculty.specialityCapacity = 5;
    faculty.specialityCount = 0;
    faculty.specialities = new Speciality[faculty.specialityCapacity];
    
    university.facultyCount++;
    std::cout << "Факультет '" << faculty.name << "' добавлен.\n";
}

void addSpeciality(int facultyIndex) {
    if (facultyIndex < 0 || facultyIndex >= university.facultyCount) {
        std::cout << "Неверный индекс факультета\n";
        return;
    }
    
    Faculty& faculty = university.faculties[facultyIndex];
    
    if (faculty.specialityCount >= faculty.specialityCapacity) {
        Speciality* newSpecialities = new Speciality[faculty.specialityCapacity * 2];
        for (int i = 0; i < faculty.specialityCount; i++) {
            newSpecialities[i] = faculty.specialities[i];
        }
        delete[] faculty.specialities;
        faculty.specialities = newSpecialities;
        faculty.specialityCapacity *= 2;
    }
    
    Speciality& speciality = faculty.specialities[faculty.specialityCount];
    
    std::cout << "Введите название специальности: ";
    std::cin.ignore();
    std::cin.getline(speciality.name, 100);
    
    speciality.studentCapacity = 10;
    speciality.studentCount = 0;
    speciality.students = new Student[speciality.studentCapacity];
    
    faculty.specialityCount++;
    std::cout << "Специальность '" << speciality.name 
              << "' добавлена на факультет '" << faculty.name << "'\n";
}

void addStudent(int facultyIndex, int specialityIndex) {
    if (facultyIndex < 0 || facultyIndex >= university.facultyCount) {
        std::cout << "Неверный индекс факультета\n";
        return;
    }
    
    Faculty& faculty = university.faculties[facultyIndex];
    
    if (specialityIndex < 0 || specialityIndex >= faculty.specialityCount) {
        std::cout << "Неверный индекс специальности\n";
        return;
    }
    
    Speciality& speciality = faculty.specialities[specialityIndex];
    
    if (speciality.studentCount >= speciality.studentCapacity) {
        Student* newStudents = new Student[speciality.studentCapacity * 2];
        for (int i = 0; i < speciality.studentCount; i++) {
            newStudents[i] = speciality.students[i];
        }
        delete[] speciality.students;
        speciality.students = newStudents;
        speciality.studentCapacity *= 2;
    }
    
    Student& student = speciality.students[speciality.studentCount];
    
    std::cout << "Введите фамилию студента: ";
    std::cin.ignore();
    std::cin.getline(student.surname, 100);
    
    speciality.studentCount++;
    
    std::cout << "Студент '" << student.surname << "' добавлен на специальность '" 
              << speciality.name << "' факультета '" << faculty.name << "'\n";
}

// Просмотр всех данных
void viewAllData() {
    std::cout << "\n-------------------------------------------\n";
    std::cout << "УНИВЕРСИТЕТ: " << university.name << std::endl;
    std::cout << "--------------------------------------------\n\n";
    
    if (university.facultyCount == 0) {
        std::cout << "В университете нет факультетов\n";
        return;
    }
    
    for (int i = 0; i < university.facultyCount; i++) {
        Faculty& faculty = university.faculties[i];
        std::cout << "ФАКУЛЬТЕТ #" << (i+1) << ": " << faculty.name << std::endl;
        std::cout << "-------------------------------------------\n";
        
        if (faculty.specialityCount == 0) {
            std::cout << "На факультете нет специальностей\n";
        } else {
            for (int j = 0; j < faculty.specialityCount; j++) {
                Speciality& speciality = faculty.specialities[j];
                std::cout << "  СПЕЦИАЛЬНОСТЬ #" << (j+1) << ": " << speciality.name << "\n";
                
                if (speciality.studentCount == 0) {
                    std::cout << "    Нет студентов\n";
                } else {
                    std::cout << "    СТУДЕНТЫ (" << speciality.studentCount << "):\n";
                    for (int k = 0; k < speciality.studentCount; k++) {
                        Student& student = speciality.students[k];
                        std::cout << "    - " << student.surname << std::endl;
                    }
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "Всего факультетов: " << university.facultyCount << std::endl;
}

// Удаление студента
void deleteStudent() {
    std::cout << "\nУДАЛЕНИЕ СТУДЕНТА\n";
    
    if (university.facultyCount == 0) {
        std::cout << "В университете нет факультетов\n";
        return;
    }
    
    std::cout << "Введите индекс факультета (1-" << university.facultyCount << "): ";
    int facultyIndex;
    std::cin >> facultyIndex;
    facultyIndex--; // Приводим к 0-индексации
    
    if (facultyIndex < 0 || facultyIndex >= university.facultyCount) {
        std::cout << "Неверный индекс факультета\n";
        return;
    }
    
    Faculty& faculty = university.faculties[facultyIndex];
    std::cout << "Факультет: " << faculty.name << std::endl;
    
    if (faculty.specialityCount == 0) {
        std::cout << "На факультете нет специальностей\n";
        return;
    }
    
    std::cout << "Введите индекс специальности (1-" << faculty.specialityCount << "): ";
    int specialityIndex;
    std::cin >> specialityIndex;
    specialityIndex--;
    
    if (specialityIndex < 0 || specialityIndex >= faculty.specialityCount) {
        std::cout << "Неверный индекс специальности\n";
        return;
    }
    
    Speciality& speciality = faculty.specialities[specialityIndex];
    std::cout << "Специальность: " << speciality.name << std::endl;
    
    if (speciality.studentCount == 0) {
        std::cout << "На этой специальности нет студентов\n";
        return;
    }
    
    std::cout << "Введите индекс студента (1-" << speciality.studentCount << "): ";
    int studentIndex;
    std::cin >> studentIndex;
    studentIndex--;
    
    if (studentIndex < 0 || studentIndex >= speciality.studentCount) {
        std::cout << "Неверный индекс студента\n";
        return;
    }
    
    // Удаление студента
    for (int i = studentIndex; i < speciality.studentCount - 1; i++) {
        speciality.students[i] = speciality.students[i + 1];
    }
    speciality.studentCount--;
    
    std::cout << "Студент удален\n";
}

// Редактирование студента
void editStudent() {
    std::cout << "\nРЕДАКТИРОВАНИЕ СТУДЕНТА\n";
    
    if (university.facultyCount == 0) {
        std::cout << "В университете нет факультетов\n";
        return;
    }
    
    std::cout << "Введите индекс факультета (1-" << university.facultyCount << "): ";
    int facultyIndex;
    std::cin >> facultyIndex;
    facultyIndex--;
    
    if (facultyIndex < 0 || facultyIndex >= university.facultyCount) {
        std::cout << "Неверный индекс факультета\n";
        return;
    }
    
    Faculty& faculty = university.faculties[facultyIndex];
    std::cout << "Факультет: " << faculty.name << std::endl;
    
    if (faculty.specialityCount == 0) {
        std::cout << "На факультете нет специальностей\n";
        return;
    }
    
    std::cout << "Введите индекс специальности (1-" << faculty.specialityCount << "): ";
    int specialityIndex;
    std::cin >> specialityIndex;
    specialityIndex--;
    
    if (specialityIndex < 0 || specialityIndex >= faculty.specialityCount) {
        std::cout << "Неверный индекс специальности\n";
        return;
    }
    
    Speciality& speciality = faculty.specialities[specialityIndex];
    std::cout << "Специальность: " << speciality.name << std::endl;
    
    if (speciality.studentCount == 0) {
        std::cout << "На этой специальности нет студентов\n";
        return;
    }
    
    std::cout << "Введите индекс студента (1-" << speciality.studentCount << "): ";
    int studentIndex;
    std::cin >> studentIndex;
    studentIndex--;
    
    if (studentIndex < 0 || studentIndex >= speciality.studentCount) {
        std::cout << "Неверный индекс студента\n";
        return;
    }
    
    Student& student = speciality.students[studentIndex];
    
    std::cout << "\nТекущие данные студента:\n";
    std::cout << "Фамилия: " << student.surname << std::endl;
    
    std::cout << "\nВведите новые данные:\n";
    std::cout << "Введите фамилию: ";
    std::cin.ignore();
    std::cin.getline(student.surname, 100);
    
    std::cout << "Данные студента обновлены\n";
}

// Сортировка студентов по фамилии
void sortStudents(int facultyIndex, int specialityIndex) {
    if (facultyIndex < 0 || facultyIndex >= university.facultyCount) {
        std::cout << "Неверный индекс факультета\n";
        return;
    }
    
    Faculty& faculty = university.faculties[facultyIndex];
    
    if (specialityIndex < 0 || specialityIndex >= faculty.specialityCount) {
        std::cout << "Неверный индекс специальности\n";
        return;
    }
    
    Speciality& speciality = faculty.specialities[specialityIndex];
    
    if (speciality.studentCount < 2) {
        std::cout << "Недостаточно студентов для сортировки\n";
        return;
    }
    
    int sortChoice;
    std::cout << "\nВыберите тип сортировки:\n";
    std::cout << "1. По фамилии (по возрастанию)\n";
    std::cout << "2. По фамилии (по убыванию)\n";
    std::cout << "Ваш выбор: ";
    std::cin >> sortChoice;
    
    for (int i = 0; i < speciality.studentCount - 1; i++) {
        for (int j = 0; j < speciality.studentCount - i - 1; j++) {
            bool swap = false;
            
            if (sortChoice == 1) {
                if (strcmp(speciality.students[j].surname, speciality.students[j+1].surname) > 0) swap = true;
            } else if (sortChoice == 2) {
                if (strcmp(speciality.students[j].surname, speciality.students[j+1].surname) < 0) swap = true;
            } else {
                std::cout << "Неверный выбор!\n";
                return;
            }
            
            if (swap) {
                Student temp = speciality.students[j];
                speciality.students[j] = speciality.students[j+1];
                speciality.students[j+1] = temp;
            }
        }
    }
    
    std::cout << "Студенты отсортированы\n";
}

// Сохранение в файл
void saveToFile() {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        std::cout << "Ошибка открытия файла для записи\n";
        return;
    }
    
    // Сохраняем данные университета
    fwrite(&university, sizeof(University), 1, file);
    
    // Сохраняем факультеты
    for (int i = 0; i < university.facultyCount; i++) {
        Faculty& faculty = university.faculties[i];
        fwrite(&faculty, sizeof(Faculty), 1, file);
        
        // Сохраняем специальности для каждого факультета
        for (int j = 0; j < faculty.specialityCount; j++) {
            Speciality& speciality = faculty.specialities[j];
            fwrite(&speciality, sizeof(Speciality), 1, file);
            
            // Сохраняем студентов для каждой специальности
            fwrite(speciality.students, sizeof(Student), speciality.studentCount, file);
        }
    }
    
    fclose(file);
    std::cout << "Данные сохранены в файл\n";
}

// Загрузка из файла
void loadFromFile() {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        std::cout << "Ошибка открытия файла для чтения или файл не существует\n";
        return;
    }
    
    // Очищаем текущие данные
    // Очищаем всех студентов
    for (int i = 0; i < university.facultyCount; i++) {
        Faculty& faculty = university.faculties[i];
        for (int j = 0; j < faculty.specialityCount; j++) {
            Speciality& speciality = faculty.specialities[j];
            delete[] speciality.students;
        }
        delete[] faculty.specialities;
    }
    
    // Очищаем факультеты
    delete[] university.faculties;
    
    // Загружаем данные университета
    fread(&university, sizeof(University), 1, file);
    
    // Выделяем память для факультетов
    university.faculties = new Faculty[university.facultyCapacity];
    
    // Загружаем факультеты
    for (int i = 0; i < university.facultyCount; i++) {
        Faculty& faculty = university.faculties[i];
        fread(&faculty, sizeof(Faculty), 1, file);
        
        // Выделяем память для специальностей
        faculty.specialities = new Speciality[faculty.specialityCapacity];
        
        // Загружаем специальности для каждого факультета
        for (int j = 0; j < faculty.specialityCount; j++) {
            Speciality& speciality = faculty.specialities[j];
            fread(&speciality, sizeof(Speciality), 1, file);
            
            // Выделяем память для студентов
            speciality.students = new Student[speciality.studentCapacity];
            
            // Загружаем студентов для каждой специальности
            fread(speciality.students, sizeof(Student), speciality.studentCount, file);
        }
    }
    
    fclose(file);
    std::cout << "Данные загружены из файла\n";
}

// Очистка памяти
void cleanup() {
    // Очищаем всех студентов
    for (int i = 0; i < university.facultyCount; i++) {
        Faculty& faculty = university.faculties[i];
        for (int j = 0; j < faculty.specialityCount; j++) {
            Speciality& speciality = faculty.specialities[j];
            delete[] speciality.students;
        }
        delete[] faculty.specialities;
    }
    
    // Очищаем факультеты
    delete[] university.faculties;
}

int main() {
    // Создаем университет БГУИР по умолчанию
    strcpy(university.name, "БГУИР");
    university.facultyCapacity = 5;
    university.facultyCount = 0;
    university.faculties = new Faculty[university.facultyCapacity];
    
    std::cout << "Создан университет: " << university.name << "\n";
    
    int choice;
    do {
        std::cout << "\n-------------------------------------------\n";
        std::cout << "СИСТЕМА УПРАВЛЕНИЯ УНИВЕРСИТЕТОМ '" << university.name << "'\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "1. Добавить факультет\n";
        std::cout << "2. Добавить специальность на факультет\n";
        std::cout << "3. Добавить студента на специальность\n";
        std::cout << "4. Просмотреть все данные\n";
        std::cout << "5. Удалить студента\n";
        std::cout << "6. Редактировать студента\n";
        std::cout << "7. Сортировать студентов на специальности\n";
        std::cout << "8. Сохранить данные в файл\n";
        std::cout << "9. Загрузить данные из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addFaculty();
                break;
            case 2:
                if (university.facultyCount == 0) {
                    std::cout << "Сначала добавьте хотя бы один факультет!\n";
                } else {
                    std::cout << "Введите индекс факультета (1-" << university.facultyCount << "): ";
                    int index;
                    std::cin >> index;
                    addSpeciality(index - 1);
                }
                break;
            case 3:
                if (university.facultyCount == 0) {
                    std::cout << "Сначала добавьте хотя бы один факультет!\n";
                } else {
                    std::cout << "Введите индекс факультета (1-" << university.facultyCount << "): ";
                    int facIndex;
                    std::cin >> facIndex;
                    std::cout << "Введите индекс специальности: ";
                    int specIndex;
                    std::cin >> specIndex;
                    addStudent(facIndex - 1, specIndex - 1);
                }
                break;
            case 4:
                viewAllData();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                editStudent();
                break;
            case 7:
                if (university.facultyCount == 0) {
                    std::cout << "Сначала добавьте хотя бы один факультет!\n";
                } else {
                    std::cout << "Введите индекс факультета (1-" << university.facultyCount << "): ";
                    int facIndex;
                    std::cin >> facIndex;
                    std::cout << "Введите индекс специальности: ";
                    int specIndex;
                    std::cin >> specIndex;
                    sortStudents(facIndex - 1, specIndex - 1);
                }
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

    cleanup();
    return 0;
}