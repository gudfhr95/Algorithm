#include <iostream>

using namespace std;

pair<int, long long> getValue(string s) {
  if (s == "black")
    return {0, 1};
  else if (s == "brown")
    return {1, 10};
  else if (s == "red")
    return {2, 100};
  else if (s == "orange")
    return {3, 1000};
  else if (s == "yellow")
    return {4, 10000};
  else if (s == "green")
    return {5, 100000};
  else if (s == "blue")
    return {6, 1000000};
  else if (s == "violet")
    return {7, 10000000};
  else if (s == "grey")
    return {8, 100000000};
  else if (s == "white")
    return {9, 1000000000};
}

int main() {
  string s;
  long long result = 0;

  cin >> s;
  result += getValue(s).first * 10;

  cin >> s;
  result += getValue(s).first;

  cin >> s;
  result *= getValue(s).second;

  cout << result;
}