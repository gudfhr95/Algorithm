#include <cstring>
#include <iostream>

using namespace std;

int N;
string S;
int d[1001];

int main() {
  cin >> N >> S;

  memset(d, -1, sizeof(d));

  d[0] = 0;
  for (int i = 0; i < N; i++) {
    if(d[i] == -1) continue;

    char target;
    switch (S[i]) {
      case 'B':
        target = 'O';
        break;
      case 'O':
        target = 'J';
        break;
      case 'J':
        target = 'B';
        break;
    }

    for (int j = i + 1; j < N; j++) {
      if (S[j] == target) {
        int cost = d[i] + ((j - i) * (j - i));

        if (d[j] == -1 || cost < d[j]) {
          d[j] = cost;
        }
      }
    }
  }

  cout << d[N - 1];
}
