#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  string name, status;
  map<string, int, greater<string>> m;

  cin >> n;

  while (n--) {
    cin >> name >> status;

    if (status == "enter")
      m[name]++;
    else
      m[name]--;
  }

  for (const auto &elem : m) {
    if (elem.second == 1) cout << elem.first << '\n';
  }
}
