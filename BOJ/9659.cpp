#include <iostream>

using namespace std;

int main() {
  long long N;

  cin >> N;

  if (N % 4 == 0 || N % 4 == 2)
    cout << "CY";
  else
    cout << "SK";
}