#include <iostream>

using namespace std;

int cards[100];
bool selected[100] = {
    false,
};
int N, M;
int nearest;

int blackjack(int count, int sum, bool selected[100]) {
  if (sum > M) {
    return -1;
  }

  if (count == 0) {
    return sum;
  }

  for (int i = 0; i < N; ++i) {
    if (!selected[i]) {
      selected[i] = true;
      nearest = max(nearest, blackjack(count - 1, sum + cards[i], selected));
      selected[i] = false;
    }
  }

  return nearest;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> cards[i];
  }
  cout << blackjack(3, 0, selected) << '\n';
  return 0;
}