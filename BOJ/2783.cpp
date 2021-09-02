#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  float X, Y;
  int N;
  vector<float> prices;

  cin >> X >> Y >> N;

  prices.push_back(X / Y);

  while (N--) {
    cin >> X >> Y;
    prices.push_back(X / Y);
  }

  sort(prices.begin(), prices.end());

  printf("%.2f", prices[0] * 1000);
}