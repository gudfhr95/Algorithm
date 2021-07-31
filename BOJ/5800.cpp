#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K, N, s, largest_gap, temp_gap;
  vector<int> scores;

  cin >> K;

  for (int i = 1; i <= K; i++) {
    cin >> N;

    scores.clear();
    largest_gap = -987654321;

    for (int j = 0; j < N; j++) {
      cin >> s;
      scores.push_back(s);
    }

    sort(scores.begin(), scores.end(), greater<>());

    for (int j = 0; j < N - 1; j++) {
      temp_gap = scores[j] - scores[j + 1];
      if (temp_gap > largest_gap) largest_gap = temp_gap;
    }

    printf("Class %d\n", i);
    printf("Max %d, Min %d, Largest gap %d\n", scores[0], scores[N - 1],
           largest_gap);
  }
}