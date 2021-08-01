#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int W, K;
  vector<int> W_Scores, K_Scores;

  for (int i = 0; i < 10; i++) {
    cin >> W;
    W_Scores.push_back(W);
  }

  for (int i = 0; i < 10; i++) {
    cin >> K;
    K_Scores.push_back(K);
  }

  sort(W_Scores.begin(), W_Scores.end(), greater<>());
  sort(K_Scores.begin(), K_Scores.end(), greater<>());

  cout << W_Scores[0] + W_Scores[1] + W_Scores[2] << ' '
       << K_Scores[0] + K_Scores[1] + K_Scores[2];

  return 0;
}