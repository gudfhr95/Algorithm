#include <iostream>

using namespace std;

struct Queue {
  int begin, end;
  int data[10000];

  Queue() {
    begin = 0;
    end = 0;
  }

  int size() { return end - begin; }

  bool empty() { return (size() == 0) ? 1 : 0; }

  void push(int n) { data[end++] = n; }

  int pop() {
    if (empty()) return -1;

    return data[begin++];
  }

  int front() {
    if (empty()) return -1;

    return data[begin];
  }

  int back() {
    if (empty()) return -1;

    return data[end - 1];
  }
};

int main() {
  int N, n;
  string s;
  Queue q;

  cin >> N;

  while (N--) {
    cin >> s;
    if (s == "push") {
      cin >> n;
      q.push(n);
    } else if (s == "pop") {
      cout << q.pop() << '\n';
    } else if (s == "size") {
      cout << q.size() << '\n';
    } else if (s == "empty") {
      cout << q.empty() << '\n';
    } else if (s == "front") {
      cout << q.front() << '\n';
    } else if (s == "back") {
      cout << q.back() << '\n';
    }
  }
}