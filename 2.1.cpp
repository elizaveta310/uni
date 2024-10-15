#include <iostream>

using namespace std;

int main() {
  int n;

  cout << "Введіть кількість разів: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Hello, World!" << endl;
  }

  return 0;
}



#include <iostream>

using namespace std;

int main() {
  int n;
  int i = 0;

  cout << "Введіть кількість разів: ";
  cin >> n;

  while (i < n) {
    cout << "Hello, World!" << endl;
    i++;
  }

  return 0;
}




#include <iostream>

using namespace std;

int main() {
  int n;
  int i = 0;

  cout << "Введіть кількість разів: ";
  cin >> n;

  do {
    cout << "Hello, World!" << endl;
    i++;
  } while (i < n);

  return 0;
}

