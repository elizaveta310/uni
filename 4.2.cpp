#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int course;
    double averageGrade;
};

void printStudent(Student* student) {
    cout << "Ім'я: " << student->name << endl;
    cout << "Курс: " << student->course << endl;
    cout << "Середній бал: " << student->averageGrade << endl;
    cout << "----------------------" << endl;
}

int main() {
    int n;

    cout << "Введіть кількість студентів: ";
    cin >> n;
    cin.ignore();

    Student* students = new Student[n];

    if (students == nullptr) {
        cerr << "Помилка виділення пам'яті!" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << "Введіть дані для студента #" << i + 1 << ":" << endl;
        cout << "Ім'я: ";
        getline(cin, students[i].name);

        cout << "Курс: ";
        cin >> students[i].course;
        cin.ignore(); 

        cout << "Середній бал: ";
        cin >> students[i].averageGrade;
        cin.ignore(); 

        cout << endl;
    }

    cout << "Список студентів:" << endl;
    for (int i = 0; i < n; ++i) {
        printStudent(&students[i]);
    }

    Student* maxGradeStudent = &students[0];
    for (int i = 1; i < n; ++i) {
        if (students[i].averageGrade > maxGradeStudent->averageGrade) {
            maxGradeStudent = &students[i];
        }
    }

    cout << "Студент з найбільшим середнім балом:" << endl;
    printStudent(maxGradeStudent);

    Student* minCourseStudent = &students[0];
    for (int i = 1; i < n; ++i) {
        if (students[i].course < minCourseStudent->course) {
            minCourseStudent = &students[i];
        }
    }

    cout << "Студент з найменшим курсом:" << endl;
    printStudent(minCourseStudent);

    string searchName;
    cout << "Введіть ім'я для пошуку: ";
    getline(cin, searchName);

    cout << "Результати пошуку за ім'ям '" << searchName << "':" << endl;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].name == searchName) {
            printStudent(&students[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Студента з ім'ям '" << searchName << "' не знайдено." << endl;
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].course > students[j + 1].course) {
                // Обмін елементів
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Студенти, відсортовані за курсом:" << endl;
    for (int i = 0; i < n; ++i) {
        printStudent(&students[i]);
    }

    delete[] students;
    students = nullptr;

    return 0;
}
