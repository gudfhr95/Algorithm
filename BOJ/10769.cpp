#include <iostream>

using namespace std;

int count(string s, string delim) {
  int result = 0;
  size_t prev = 0, cur;

  cur = s.find(delim);
  while (cur != string::npos) {
    result++;
    prev = cur + 1;
    cur = s.find(delim, prev);
  }

  return result;
}

int main() {
  string s;

  getline(cin, s);

  int happy = count(s, ":-)");
  int sad = count(s, ":-(");

  if (happy == 0 && sad == 0)
    cout << "none";
  else if (happy > sad)
    cout << "happy";
  else if (happy == sad)
    cout << "unsure";
  else if (happy < sad)
    cout << "sad";
}
