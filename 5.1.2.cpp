#include <iostream>
using namespace std;

int sumRecursive(int numbers[], int n) {
    if (n == 0) {
        return 0;
    }
    return numbers[n - 1] + sumRecursive(numbers, n - 1);
}

int main() {
    int numbers1[] = {1, 2, 3}; 
    int numbers2[] = {4, 5, 6, 7, 8};  

    cout << "Сума 3 чисел (рекурсія): " << sumRecursive(numbers1, 3) << endl;
    cout << "Сума 5 чисел (рекурсія): " << sumRecursive(numbers2, 5) << endl; 
  
    return 0;
}
