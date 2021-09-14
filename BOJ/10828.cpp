#include <iostream>

using namespace std;

struct Stack {
  int data[10000];
  int size;

  Stack() { size = 0; }

  void push(int n) { data[size++] = n; }

  int pop() {
    if (size == 0) return -1;

    return data[--size];
  }

  int empty() {
    if (size == 0)
      return 1;
    else
      return 0;
  }

  int top() {
    if (size == 0) return -1;

    return data[size - 1];
  }
};

int main() {
  int N, n;
  string s;

  Stack stack;

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  while (N--) {
    cin >> s;
    if (s == "push") {
      cin >> n;
      stack.push(n);
    } else if (s == "pop") {
      cout << stack.pop() << '\n';
    } else if (s == "size") {
      cout << stack.size << '\n';
    } else if (s == "empty") {
      cout << stack.empty() << '\n';
    } else if (s == "top") {
      cout << stack.top() << '\n';
    }
  }
}