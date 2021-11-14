#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<int> plus;
  vector<int> minus;
  vector<int> zero;
  for (int i = 0; i < N; i++) {
    int n;

    cin >> n;

    if (n > 0)
      plus.push_back(n);
    else if (n == 0)
      zero.push_back(n);
    else
      minus.push_back(n);
  }

  sort(plus.begin(), plus.end());
  sort(minus.begin(), minus.end(), greater<>());

  int result = 0;
  while (plus.size() > 0) {
    int cur = plus[plus.size() - 1];
    plus.pop_back();

    if (plus.size() == 0) {
      result += cur;
      break;
    }

    if (cur * plus[plus.size() - 1] > cur + plus[plus.size() - 1]) {
      result += cur * plus[plus.size() - 1];
      plus.pop_back();
    } else {
      result += cur;
    }
  }

  while (minus.size() > 0) {
    int cur = minus[minus.size() - 1];
    minus.pop_back();

    if (minus.size() == 0) {
      if (zero.size() == 0) {
        result += cur;
      }
      break;
    }

    result += cur * minus[minus.size() - 1];
    minus.pop_back();
  }

  cout << result;
}