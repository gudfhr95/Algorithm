#include <iostream>

using namespace std;

struct Deque {
  int begin, end;
  int data[20000];

  Deque() {
    begin = 10000;
    end = 10000;
  }

  int size() { return end - begin; }

  bool empty() { return (size() == 0) ? 1 : 0; }

  void push_front(int n) { data[begin--] = n; }

  void push_back(int n) { data[++end] = n; }

  int pop_front() {
    if (size() == 0) return -1;

    return data[++begin];
  }

  int pop_back() {
    if (size() == 0) return -1;

    return data[end--];
  }

  int front() {
    if (size() == 0) return -1;

    return data[begin + 1];
  }

  int back() {
    if (size() == 0) return -1;

    return data[end];
  }
};

int main() {
  int N, n;
  string s;
  Deque d;

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  while (N--) {
    cin >> s;
    if (s == "push_front") {
      cin >> n;
      d.push_front(n);
    } else if (s == "push_back") {
      cin >> n;
      d.push_back(n);
    } else if (s == "pop_front") {
      cout << d.pop_front() << '\n';
    } else if (s == "pop_back") {
      cout << d.pop_back() << '\n';
    } else if (s == "size") {
      cout << d.size() << '\n';
    } else if (s == "empty") {
      cout << d.empty() << '\n';
    } else if (s == "front") {
      cout << d.front() << '\n';
    } else if (s == "back") {
      cout << d.back() << '\n';
    }
  }
}