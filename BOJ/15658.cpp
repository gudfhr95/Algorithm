#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;

pair<int, int> calc(int index, int cur, int plus, int minus, int mult,
                    int div) {
  if (index == N) return {cur, cur};

  vector<pair<int, int>> res;
  if (plus > 0) {
    res.push_back(
        calc(index + 1, cur + numbers[index], plus - 1, minus, mult, div));
  }
  if (minus > 0) {
    res.push_back(
        calc(index + 1, cur - numbers[index], plus, minus - 1, mult, div));
  }
  if (mult > 0) {
    res.push_back(
        calc(index + 1, cur * numbers[index], plus, minus, mult - 1, div));
  }
  if (div > 0) {
    res.push_back(
        calc(index + 1, cur / numbers[index], plus, minus, mult, div - 1));
  }

  pair<int, int> result = res[0];
  for (const auto p : res) {
    result.first = max(result.first, p.first);
    result.second = min(result.second, p.second);
  }

  return result;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int n;

    cin >> n;

    numbers.push_back(n);
  }

  int plus, minus, mult, div;
  cin >> plus >> minus >> mult >> div;

  pair<int, int> result = calc(1, numbers[0], plus, minus, mult, div);

  cout << result.first << '\n';
  cout << result.second << '\n';
}