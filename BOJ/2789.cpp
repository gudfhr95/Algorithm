#include <iostream>
#include <vector>

using namespace std;

string CAMBRIDGE = "CAMBRIDGE";

string erase(string s, char delim) {
  string result = "";
  vector<string> result_vector;
  size_t prev = 0, cur;
  string substring;

  cur = s.find(delim);
  while (cur != string::npos) {
    substring = s.substr(prev, cur - prev);
    result_vector.push_back(substring);
    prev = cur + 1;
    cur = s.find(delim, prev);
  }
  substring = s.substr(prev, cur - prev);
  result_vector.push_back(substring);

  for (const auto &elem : result_vector) {
    result += elem;
  }

  return result;
}

int main() {
  string s;

  cin >> s;

  for (int i = 0; i < CAMBRIDGE.length(); i++) {
    s = erase(s, CAMBRIDGE[i]);
  }

  cout << s;
}