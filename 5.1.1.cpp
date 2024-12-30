#include <iostream>
using namespace std;

int sum(int numbers[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += numbers[i]; и
    }
    return total;
}

int main() {
    int numbers1[] = {1, 2, 3}; 
    int numbers2[] = {4, 5, 6, 7, 8};  
  
    cout << "Сума 3 чисел: " << sum(numbers1, 3) << endl; 
    cout << "Сума 5 чисел: " << sum(numbers2, 5) << endl; 

    return 0;
}
