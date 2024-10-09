2) #include <iostream>

using namespace std;

int main() {

  double base1, base2, height, area;

  cout << "Введіть довжину першої паралельної сторони: ";

  cin >> base1;

  cout << "Введіть довжину другої паралельної сторони: ";

  cin >> base2;

  cout << "Введіть висоту трапеції: ";

  cin >> height;

  area = 0.5 * (base1 + base2) * height;

  cout << "Площа трапеції: " << area << endl;

  return 0;

}

3) #include <iostream>

using namespace std;

int main() {

  double purchasePrice, profitPercentage, profit;

  cout << "Введіть вартість покypки: ";

  cin >> purchasePrice;

  cout << "Введіть відсоток прибутку: ";

  cin >> profitPercentage;

  profit = purchasePrice * (profitPercentage / 100);

  cout << "Сума прибутку: " << profit << endl;

  return 0;

}
