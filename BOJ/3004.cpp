#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int a = (N / 2) + 1;
  int b = (N / 2) + 1;
  if (N % 2 != 0) a += 1;

  cout << a * b;
}