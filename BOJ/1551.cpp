#include <iostream>
#include <vector>

using namespace std;

vector<int> split(string s) {
  vector<int> result;
  size_t prev = 0, cur;
  string number;

  cur = s.find(",");
  while (cur != string::npos) {
    number = s.substr(prev, cur - prev);
    result.push_back(stoi(number));
    prev = cur + 1;
    cur = s.find(",", prev);
  }
  number = s.substr(prev, cur - prev);
  result.push_back(stoi(number));

  return result;
}

vector<int> getSequence(vector<int> numbers) {
  vector<int> result;

  for (int i = 0; i < numbers.size() - 1; i++) {
    result.push_back(numbers[i + 1] - numbers[i]);
  }

  return result;
}

int main() {
  int N, K, n;
  string s;

  cin >> N >> K >> s;

  vector<int> numbers = split(s);

  while (K--) {
    numbers = getSequence(numbers);
  }

  for (int i = 0; i < numbers.size() - 1; i++) {
    cout << numbers[i] << ',';
  }
  cout << numbers[numbers.size() - 1];
}