#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;

  cin >> N;

  int result[N];

  memset(result, 0, sizeof(result));

  for (int i = 0; i < N; i++) {
    vector<int> cards;
    for (int j = 0; j < 5; j++) {
      cin >> n;
      cards.push_back(n);
    }

    vector<bool> temp(5, false);

    for (int j = 0; j < 3; j++) {
      temp[j] = true;
    }

    do {
      int sum = 0;
      for (int j = 0; j < 5; j++) {
        if (temp[j]) sum += cards[j];
      }
      result[i] = max(result[i], sum % 10);
    } while (prev_permutation(temp.begin(), temp.end()));
  }

  int max_value = -987654321;
  int index = -1;
  for (int i = 0; i < N; i++) {
    if (result[i] >= max_value) {
      max_value = result[i];
      index = i;
    }
  }

  cout << index + 1;
}