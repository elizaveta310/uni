#include <iostream>
using namespace std;

int sum(int a, int b) {
  return a + b;
}

double sum(double a, double b) {
  return a + b;
}

int main() {
    int intResult = sum(5, 7); 
    cout << "Сума цілих чисел: " << intResult << endl;
  
    double doubleResult = sum(5.5, 7.5);  
    cout << "Сума подвійних чисел: " << doubleResult << endl;

    return 0;
}
