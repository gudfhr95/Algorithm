#include <iostream>

using namespace std;

int PIECES[6] = {1, 1, 2, 2, 2, 8};

int main() {
  int n;

  for (int i = 0; i < 6; i++) {
    cin >> n;
    cout << PIECES[i] - n << ' ';
  }
}