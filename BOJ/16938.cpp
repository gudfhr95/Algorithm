#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L, R, X;
int A[15];
int result = 0;

bool check(vector<bool> problems) {
  int cnt = 0;
  int sum = 0;
  int maxi = 0;
  int mini = 987654321;

  for (int i = 0; i < problems.size(); i++) {
    if (!problems[i]) continue;

    cnt++;
    sum += A[i];
    maxi = max(maxi, A[i]);
    mini = min(mini, A[i]);
  }

  if (sum > R || sum < L) {
    return false;
  }

  if (maxi - mini < X) {
    return false;
  }

  return true;
}

void make(vector<bool> problems) {
  if (problems.size() == N) {
    if (check(problems)) {
      result++;
    }
    return;
  }

  vector<bool> a(problems);
  vector<bool> b(problems);

  a.push_back(true);
  b.push_back(false);

  make(a);
  make(b);
}

int main() {
  cin >> N >> L >> R >> X;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  make({});

  cout << result;
}