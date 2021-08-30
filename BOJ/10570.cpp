#include <cstring>
#include <iostream>

using namespace std;

int MESSAGE[1001];

int main() {
  int N, V, S;

  cin >> N;

  while (N--) {
    cin >> V;

    memset(MESSAGE, 0, sizeof(MESSAGE));

    for (int i = 0; i < V; i++) {
      cin >> S;
      MESSAGE[S]++;
    }

    int max = -987654321;
    int index = 0;

    for (int i = 0; i < 1001; i++) {
      if (MESSAGE[i] > max) {
        max = MESSAGE[i];
        index = i;
      }
    }

    cout << index << '\n';
  }
}
