#include <iostream>
using namespace std;

int main() {
    double myArray[5] = {1.2, 3.4, 5.6, 7.8, 9.0};
    double sum = 0; 

    for (int i = 0; i < 5; i++) {
        sum += myArray[i];
    }

    double average = sum / 5; 

    cout << "Середнє арифметичне: " << average << endl;

    return 0;
}
