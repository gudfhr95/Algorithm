#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<string> getAnagram(string s) {
  set<string> result;

  sort(s.begin(), s.end());

  do {
    result.insert(s);
  } while (next_permutation(s.begin(), s.end()));

  return result;
}

int main() {
  int N;
  string s;

  cin >> N;

  while (N--) {
    cin >> s;

    set<string> anagram = getAnagram(s);

    for (const auto &elem : anagram) {
      cout << elem << '\n';
    }
  }
}