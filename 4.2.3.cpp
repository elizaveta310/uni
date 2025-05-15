#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

using namespace std;

struct Student {
    string name;
    int course;
    double averageGrade;
};

struct Group {
    Student* students;
    int size;

    void printAll() {
        for (int i = 0; i < size; ++i) {
            cout << "Студент: " << students[i].name << ", Курс: " << students[i].course 
                 << ", Середній бал: " << students[i].averageGrade << endl;
        }
    }

    Student* getMaxAverageStudent() {
        if (size == 0) return nullptr;
        Student* topStudent = &students[0];
        for (int i = 1; i < size; ++i) {
            if (students[i].averageGrade > topStudent->averageGrade) {
                topStudent = &students[i];
            }
        }
        return topStudent;
    }

    Student* getMinCourseStudent() {
        if (size == 0) return nullptr;
        Student* juniorStudent = &students[0];
        for (int i = 1; i < size; ++i) {
            if (students[i].course < juniorStudent->course) {
                juniorStudent = &students[i];
            }
        }
        return juniorStudent;
    }

    void searchByName(const string& name) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (students[i].name == name) {
                cout << "Знайдено студента: " << students[i].name << ", Курс: " 
                     << students[i].course << ", Середній бал: " 
                     << students[i].averageGrade << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            throw runtime_error("Студента з таким ім'ям не знайдено.");
        }
    }

    void sortByCourse() {
        // Сортування за курсом (можна реалізувати, наприклад, методом бульбашка)
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
    }
};

int main() {
    Group group;
    group.size = 3; // Приклад кількості студентів
    group.students = new Student[group.size];

    for (int i = 0; i < group.size; ++i) {
        cout << "Введіть ім'я студента: ";
        cin >> group.students[i].name;

        // Введення курсу з обробкою винятків
        while (true) {
            cout << "Курс: ";
            cin >> group.students[i].course;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Некоректний ввід. Введіть ціле число для курсу.");
            } else if (group.students[i].course <= 0) {
                throw invalid_argument("Курс має бути більше 0.");
            } else {
                cin.ignore();
                break;
            }
        }

        // Введення середнього балу з обробкою винятків
        while (true) {
            cout << "Середній бал: ";
            cin >> group.students[i].averageGrade;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Некоректний ввід. Введіть число з плаваючою комою для середнього балу.");
            } else if (group.students[i].averageGrade < 0 || group.students[i].averageGrade > 100) {
                throw invalid_argument("Середній бал має бути в діапазоні від 0 до 100.");
            } else {
                cin.ignore();
                break;
            }
        }
        cout << endl;
    }

    cout << "\nСписок студентів:" << endl;
    group.printAll();

    try {
        Student* topStudent = group.getMaxAverageStudent();
                if (topStudent) {
            cout << "\nСтудент з найбільшим середнім балом:" << endl;
            group.printAll(); // Можна замінити на group.printStudent(*topStudent);
        }

        Student* juniorStudent = group.getMinCourseStudent();
        if (juniorStudent) {
            cout << "\nСтудент з найменшим курсом:" << endl;
            group.printAll(); // Можна замінити на group.printStudent(*juniorStudent);
        }

        string searchName;
        cout << "\nВведіть ім'я для пошуку: ";
        getline(cin, searchName);
        
        group.searchByName(searchName);

        group.sortByCourse();
        cout << "\nСтуденти, відсортовані за курсом:" << endl;
        group.printAll();

    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    group.clear();

    return 0;
}
