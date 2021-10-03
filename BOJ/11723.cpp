#include <iostream>

using namespace std;

int add(int set, int x) { return set | (1 << (x - 1)); }

int remove(int set, int x) { return set & ~(1 << (x - 1)); }

void check(int set, int x) {
  if ((set & (1 << (x - 1))) == 0)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}

int toggle(int set, int x) { return set ^ (1 << (x - 1)); }

int all(int set) { return (1 << 21) - 1; }

int empty(int set) { return 0; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int M;

  cin >> M;

  int set = 0;

  string op;
  int x;
  while (M--) {
    cin >> op;
    if (op == "add") {
      cin >> x;
      set = add(set, x);
    } else if (op == "remove") {
      cin >> x;
      set = remove(set, x);
    } else if (op == "check") {
      cin >> x;
      check(set, x);
    } else if (op == "toggle") {
      cin >> x;
      set = toggle(set, x);
    } else if (op == "all") {
      set = all(set);
    } else if (op == "empty") {
      set = empty(set);
    }
  }
}