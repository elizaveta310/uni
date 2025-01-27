#include <iostream>
using namespace std;

void swapPointers(int **a, int **b) {
    int* temp = *a; 
    *a = *b;         
    *b = temp;        
}

int main() {
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y; 
    cout << "До обміну: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    swapPointers(&ptr1, &ptr2);
    cout << "Після обміну: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    return 0;
}
