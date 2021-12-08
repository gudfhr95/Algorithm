#include <iostream>
#include <vector>

using namespace std;

int N;
string s;
int result = -987654321;

int calc(vector<int> nums, vector<char> ops) {
  vector<int> n;
  vector<char> o;

  n.push_back(nums[0]);
  for (int i = 1; i < nums.size(); i++) {
    if (ops[i - 1] == '*') {
      n[n.size() - 1] *= nums[i];
    } else {
      n.push_back(nums[i]);
      o.push_back(ops[i - 1]);
    }
  }

  int res = n[0];
  for (int i = 1; i < n.size(); i++) {
    char op = o[i - 1];
    switch (op) {
      case '+':
        res += n[i];
        break;
      case '-':
        res -= n[i];
        break;
    }
  }

  return res;
}

void go(int index, vector<int> nums, vector<char> ops, bool p) {
  if (index == N) {
    result = max(result, calc(nums, ops));
    return;
  }

  vector<int> newNums(nums);
  vector<char> newOps(ops);

  newNums.push_back(s[index + 1] - '0');
  newOps.push_back(s[index]);

  go(index + 2, newNums, newOps, false);

  if (!p) {
    int n1 = nums.back();
    int n2 = s[index + 1] - '0';

    switch (s[index]) {
      case '+':
        n1 += n2;
        break;
      case '-':
        n1 -= n2;
        break;
      case '*':
        n1 *= n2;
        break;
    }

    nums.pop_back();
    nums.push_back(n1);

    go(index + 2, nums, ops, true);
  }
}

int main() {
  cin >> N >> s;

  vector<int> nums;
  vector<char> ops;

  nums.push_back(s[0] - '0');

  go(1, nums, ops, false);

  cout << result;
}
