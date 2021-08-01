#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K, answer = 0;
  vector<int> coins;

  cin >> N >> K;

  int temp;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    coins.push_back(temp);
  }

  sort(coins.begin(), coins.end(), greater<>());

  for (int i = 0; i < coins.size(); ++i) {
    answer += K / coins[i];
    K %= coins[i];
  }

  cout << answer;
}