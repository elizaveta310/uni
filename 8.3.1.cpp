#include <iostream>
using namespace std;

// Функція для обчислення суми двох цілих чисел
int sum(int a, int b) {
  return a + b;
}

// Функція для обчислення суми двох подвійних значень
double sum(double a, double b) {
  return a + b;
}

int main() {
  int a = 5, b = 3;
  cout << "Сума двох цілих чисел: " << sum(a, b) << endl;

  double x = 2.5, y = 1.7;
  cout << "Сума двох подвійних значень: " << sum(x, y) << endl;

  return 0;
}
