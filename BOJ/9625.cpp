#include <iostream>

using namespace std;

int a[45], b[45];

int main(void) {
  int K;

  a[0] = 1;
  b[1] = 1;

  cin >> K;

  for (int i = 2; i < K + 1; i++) {
    a[i] = b[i - 1];
    b[i] = a[i - 1] + b[i - 1];
  }
  cout << a[K] << " " << b[K];
}
