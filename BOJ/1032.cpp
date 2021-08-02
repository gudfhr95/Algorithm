#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string name, result = "";
  vector<string> name_list;
  bool flag;

  cin >> N;

  while (N--) {
    cin >> name;
    name_list.push_back(name);
  }

  for (int i = 0; i < name.length(); i++) {
    flag = true;
    for (const auto &elem : name_list) {
      if (elem[i] != name[i]) {
        flag = false;
        break;
      }
    }

    if (flag)
      result += name[i];
    else
      result += '?';
  }

  cout << result << '\n';
}