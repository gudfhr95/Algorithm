#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, W, H, match;
  double max_length;

  cin >> N >> W >> H;

  max_length = sqrt(pow(W, 2) + pow(H, 2));

  while (N--) {
    cin >> match;

    if (match <= max_length)
      cout << "DA\n";
    else
      cout << "NE\n";
  }
}