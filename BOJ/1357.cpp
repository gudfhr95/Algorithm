#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string A, B, answer;
  int sum;

  cin >> A >> B;

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  sum = stoi(A) + stoi(B);

  answer = to_string(sum);
  reverse(answer.begin(), answer.end());

  cout << stoi(answer);
}