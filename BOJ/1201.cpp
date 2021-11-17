#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, K;

  cin >> N >> M >> K;

  vector<int> A(N);

  if (M + K - 1 <= N && N <= M * K) {
    for (int i = 0; i < N; i++) {
      A[i] = i + 1;
    }

    vector<int> G;
    G.push_back(0);
    G.push_back(K);

    N -= K;
    M -= 1;

    int gs = M == 0 ? 1 : N / M;
    int r = M == 0 ? 0 : N % M;
    for (int i = 0; i < M; i++) {
      G.push_back(G.back() + gs + (r > 0 ? 1 : 0));
      if (r > 0) {
        r -= 1;
      }
    }

    for (int i = 0; i < G.size() - 1; i++) {
      reverse(A.begin() + G[i], A.begin() + G[i + 1]);
    }

    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << ' ';
    }
  } else {
    cout << -1;
  }
}