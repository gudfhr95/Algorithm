#include <iostream>

using namespace std;

bool checkDeleted(int N, string prev, string cur) {
  if (N % 2 == 0) {
    if (prev == cur)
      return true;
    else
      return false;
  } else {
    for (int i = 0; i < prev.length(); i++) {
      if (prev[i] == '0' && cur[i] == '1')
        continue;
      else if (prev[i] == '1' && cur[i] == '0')
        continue;
      else {
        return false;
      }
    }
    return true;
  }
}

int main() {
  int N;
  string prev, cur;
  bool isDeleted = false;

  cin >> N >> prev >> cur;

  if (checkDeleted(N, prev, cur))
    cout << "Deletion succeeded";
  else
    cout << "Deletion failed";
}