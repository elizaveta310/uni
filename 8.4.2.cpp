#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <cmath>    
using namespace std;

int main() {
    double calculatePi(int numn) {
    srand(time(0)); 

    int n; 
    int insideCircle = 0; 

    cout << "Введіть кількість кидків дротиків: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        double x = rand() / (double)RAND_MAX;
        double y = rand() / (double)RAND_MAX;

        double distanceSquared = x * x + y * y;

        if (distanceSquared <= 1) {
            insideCircle++; 
        }
    }

    cout << "Кількість дротиків всередині кола: " << insideCircle << endl;
}

 // Обчислення пі за формулою: 4 * (кількість_попадань_всередину / загальна_кількість_кидків)
     double piEstimate = 4.0 * insideCircle / numKydkiv;
    return piEstimate;
}

int main() {
    int numKydkiv = 5000000; 
    
    double piValue = calculatePi(numKydkiv);
    cout << "Приблизне значення числа пі: " << piValue << endl;  

    return 0;
}
