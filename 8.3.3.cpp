#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

int sum(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main() {
    cout << "Сума двох чисел: " << sum(1, 2) << endl;
    cout << "Сума трьох чисел: " << sum(1, 2, 3) << endl;
    cout << "Сума чотирьох чисел: " << sum(1, 2, 3, 4) << endl; 

    return 0;
}