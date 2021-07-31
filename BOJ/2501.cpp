#include <iostream>
#include <vector>

using namespace std;

vector<int> getDivisors(int n) {
  vector<int> result;

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      result.push_back(i);
    }
  }

  return result;
}

int main() {
  int N, K;

  cin >> N >> K;

  vector<int> divisors = getDivisors(N);

  if (divisors.size() < K)
    cout << 0;
  else
    cout << divisors[K - 1];

  return 0;
}