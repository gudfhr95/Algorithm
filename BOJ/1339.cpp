#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int alphabet[26];
vector<char> letters;
vector<int> numbers;
vector<string> words;

int convert(string s) {
  int result = 0;

  for (char c : s) {
    result = (result * 10) + alphabet[c - 'A'];
  }

  return result;
}

int calculate() {
  for (int i = 0; i < letters.size(); i++) {
    alphabet[letters[i] - 'A'] = numbers[i];
  }

  int result = 0;

  for (int i = 0; i < words.size(); i++) {
    result += convert(words[i]);
  }

  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string s;

    cin >> s;

    words.push_back(s);

    for (char c : s) {
      letters.push_back(c);
    }
  }

  sort(letters.begin(), letters.end());
  letters.erase(unique(letters.begin(), letters.end()), letters.end());

  int m = letters.size();
  for (int i = 9; i > 9 - m; i--) {
    numbers.push_back(i);
  }

  int result = -987654321;
  do {
    result = max(result, calculate());
  } while (prev_permutation(numbers.begin(), numbers.end()));

  cout << result;
}