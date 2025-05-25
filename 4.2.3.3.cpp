#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int course;
    double averageGrade;
};

struct Group {
    Student* students = nullptr;
    int size = 0;

    void printAll() const {
        for (int i = 0; i < size; ++i) {
            cout << "Студент: " << students[i].name
                 << ", Курс: " << students[i].course
                 << ", Середній бал: " << students[i].averageGrade << endl;
        }
    }

    Student* getMaxAverageStudent() const {
        if (size == 0) return nullptr;
        Student* top = &students[0];
        for (int i = 1; i < size; ++i) {
            if (students[i].averageGrade > top->averageGrade) {
                top = &students[i];
            }
        }
        return top;
    }

    Student* getMinCourseStudent() const {
        if (size == 0) return nullptr;
        Student* min = &students[0];
        for (int i = 1; i < size; ++i) {
            if (students[i].course < min->course) {
                min = &students[i];
            }
        }
        return min;
    }

    void searchByName(const string& name) const {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (students[i].name == name) {
                cout << "Знайдено: " << students[i].name << ", Курс: "
                     << students[i].course << ", Бал: " << students[i].averageGrade << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            throw runtime_error("Студента з таким ім'ям не знайдено.");
        }
    }

    void sortByCourse() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (students[j].course > students[j + 1].course) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    void clear() {
        delete[] students;
        students = nullptr;
        size = 0;
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename);
        if (!out) {
            throw runtime_error("Помилка відкриття файлу для запису.");
        }
        out << size << endl;
        for (int i = 0; i < size; ++i) {
            out << students[i].name << endl;
            out << students[i].course << endl;
            out << students[i].averageGrade << endl;
        }
        out.close();
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) {
            throw runtime_error("Помилка відкриття файлу для зчитування.");
        }

        clear(); // очистити попередні дані

        in >> size;
        in.ignore(); // пропустити символ нового рядка
        students = new Student[size];

        for (int i = 0; i < size; ++i) {
            getline(in, students[i].name);
            in >> students[i].course;
            in >> students[i].averageGrade;
            in.ignore();
        }

        in.close();
    }

    void inputFromUser() {
        cout << "Скільки студентів ввести? ";
        cin >> size;
        cin.ignore();
        students = new Student[size];

        for (int i = 0; i < size; ++i) {
            cout << "\nСтудент #" << (i + 1) << endl;
            cout << "Ім'я: ";
            getline(cin, students[i].name);

            while (true) {
                cout << "Курс: ";
                cin >> students[i].course;
                if (cin.fail() || students[i].course <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Некоректне значення. Спробуйте ще раз.\n";
                } else {
                    break;
                }
            }

            while (true) {
                cout << "Середній бал: ";
                cin >> students[i].averageGrade;
                if (cin.fail() || students[i].averageGrade < 0 || students[i].averageGrade > 100) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Бал має бути від 0 до 100. Спробуйте ще раз.\n";
                } else {
                    break;
                }
            }

            cin.ignore(); // очистити буфер
        }
    }
};

int main() {
    Group group;
    try {
        int choice;
        do {
            cout << "\nМеню:\n";
            cout << "1. Ввести студентів вручну\n";
            cout << "2. Зчитати студентів з файлу\n";
            cout << "3. Зберегти студентів у файл\n";
            cout << "4. Вивести всіх студентів\n";
            cout << "5. Знайти з найвищим середнім балом\n";
            cout << "6. Знайти студента з найменшим курсом\n";
            cout << "7. Пошук за ім'ям\n";
            cout << "8. Сортувати за курсом\n";
            cout << "0. Вихід\n";
            cout << "Ваш вибір: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    group.clear();
                    group.inputFromUser();
                    break;
                case 2:
                    group.loadFromFile("students.txt");
                    cout << "Зчитано з файлу.\n";
                    break;
                case 3:
                    group.saveToFile("students.txt");
                    cout << "Збережено у файл.\n";
                    break;
                case 4:
                    group.printAll();
                    break;
                case 5: {
                    Student* top = group.getMaxAverageStudent();
                    if (top) {
                        cout << "Найкращий студент: " << top->name << ", Бал: " << top->averageGrade << endl;
                    }
                    break;
                }
                case 6: {
                    Student* min = group.getMinCourseStudent();
                    if (min) {
                        cout << "Наймолодший за курсом: " << min->name << ", Курс: " << min->course << endl;
                    }
                    break;
                }
                case 7: {
                    string name;
                    cout << "Введіть ім'я: ";
                    getline(cin, name);
                    group.searchByName(name);
                    break;
                }
                case 8:
                    group.sortByCourse();
                    cout << "Відсортовано за курсом.\n";
                    break;
                case 0:
                    cout << "Завершення програми.\n";
                    break;
                default:
                    cout << "Невірний вибір.\n";
                    break;
            }
        } while (choice != 0);
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    group.clear();
    return 0;
}
