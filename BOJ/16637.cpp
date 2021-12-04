#include <iostream>
#include <vector>

using namespace std;

int N;
string s;
int result = -987654321;

void calculate(vector<int> numbers, vector<char> ops, int index, bool b) {
  if (index == N) {
    int sum = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
      switch (ops[i - 1]) {
        case '+':
          sum += numbers[i];
          break;
        case '-':
          sum -= numbers[i];
          break;
        case '*':
          sum *= numbers[i];
          break;
      }
    }
    result = max(result, sum);
    return;
  }

  vector<int> numbers1(numbers);
  vector<char> ops1(ops);

  ops1.push_back(s[index]);
  numbers1.push_back(s[index + 1] - '0');
  calculate(numbers1, ops1, index + 2, false);

  vector<int> numbers2(numbers);
  vector<char> ops2(ops);

  if (!b) {
    int c1 = numbers2.back();
    int c2 = s[index + 1] - '0';
    numbers2.pop_back();
    switch (s[index]) {
      case '+':
        c1 += c2;
        break;
      case '-':
        c1 -= c2;
        break;
      case '*':
        c1 *= c2;
        break;
    }

    numbers2.push_back(c1);
    calculate(numbers2, ops2, index + 2, true);
  }
}

int main() {
  cin >> N >> s;

  vector<int> numbers;
  vector<char> ops;

  numbers.push_back(s[0] - '0');

  calculate(numbers, ops, 1, false);

  cout << result;
}