#include <iostream>
#include <vector>

using namespace std;

bool isPalindrom(string s) {
  if (s.length() <= 1) return true;

  if (s[0] != s[s.length() - 1]) return false;

  return isPalindrom(s.substr(1, s.length() - 2));
}

void getPalindrom(vector<string> words) {
  for (int i = 0; i < words.size() - 1; i++) {
    for (int j = i + 1; j < words.size(); j++) {
      if (isPalindrom(words[i] + words[j])) {
        cout << words[i] + words[j] << '\n';
        return;
      }
      if (isPalindrom(words[j] + words[i])) {
        cout << words[j] + words[i] << '\n';
        return;
      }
    }
  }

  cout << "0\n";
  return;
}

int main() {
  int T, k;
  string s;

  cin >> T;

  while (T--) {
    cin >> k;

    vector<string> words;

    for (int i = 0; i < k; i++) {
      cin >> s;
      words.push_back(s);
    }

    getPalindrom(words);
  }
}