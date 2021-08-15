#include <iostream>

using namespace std;

string convertToMax(string s) {
  string result = "";

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '5')
      result += '6';
    else
      result += s[i];
  }

  return result;
}

string convertToMin(string s) {
  string result = "";

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '6')
      result += '5';
    else
      result += s[i];
  }

  return result;
}

int main() {
  string A, B;

  cin >> A >> B;

  cout << stoi(convertToMin(A)) + stoi(convertToMin(B));
  cout << ' ';
  cout << stoi(convertToMax(A)) + stoi(convertToMax(B));
}
