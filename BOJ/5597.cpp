#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  map<int, int> students;

  for (int i = 1; i <= 30; i++) {
    students[i] = 1;
  }

  for (int i = 0; i < 28; i++) {
    cin >> n;
    students[n]--;
  }

  for (const auto &elem : students) {
    if (elem.second == 1) {
      cout << elem.first << '\n';
    }
  }
}