#include <iostream>

using namespace std;

int main() {
  int sum = 0;

  for (int i = 1; i <= 100; i++) {
    sum += i;
  }

  cout << "Сума чисел від 1 до 100: " << sum << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main() {
  int number;

  cout << "Введіть число: ";
  cin >> number;

  cout << "Дільники числа " << number << ": ";
  for (int i = 1; i <= number; i++) {
    if (number % i == 0) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}

#include <iostream>

using namespace std;

int main() {
  for (int i = 100; i <= 999; i++) {
    int hundreds = i / 100;
    int tens = (i % 100) / 10;
    int units = i % 10;

    if (hundreds != tens && hundreds != units && tens != units) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}


