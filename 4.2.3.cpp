
#include <iostream>
#include <string>
#include <limits>  
#include <stdexcept> 
using namespace std;

struct Student {
    string name;
    int course;
    double averageGrade;
};

struct Group {
    string groupName;
    int studentCount = 0;
    Student* students = nullptr;

    void init_students() {
        students = new Student[studentCount];
    }

    void resize_students(int newCount) {
        Student* newStudents = new Student[newCount];

        for (int i = 0; i < min(studentCount, newCount); ++i) {
            newStudents[i] = students[i];
        }

        delete[] students;
        students = newStudents;
        studentCount = newCount;
    }

    void printStudent(const Student& student) {
        cout << "Ім'я: " << student.name << endl;
        cout << "Курс: " << student.course << endl;
        cout << "Середній бал: " << student.averageGrade << endl;
        cout << "----------------------" << endl;
    }

    void printAll() {
        for (int i = 0; i < studentCount; ++i) {
            printStudent(students[i]);
        }
    }

    Student* getMaxAverageStudent() {
        if (studentCount == 0) return nullptr;

        Student* maxStudent = &students[0];
        for (int i = 1; i < studentCount; ++i) {
            if (students[i].averageGrade > maxStudent->averageGrade) {
                maxStudent = &students[i];
            }
        }
        return maxStudent;
    }

    Student* getMinCourseStudent() {
        if (studentCount == 0) return nullptr;

        Student* minStudent = &students[0];
        for (int i = 1; i < studentCount; ++i) {
            if (students[i].course < minStudent->course) {
                minStudent = &students[i];
            }
        }
        return minStudent;
    }

    void searchByName(const string& name) {
        bool found = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].name == name) {
                printStudent(students[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "Студента з ім'ям '" << name << "' не знайдено." << endl;
        }
    }

    void sortByCourse() {
        for (int i = 0; i < studentCount - 1; ++i) {
            for (int j = 0; j < studentCount - i - 1; ++j) {
                if (students[j].course > students[j + 1].course) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    void clear() {
        delete[] students;
        students = nullptr;
        studentCount = 0;
    }
};

int main() {
    Group group;
    group.groupName = "ПІ-25";

    int numStudents;
    while (true) {
        cout << "Введіть кількість студентів: ";
        cin >> numStudents;

        if (cin.fail()) {
            cout << "Помилка: Некоректний ввід. Введіть ціле число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (numStudents <= 0) {
            cout << "Помилка: Кількість студентів має бути більше 0." << endl;
        } else {
            group.studentCount = numStudents;
            cin.ignore();
            break;
        }
    }

    try {
        group.init_students();
    } catch (const std::bad_alloc& e) {
        cerr << "Помилка виділення пам'яті: " << e.what() << endl;
        return 1; // Exit with an error code.
    }


    for (int i = 0; i < group.studentCount; ++i) {
        cout << "Введіть дані для студента #" << i + 1 << ":" << endl;
        cout << "Ім'я: ";
        getline(cin, group.students[i].name);

        while (true) {
            cout << "Курс: ";
            cin >> group.students[i].course;

            if (cin.fail()) {
                cout << "Помилка: Некоректний ввід. Введіть ціле число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (group.students[i].course <= 0) {
                cout << "Помилка: Курс має бути більше 0." << endl;
            } else {
                cin.ignore();
                break;
            }
        }

        while (true) {
            cout << "Середній бал: ";
            cin >> group.students[i].averageGrade;

            if (cin.fail()) {
                cout << "Помилка: Некоректний ввід. Введіть число з плаваючою комою." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (group.students[i].averageGrade < 0 || group.students[i].averageGrade > 100) {
                cout << "Помилка: Середній бал має бути в діапазоні від 0 до 100." << endl;
            } else {
                cin.ignore();
                break;
            }
        }
        cout << endl;
    }

    cout << "\nСписок студентів:" << endl;
    group.printAll();

    Student* topStudent = group.getMaxAverageStudent();
    if (topStudent) {
        cout << "\nСтудент з найбільшим середнім балом:" << endl;
        group.printStudent(*topStudent);
    }

    Student* juniorStudent = group.getMinCourseStudent();
    if (juniorStudent) {
        cout << "\nСтудент з найменшим курсом:" << endl;
        group.printStudent(*juniorStudent);
    }

    string searchName;
    cout << "\nВведіть ім'я для пошуку: ";
    getline(cin, searchName);
    group.searchByName(searchName);

    group.sortByCourse();
    cout << "\nСтуденти, відсортовані за курсом:" << endl;
    group.printAll();

    group.clear();

    return 0;
}
