#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int freq[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  stack<int> s;

  cin >> N;

  vector<int> seq(N);
  vector<int> result(N);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
    freq[seq[i]] += 1;
  }

  for (int i = 0; i < N; i++) {
    while (!s.empty() && freq[seq[s.top()]] < freq[seq[i]]) {
      result[s.top()] = seq[i];
      s.pop();
    }
    s.push(i);
  }

  while (!s.empty()) {
    result[s.top()] = -1;
    s.pop();
  }

  for (int i = 0; i < N; i++) {
    cout << result[i] << ' ';
  }
}