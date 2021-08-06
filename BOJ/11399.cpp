#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, answer = 0;
  vector<int> P;

  cin >> N;

  int temp;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    P.push_back(temp);
  }

  sort(P.begin(), P.end());

  for (int i = 0; i < N; ++i) {
    answer += P[i] * (N - i);
  }

  cout << answer;
}