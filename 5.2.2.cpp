#include <iostream>
using namespace std;

void reverse(int array[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = array[i]; 
        array[i] = array[len - 1 - i]; 
        array[len - 1 - i] = temp;     
    }
}

int main() {
  int array[] = {8, 6, 10, 1};
  int len = 4;
  reverse(array, len);
  cout << array[0] << "," << array[1] << "," << array[2] << "," << array[3];

  return 0;
}
