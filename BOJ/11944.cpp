#include <iostream>

using namespace std;

int main() {
  string N, answer = "";
  int M;

  cin >> N >> M;

  for (int i = 0; i < stoi(N); i++) {
    answer += N;
  }

  if (answer.length() > M) answer = answer.substr(0, M);

  cout << answer;
}