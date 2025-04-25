#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum BodyType {
    SEDAN,
    HATCHBACK,
    SUV,
    TRUCK,
    OTHER
};

struct Car {
    string make;
    string model;
    int year;
    double engineVolume;
    int horsepower;
    BodyType bodyType;

    void displayInfo() {
        cout << "Марка: " << make << endl;
        cout << "Модель: " << model << endl;
        cout << "Рік випуску: " << year << endl;
        cout << "Об'єм двигуна: " << engineVolume << " л" << endl;
        cout << "Кількість кінських сил: " << horsepower << endl;
        cout << "Тип кузова: ";
        switch (bodyType) {
            case SEDAN: cout << "Седан"; break;
            case HATCHBACK: cout << "Хетчбек"; break;
            case SUV: cout << "Позашляховик"; break;
            case TRUCK: cout << "Пікап"; break;
            case OTHER: cout << "Інший"; break;
            default: cout << "Невідомо";
        }
        cout << endl;
    }

    double calculateTax() {
        if (engineVolume <= 0 || horsepower <= 0) {
            cerr << "Помилка: Об'єм двигуна та кількість кінських сил повинні бути додатними." << endl;
            return 0.0;
        }
        return engineVolume * horsepower * 0.05;
    }
};

int safeGetInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Помилка: Неправильний формат вводу. Введіть ціле число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ← виправлено '\n'
    }
    return value;
}

double safeGetDouble(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Помилка: Неправильний формат вводу. Введіть число з плаваючою комою: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ← виправлено '\n'
    }
    return value;
}

int main() {
    Car myCar;

    cout << "Введіть інформацію про автомобіль:" << endl;

    cout << "Марка: ";
    getline(cin >> ws, myCar.make);

    cout << "Модель: ";
    getline(cin >> ws, myCar.model);

    myCar.year = safeGetInt("Рік випуску: ");
    while (myCar.year < 1900 || myCar.year > 2024) {
        cout << "Помилка: Рік випуску повинен бути між 1900 та 2024. Введіть рік випуску: ";
        myCar.year = safeGetInt("");
    }

    myCar.engineVolume = safeGetDouble("Об'єм двигуна (л): ");
    while (myCar.engineVolume <= 0) {
        cout << "Помилка: Об'єм двигуна повинен бути додатним. Введіть об'єм двигуна: ";
        myCar.engineVolume = safeGetDouble("");
    }

    myCar.horsepower = safeGetInt("Кількість кінських сил: ");
    while (myCar.horsepower <= 0) {
        cout << "Помилка: Кількість кінських сил повинна бути додатною. Введіть кількість кінських сил: ";
        myCar.horsepower = safeGetInt("");
    }

    int bodyTypeInput;
    cout << "Виберіть тип кузова (0 - Седан, 1 - Хетчбек, 2 - Позашляховик, 3 - Пікап, 4 - Інший): ";
    cin >> bodyTypeInput;

    if (bodyTypeInput >= 0 && bodyTypeInput <= 4) {
        myCar.bodyType = static_cast<BodyType>(bodyTypeInput);
    } else {
        cout << "Неправильний вибір типу кузова. Встановлено значення за замовчуванням (Седан)." << endl;
        myCar.bodyType = SEDAN;
    }

    cout << "\nІнформація про ваш автомобіль:" << endl; // ← виправлено '\n'
    myCar.displayInfo();

    double tax = myCar.calculateTax();
    cout << "Податок на автомобіль: " << tax << " грн." << endl;

    return 0;
}
