#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  vector<int> s(N + 1);
  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + a[i];
  }

  map<int, int> cnt;
  cnt[0] = 1;

  long long result = 0;
  for (int i = 1; i <= N; i++) {
    result += cnt[s[i] - K];
    cnt[s[i]] += 1;
  }

  cout << result;
}