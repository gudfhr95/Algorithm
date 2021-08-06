#include <iostream>

using namespace std;

int main() {
  int N;
  double price;

  cin >> N;

  while (N--) {
    cin >> price;
    printf("$%.2f\n", price * 0.8);
  }
}