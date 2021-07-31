#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, sum = 0;
  pair<int, int> max = {-1, -987654321};
  unordered_map<int, int> um;  // 최빈값 계산용

  for (int i = 0; i < 10; i++) {
    cin >> n;
    sum += n;
    um[n]++;
  }

  for (const auto &elem : um) {
    if (elem.second > max.second) {
      max.first = elem.first;
      max.second = elem.second;
    }
  }

  cout << sum / 10 << '\n' << max.first;
}