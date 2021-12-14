#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A[4001];
int B[4001];
int C[4001];
int D[4001];

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<int> AB;
  vector<int> CD;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      AB.push_back(A[i] + B[j]);
      CD.push_back(C[i] + D[j]);
    }
  }

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  long long result = 0;
  for (long long i = 0; i < n * n; i++) {
    auto q = equal_range(CD.begin(), CD.end(), -AB[i]);
    result += q.second - q.first;
  }

  cout << result;
}