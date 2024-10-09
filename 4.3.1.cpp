#include <iostream>

using namespace std;

int main() {
    int bal;
    cout << "Введіть ваш бал: ";
    cin >> bal;

    if (bal >= 90 && bal <= 100) {
        cout << "Оцінка: A" << endl;
    } else if (bal >= 82 && bal <= 89) {
        cout << "Оцінка: B" << endl;
    } else if (bal >= 74 && bal <= 81) {
        cout << "Оцінка: C" << endl;
    } else if (bal >= 64 && bal <= 73) {
        cout << "Оцінка: D" << endl;
    } else if (bal >= 60 && bal <= 63) {
        cout << "Оцінка: E" << endl;
    } else if (bal >= 35 && bal <= 59) {
        cout << "Оцінка: FX" << endl;
    } else if (bal >= 1 && bal <= 34) {
        cout << "Оцінка: F" << endl;
    } else {
        cout << "Недійсний бал!" << endl;
    }

    return 0;
}
