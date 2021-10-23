#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
vector<char> ops;

int calculate() {
  int result = numbers[0];

  for (int i = 0; i < ops.size(); i++) {
    switch (ops[i]) {
      case '+':
        result += numbers[i + 1];
        break;
      case '-':
        result -= numbers[i + 1];
        break;
      case '*':
        result *= numbers[i + 1];
        break;
      case '/':
        result /= numbers[i + 1];
        break;
    }
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

  for (int i = 0; i < plus; i++) {
    ops.push_back('+');
  }

  for (int i = 0; i < minus; i++) {
    ops.push_back('-');
  }

  for (int i = 0; i < mult; i++) {
    ops.push_back('*');
  }

  for (int i = 0; i < div; i++) {
    ops.push_back('/');
  }

  sort(ops.begin(), ops.end());

  int maxResult = -987654321;
  int minResult = 987654321;
  do {
    int temp = calculate();
    maxResult = max(maxResult, temp);
    minResult = min(minResult, temp);
  } while (next_permutation(ops.begin(), ops.end()));

  cout << maxResult << '\n';
  cout << minResult << '\n';
}