#include <iostream>
#include <ctime>   
#include <random>  
#include <limits>
using namespace std;

int main() {
    int n;

    cout << "Введіть розмір масиву (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір масиву має бути додатнім числом." << endl;
        return 1; 
    }

    int* arr = new int[n];

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distrib(0, n - 1); 

    for (int i = 0; i < n; i++) {
        arr[i] = distrib(gen);
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int max_element = std::numeric_limits<int>::min(); 
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    cout << "Максимальний елемент: " << max_element << endl;
   delete[] arr;
    arr = nullptr; 
  
    return 0;
}

    delete[] arr;
    arr = nullptr; 
    return 0;
}
