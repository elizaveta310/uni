#include <iostream>
using namespace std;

void swapByPointer(int *a, int *b) {
    *a = *a + *b; 
    *b = *a - *b;  
    *a = *a - *b; 
}

int main() {
    int x = 5, y = 6;
    cout << "До обміну: x = " << x << ", y = " << y << endl;
    swapByPointer(&x, &y);
    cout << "Після обміну: x = " << x << ", y = " << y << endl;
    return 0;
}
