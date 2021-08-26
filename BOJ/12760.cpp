#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int CARDS[101][101] = {
    0,
};
int PLAYERS[101] = {
    0,
};

void getWinner(int round) {
  int highest = -987654321;
  for (int i = 1; i <= N; i++) {
    highest = max(highest, CARDS[i][round]);
  }

  for (int i = 1; i <= N; i++) {
    if (CARDS[i][round] == highest) PLAYERS[i]++;
  }
}

int main() {
  int n;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> n;
      CARDS[i][j] = n;
    }
    sort(CARDS[i], CARDS[i] + M + 1);
  }

  for (int i = 1; i <= M; i++) {
    getWinner(i);
  }

  int highest = -987654321;
  for (int i = 1; i <= N; i++) {
    highest = max(highest, PLAYERS[i]);
  }
  for (int i = 1; i <= N; i++) {
    if (PLAYERS[i] == highest) cout << i << ' ';
  }
}