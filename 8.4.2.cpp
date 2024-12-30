#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <cmath>    
using namespace std;

int main() {
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

    return 0;
}
