#include <iostream>
#include <vector>

using namespace std;

int N;
int result = 0;

void hit(int index, vector<int> S, vector<int> W) {
  if (index == N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] <= 0) {
        sum++;
      }
    }

    result = max(result, sum);
    return;
  }

  if (S[index] <= 0) {
    return hit(index + 1, S, W);
  }

  vector<int> candidates;
  for (int i = 0; i < N; i++) {
    if (i == index) continue;

    if (S[i] <= 0) continue;

    candidates.push_back(i);
  }

  if (candidates.empty()) {
    return hit(index + 1, S, W);
  }

  for (int candidate : candidates) {
    vector<int> SN = S;
    vector<int> WN = W;

    SN[index] -= W[candidate];
    SN[candidate] -= W[index];

    hit(index + 1, SN, WN);
  }
}

int main() {
  cin >> N;

  vector<int> S(N);
  vector<int> W(N);

  for (int i = 0; i < N; i++) {
    cin >> S[i] >> W[i];
  }

  hit(0, S, W);

  cout << result;
}
