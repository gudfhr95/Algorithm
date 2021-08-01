#include <iostream>

using namespace std;

int main() {
  int N;
  int result = 0;

  cin >> N;

  char num[N];

  cin >> num;

  for (int i = 0; i < N; ++i) {
    result += num[i] - '0';
  }

  cout << result << '\n';
  return 0;
}