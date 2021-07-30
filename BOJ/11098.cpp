#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  int p;
  int key;
  string value;

  cin >> n;

  while (n--) {
    cin >> p;
    map<int, string, greater<int>> m;

    for (int i = 0; i < p; ++i) {
      cin >> key >> value;
      pair<int, string> p = make_pair(key, value);
      m.insert(p);
    }

    cout << m.begin()->second << endl;
  }
}