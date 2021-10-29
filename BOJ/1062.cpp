#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> words;

int convertToBit(string s) {
  int result = 0;
  for (char c : s) {
    result |= (1 << (c - 'a'));
  }
  return result;
}

int count(int mask) {
  int result = 0;

  for (int word : words) {
    if ((word & ((1 << 26) - 1 - mask)) == 0) {
      result++;
    }
  }

  return result;
}

int read(int index, int k, int mask) {
  if (k < 0) return 0;

  if (index == 26) return count(mask);

  int result = 0;
  int cnt = read(index + 1, k - 1, mask | (1 << index));
  result = max(result, cnt);

  if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' &&
      index != 'i' - 'a' && index != 'c' - 'a') {
    cnt = read(index + 1, k, mask);
    result = max(result, cnt);
  }

  return result;
}

int main() {
  cin >> N >> K;

  if (K < 5) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < N; i++) {
    string word;

    cin >> word;

    words.push_back(convertToBit(word));
  }

  cout << read(0, K, 0);
}