#include <algorithm>
#include <iostream>

using namespace std;

string convert(int n) {
  string result = "";

  while (n != 0) {
    int remainder = abs(n % 2);
    result += to_string(remainder);
    n = (n - remainder) / -2;
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  if (N == 0)
    cout << N;
  else
    cout << convert(N);
}