#include <iostream>
using namespace std;

int main() {
    double myArray[5] = {1.2, 3.4, 5.6, 7.8, 9.0}; 

    cout << "Елементи масиву: ";
    for (int i = 0; i < 5; i++) {
        cout << myArray[i] << " "; 
    }
    cout << endl; 

    return 0;
}
