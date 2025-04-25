#include <iostream>
#include <string>
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

    cout << "Введіть кількість студентів: ";
    cin >> group.studentCount;
    cin.ignore();

    group.init_students();

    for (int i = 0; i < group.studentCount; ++i) {
        cout << "Введіть дані для студента #" << i + 1 << ":" << endl;
        cout << "Ім'я: ";
        getline(cin, group.students[i].name);

        cout << "Курс: ";
        cin >> group.students[i].course;
        cin.ignore();

        cout << "Середній бал: ";
        cin >> group.students[i].averageGrade;
        cin.ignore();
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
