#include <iostream>
using namespace std;

int sum(int a, int b) {
  return a + b;
}

double sum(double a, double b) {
  return a + b;
}

int main() {
  int a = 5, b = 7;
  cout << "Сума двох цілих чисел: " << sum(a, b) << endl;

  double x = 5.5, y = 7.7;
  cout << "Сума двох подвійних значень: " << sum(x, y) << endl;

  return 0;
}


int main() {
    int intResult = sum(5, 7); 
    cout << "Сума цілих чисел: " << intResult << endl;

  
    double doubleResult = sum(5.5, 7.5);  
    cout << "Сума подвійних чисел: " << doubleResult << endl;

    return 0;
}
