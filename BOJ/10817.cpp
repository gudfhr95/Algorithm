#include <iostream>

using namespace std;

int main() {
  int sort[3];
  int temp;
  cin >> sort[0] >> sort[1] >> sort[2];

  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      if (sort[i] < sort[j]) {
        temp = sort[i];
        sort[i] = sort[j];
        sort[j] = temp;
      }
    }
  }

  cout << sort[1];
}