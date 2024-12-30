#include <iostream>
using namespace std;

const int WIDTH = 3;
const int LENGTH = 4;

void transposeMatrix(int input[][LENGTH], int output[][WIDTH]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            output[j][i] = input[i][j];
        }
    }
}

int main() {
   int input[WIDTH][LENGTH] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int output[LENGTH][WIDTH];

    transposeMatrix(input, output);

    // Виводимо транспоновану матрицю
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
