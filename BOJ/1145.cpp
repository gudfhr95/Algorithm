#include <iostream>

using namespace std;

int N[5];

bool isMultiple(int n) {
  int count = 0;

  for (int i = 0; i < 5; i++) {
    if (n % N[i] == 0) count++;
  }

  if (count >= 3)
    return true;
  else
    return false;
}

int main() {
  for (int i = 0; i < 5; i++) {
    cin >> N[i];
  }

  int multiple = 1;
  while (true) {
    if (isMultiple(multiple)) {
      cout << multiple;
      break;
    }

    multiple++;
  }
}