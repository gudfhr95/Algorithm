#include <iostream>
#include <vector>

using namespace std;

int ANSWERS[10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

bool check_answers(vector<int> answers) {
  for (int i = 0; i < 10; i++) {
    if (answers[i] != ANSWERS[i]) return false;
  }

  return true;
}

int main() {
  int N, answer;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    vector<int> answers;

    for (int j = 0; j < 10; j++) {
      cin >> answer;
      answers.push_back(answer);
    }

    if (check_answers(answers)) {
      cout << i << '\n';
    }
  }
}