#include <iostream>

using namespace std;

int N;
int S[20];
bool check[20 * 200000 + 1];

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  for (int i = 1; i < (1 << (N + 1)); i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      if ((i & (1 << j)) != 0) {
        sum += S[j];
      }
    }
    check[sum] = true;
  }

  for (int i = 1; i <= 20 * 200000 + 1; i++) {
    if (!check[i]) {
      cout << i;
      break;
    }
  }
}