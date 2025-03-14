#include <iostream>
#include <string>
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
            case SEDAN:
                cout << "Седан";
                break;
            case HATCHBACK:
                cout << "Хетчбек";
                break;
            case SUV:
                cout << "Позашляховик";
                break;
            case TRUCK:
                cout << "Пікап";
                break;
            case OTHER:
                cout << "Інший";
                break;
            default:
                cout << "Невідомо";
        }
        cout << endl;
    }


    double calculateTax() {
      
        double tax = engineVolume * horsepower * 0.05;
        return tax;
    }
};

int main() {

    Car myCar;

    myCar.make = "Toyota";
    myCar.model = "Camry";
    myCar.year = 2020;
    myCar.engineVolume = 2.5;
    myCar.horsepower = 203;
    myCar.bodyType = SEDAN;

    cout << "Інформація про мій автомобіль:" << endl;
    myCar.displayInfo();

    double tax = myCar.calculateTax();
    cout << "Податок на автомобіль: " << tax << " грн." << endl;

    return 0;
}
