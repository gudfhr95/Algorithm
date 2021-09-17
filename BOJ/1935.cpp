#include <iostream>
#include <stack>

using namespace std;

int numbers[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  string s;
  stack<double> op;

  cin >> N >> s;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) {
      op.push(numbers[s[i] - 'A']);
    } else {
      double b = op.top();
      op.pop();
      double a = op.top();
      op.pop();

      double result;
      if (s[i] == '+') {
        result = a + b;
      } else if (s[i] == '-') {
        result = a - b;
      } else if (s[i] == '*') {
        result = a * b;
      } else if (s[i] == '/') {
        result = a / b;
      }

      op.push(result);
    }
  }

  printf("%.2f", op.top());
}