#include <iostream>
#include <queue>

using namespace std;

void drop(queue<int> &cards) {
  cout << cards.front() << ' ';

  cards.pop();
  cards.push(cards.front());
  cards.pop();
}

int main() {
  int N;
  queue<int> cards;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cards.push(i);
  }

  while (cards.size() > 1) {
    drop(cards);
  }

  cout << cards.front();
}