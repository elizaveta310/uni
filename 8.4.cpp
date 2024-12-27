#include <iostream>
#include <cstdlib>  // Для rand(), srand(), RAND_MAX
#include <ctime>    // Для time()
#include <cmath>    // Для sqrt()

using namespace std;

int main() {
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    // Генерація випадкових координат x та y у діапазоні [0, 1]
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;

    // Виведення координат
    cout << "Координати дротика: x = " << x << ", y = " << y << endl;
    
    return 0;
}
