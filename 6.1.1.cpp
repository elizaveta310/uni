#include <iostream>
using namespace std;

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {  
        length++;           
        str++;              
    }
    return length;         
}

int main() {
    char str[] = "Hello, World!";
    cout << "Length of the string: " << stringLength(str) << endl;
    return 0;
}
