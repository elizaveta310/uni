#include <iostream>
using namespace std;

int main() {
    char *oddOrEven = "Never odd or even";

    char *nthCharPtr = &oddOrEven[5];

    nthCharPtr = oddOrEven + 3;

    cout << *nthCharPtr << endl;

    char **pointerPtr = &nthCharPtr;

    cout << **pointerPtr << endl;

    cout << *nthCharPtr << endl;
    nthCharPtr++;

    cout << nthCharPtr - oddOrEven << endl;

    return 0;
}  
