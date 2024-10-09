#include <iostream>

using namespace std;

int main() {
  double num1, num2;
  char operation;

  cout << "Введіть перше число: ";
  cin >> num1;

  cout << "Введіть друге число: ";
  cin >> num2;

  cout << "Введіть операцію (+, -, *, /): ";
  cin >> operation;

  double result;

  switch (operation) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        cout << "Ділення на нуль неможливе!" << endl;
        return 1; // Повертаємо 1, що вказує на помилку
      } else {
        result = num1 / num2;
      }
      break;
    default:
      cout << "Невідома операція" << endl;
      return 1; // Повертаємо 1, що вказує на помилку
  }

  cout << "Результат: " << result << endl;

  return 0;
}

