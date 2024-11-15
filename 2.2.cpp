#include <iostream>
#include <limits>
#include <climits>

using namespace std;

int main() {
    int N;
    cout << "Введіть кількість чисел: ";
    cin >> N;

    double sum = 0;
    int max = INT_MAX; 
    int min = numeric_limits<int>::max();

    cout << "Введіть " << N << " цілих чисел: ";
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sum += num;
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    double average = sum / N;
    int range = max - min;

    cout << "Середнє: " << average << endl;
    cout << "Максимальне: " << max << endl;
    cout << "Мінімальне: " << min << endl;
    cout << "Діапазон: " << range << endl;

    return 0;
}
