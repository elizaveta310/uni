#include <iostream>

using namespace std;

int main() {
  while (true) {
    int N;
    cout << "Введіть ціле число: ";
    cin >> N;

    cout << (N >= 0 && N % 5 == 0 ? N / 5 : -1) << endl;
  }

  return 0;
}


#include <iostream>

using namespace std;

int main() {
  while (true) {
    int N;
    cout << "Введіть ціле число: ";
    cin >> N;

    if (N >= 0 && N % 5 == 0) {
      cout << N / 5 << endl;
    } else {
      continue;
    }
  }

  return 0;
}




#include <iostream>

using namespace std;

int main() {
  while (true) {
    int N;
    cout << "Введіть ціле число (введіть -1 для виходу): ";
    cin >> N;

    if (N < 0) {
      cout << "До побачення!" << endl;
      break;
    }

    if (N >= 0 && N % 5 == 0) {
      cout << N / 5 << endl;
    }
  }

  return 0;
}

