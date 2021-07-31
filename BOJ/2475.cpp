#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n, checksum = 0;

  for (int i = 0; i < 5; i++) {
    cin >> n;
    checksum += pow(n, 2);
  }

  cout << checksum % 10;
}